#pragma once

#include "ofMain.h"
#include "FTGL/ftgles.h"
#include "ofxFTGLESFont.h"


typedef	FTGL::TextAlignment ofxFTGLESTextAlignment;

#define FTGL_ALIGN_LEFT     FTGL::ALIGN_LEFT
#define FTGL_ALIGN_CENTER   FTGL::ALIGN_CENTER
#define FTGL_ALIGN_RIGHT    FTGL::ALIGN_RIGHT
#define FTGL_ALIGN_JUSTIFY  FTGL::ALIGN_JUSTIFY

class ofxFTGLESSimpleLayout
: public ofxFTGLESFont
{
    public:
        ofxFTGLESSimpleLayout();
        ~ofxFTGLESSimpleLayout();

        void unload();

	    bool loadFont(string filename, float fontsize = 10, bool _bAntiAliased = false, bool _bFullCharacterSet = false, bool makeContours = false, float simplifyAmnt = 0, int dpi = 72);

        ofRectangle getStringBoundingBox(wstring s, float x, float y);
        ofRectangle getStringBoundingBox(string s, float x, float y);
    
        void drawString(wstring s, float x, float y);
        void drawString(string s, float x, float y);

        float       getLineLength() const;
        void        setLineLength(float length);
        float       getLineSpacing() const;
        void		setLineSpacing(float spacing);

        ofxFTGLESTextAlignment getAlignment() const;
        void setAlignment(ofxFTGLTextAlignment alignment);

        FTSimpleLayout* layout;
};

