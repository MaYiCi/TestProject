#ifndef __MMLABEL_SCENE_H__
#define __MMLABEL_SCENE_H__

#include "cocos2d.h"
#include "CCLabel.h"
USING_NS_CC;
using namespace cocos2d::ui;
using namespace std;

class MMLabel : public Label
{
private:
    std::string _myutf8Text;
    int     _iMaxWidth;
    string getShortName(string sName, int iMaxLen);
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    int   getStringCount();
    void  setMaxWidth(int iMaxWidth){_iMaxWidth = iMaxWidth;}
    void  splitString();
    // implement the "static create()" method manually
    CREATE_FUNC(MMLabel);
    static MMLabel* createWithTTF(const std::string& text, const std::string& font, float fontSize,
                                       const Size& dimensions = Size::ZERO, TextHAlignment hAlignment = TextHAlignment::LEFT,
                                       TextVAlignment vAlignment = TextVAlignment::TOP);
};

#endif // __HELLOWORLD_SCENE_H__
