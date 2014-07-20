#include "ofxFTGLESSimpleLayout.h"

ofxFTGLESSimpleLayout::ofxFTGLESSimpleLayout()
: ofxFTGLESFont()
{
    layout = NULL;
}

ofxFTGLESSimpleLayout::~ofxFTGLESSimpleLayout()
{
//	unload();
}

void ofxFTGLESSimpleLayout::unload()
{
    ofxFTGLESFont::unload();
    
    if (layout != NULL) {
        delete layout;
        layout = NULL;
    }
}


bool ofxFTGLESSimpleLayout::loadFont(string filename, float fontsize, bool _bAntiAliased, bool _bFullCharacterSet, bool makeContours, float simplifyAmnt, int dpi)
{
    if (ofxFTGLESFont::loadFont(filename, fontsize, _bAntiAliased, _bFullCharacterSet, makeContours, simplifyAmnt, dpi)) {
        layout = new FTSimpleLayout();
        layout->SetFont(font);
    
        return true;
    }
    
    return false;
}

float ofxFTGLESSimpleLayout::getLineLength() const
{
	return layout->GetLineLength();
}

void ofxFTGLESSimpleLayout::setLineLength(float length)
{
    layout->SetLineLength(length);
}

float ofxFTGLESSimpleLayout::getLineSpacing() const
{
	return layout->GetLineSpacing();
}

void ofxFTGLESSimpleLayout::setLineSpacing(float spacing)
{
    layout->SetLineSpacing(spacing);
}

ofxFTGLESTextAlignment ofxFTGLESSimpleLayout::getAlignment() const
{
    return layout->GetAlignment();
}

void ofxFTGLESSimpleLayout::setAlignment(ofxFTGLESTextAlignment alignment)
{
    layout->SetAlignment(alignment);
}

ofRectangle ofxFTGLESSimpleLayout::getStringBoundingBox(string s, float x, float y)
{
    if (loaded) {
    	FTBBox bbox = layout->BBox(s.c_str());
	    return ofRectangle(x + bbox.Lower().Xf(), y + bbox.Lower().Yf(), bbox.Upper().Xf(), bbox.Upper().Yf());
    }
	return ofRectangle();
}

ofRectangle ofxFTGLESSimpleLayout::getStringBoundingBox(wstring s, float x, float y)
{
    if (loaded) {
    	FTBBox bbox = layout->BBox((wchar_t*)s.c_str());
	    return ofRectangle(x + bbox.Lower().Xf(), y + bbox.Lower().Yf(), bbox.Upper().Xf(), bbox.Upper().Yf());
    }
	return ofRectangle();
}

void ofxFTGLESSimpleLayout::drawString(string s, float x, float y)
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(1,-1,1);
    layout->Render(s.c_str());
    glPopMatrix();
}

void ofxFTGLESSimpleLayout::drawString(wstring s, float x, float y)
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(1,-1,1);
    layout->Render((wchar_t*)s.c_str());
    glPopMatrix();
}
