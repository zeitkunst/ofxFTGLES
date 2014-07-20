

#pragma once

#include "ofMain.h"
#include "FTGL/ftgles.h"

class ofxFTGLESFont {

  public:
	ofxFTGLESFont();
    ~ofxFTGLESFont();
	//the last parameters don't do anything, but are left in so that ofxFTGLESFont
	//can be dropped in in place of ofTrueTypeFont without compiler errors
	bool 		loadFont(string filename, float fontsize = 10, bool _bAntiAliased = false, bool _bFullCharacterSet = false, bool makeContours = false, float simplifyAmnt = 0, int dpi = 72);
    bool 		isLoaded();

    void setTracking(float tracking);
    float getTracking() const;
   
	void 		setSize(int size);
    float       getSpaceSize();
	float 		getLineHeight();
    void		setLineHeight(float newHeight);
	ofRectangle getStringBoundingBox(wstring s, float x, float y);
	ofRectangle getStringBoundingBox(string s, float x, float y);

	void 		drawString(wstring s, float x, float y);
	void 		drawString(string s, float x, float y);
	float 		stringHeight(string c);
	float 		stringWidth(string c);
	
    FTFont*  font;
  protected:
    bool loaded;
    float lineHeight;
    FTPoint trackingPoint;

};

