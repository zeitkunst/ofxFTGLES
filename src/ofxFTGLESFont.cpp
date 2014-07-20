#include "ofxFTGLESFont.h"

ofxFTGLESFont::ofxFTGLESFont(){
    loaded = false;
    font = NULL;
}

ofxFTGLESFont::~ofxFTGLESFont(){
	if(font != NULL){
        //delete font;
    }
}

void ofxFTGLESFont::unload()
{
    if (font != NULL) {
        delete font;
        font = NULL;
    }
    
    loaded = false;
}


bool ofxFTGLESFont::loadFont(string filename, float fontsize, bool _bAntiAliased, bool _bFullCharacterSet, bool makeContours, float simplifyAmnt, int dpi){
	fontsize *= 2;
	
    font = new FTTextureFont(ofToDataPath(filename).c_str());
//	lineHeight = fontsize * 1.43f;
  	lineHeight = fontsize;
  
    font->Outset(0.0f, fontsize);

    font->CharMap(ft_encoding_unicode);

    if(font->Error()){
        ofLogError("ofxFTGLESFont") << "Error loading font " << filename;
        delete font;
		return false;
    }    
    
    if(!font->FaceSize(fontsize)){
        ofLogError("ofxFTGLESFont") << "Failed to set font size";
        delete font;
		return false;
    }
    
    loaded = true;
    return true;
}

float ofxFTGLESFont::getSpaceSize(){
	return stringWidth(" ");
}

// TODO
// Pull from ofxFTGL implementation
float ofxFTGLESFont::stringWidth(string c){
    ofRectangle rect = getStringBoundingBox(c, 0,0);
    return rect.width;
}

float ofxFTGLESFont::stringHeight(string c) {
    ofRectangle rect = getStringBoundingBox(c, 0,0);
    return rect.height;
}

bool ofxFTGLESFont::isLoaded(){
    return loaded;
}

void ofxFTGLESFont::setSize(int size){
    if(loaded){
	    font->FaceSize(size);
    }
}

void ofxFTGLESFont::setTracking(float tracking)
{
    trackingPoint.X(tracking);
}

float ofxFTGLESFont::getTracking() const
{
    return trackingPoint.Xf();
}


float ofxFTGLESFont::getLineHeight(){
	return lineHeight;
}

void ofxFTGLESFont::setLineHeight(float newHeight){
    lineHeight = newHeight;
}

ofRectangle ofxFTGLESFont::getStringBoundingBox(string s, float x, float y){
    if(loaded){
    	FTBBox bbox = font->BBox(s.c_str());
	    return ofRectangle(x + bbox.Lower().Xf(), y + bbox.Lower().Yf(), bbox.Upper().Xf(), bbox.Upper().Yf());
    }
	return ofRectangle();
}

ofRectangle ofxFTGLESFont::getStringBoundingBox(wstring s, float x, float y){
    if(loaded){
    	FTBBox bbox = font->BBox((wchar_t*)s.c_str());
	    return ofRectangle(x + bbox.Lower().Xf(), y + bbox.Lower().Yf(), bbox.Upper().Xf(), bbox.Upper().Yf());
    }
	return ofRectangle();
}

void ofxFTGLESFont::drawString(string s, float x, float y){
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(1,-1,1);

    //font->Render(s.c_str());
    font->Render(s.c_str(), -1, FTPoint(), trackingPoint);
    glPopMatrix();
}

void ofxFTGLESFont::drawString(wstring s, float x, float y){
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(1,-1,1);
    //font->Render((wchar_t*)s.c_str());
    font->Render((wchar_t*)s.c_str(), -1, FTPoint(), trackingPoint);
    glPopMatrix();
}
