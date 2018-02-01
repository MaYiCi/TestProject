#include "MMLabel.h"

#include <algorithm>

#include "2d/CCFont.h"
#include "2d/CCFontAtlasCache.h"
#include "2d/CCFontAtlas.h"
#include "2d/CCSprite.h"
#include "2d/CCSpriteBatchNode.h"
#include "2d/CCDrawNode.h"
#include "2d/CCCamera.h"
#include "base/ccUTF8.h"
#include "platform/CCFileUtils.h"
#include "renderer/CCRenderer.h"
#include "renderer/ccGLStateCache.h"
#include "base/CCDirector.h"
#include "base/CCEventListenerCustom.h"
#include "base/CCEventDispatcher.h"
#include "base/CCEventCustom.h"
#include "2d/CCFontFNT.h"

bool MMLabel::init(){
    //////////////////////////////
    // 1. super init first
    if ( !Label::init() ){
        return false;
    }
    return true;
}

MMLabel* MMLabel::createWithTTF(const std::string& text, const std::string& font, float fontSize, const Size& dimensions /* = Size::ZERO */, TextHAlignment hAlignment /* = TextHAlignment::LEFT */, TextVAlignment vAlignment /* = TextVAlignment::TOP */)
{
    return (MMLabel*)Label::createWithTTF(text, "fzcy_gbk.ttf", fontSize);
}
void MMLabel::splitString(){
    std::string myutf8Text = "我是一个小小蚂蚁";
    std::u16string utf16String;
    if (StringUtils::UTF8ToUTF16(myutf8Text, utf16String))
    {
        auto character = utf16String[1];
        CCLOG("开始拆分字符串");
        TTFConfig ttfConfig("fzcy_gbk.ttf", 30, GlyphCollection::DYNAMIC);
        FontAtlas *newAtlas = FontAtlasCache::getFontAtlasTTF(&ttfConfig);
        newAtlas->prepareLetterDefinitions(utf16String);
        FontLetterDefinition letterDef;
        if (newAtlas->getLetterDefinitionForChar(character, letterDef) == false)
        {
            CCLOG("LabelTextFormatter error:can't find letter definition in font file for letter: %c", character);
        }else{
            CCLOG("LabelTextFormatter success:can't find letter definition in font file for letter: %c", character);
        }
    }
}

string MMLabel::getShortName(string sName, int iMaxLen){
    int    i = 0, iLen = 0, iTLen = 0, iStrLen = (int)sName.length();
    string sOut = "";
    string sTmp = "";
    for(i = 0; i < iStrLen && i < iMaxLen; i += iLen){
        if(sName[i] < 255 && sName[i] > 0){//扩充的ASCII字符范围为0-255,如是,处理一个字节
            sTmp = sName.substr(i, 1);
            iLen = 1;
            iTLen += 1;
        }else if((sName[i] & 0xe0) == 0xc0){    //2个字节
            sTmp = sName.substr(i, 2);
            iLen = 2;
            iTLen += 2;
        }else if((sName[i] & 0xf0) == 0xe0){    //3个字节（汉字）
            sTmp = sName.substr(i, 3);
            iLen = 3;
            iTLen += 2;
        }else if((sName[i] & 0xf8) == 0xf0){    //4个字节（表情符号）
            sTmp = sName.substr(i, 4);
            iLen = 4;
            iTLen += 2;
        }else{ //其他暂时算5个字节，不考虑了
            sTmp = sName.substr(i, 5);
            iLen = 5;
            iTLen += 2;
        }
        sOut += sTmp;
    }
    if(iTLen <= iMaxLen){
        return sName;
    }else{
        return sOut + "...";
    }
}
int MMLabel::getStringCount(){
    return this->getStringLength();
}
