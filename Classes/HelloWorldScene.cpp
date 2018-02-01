#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "MMLabel.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("MainScene.csb");
    addChild(rootNode);

    std::string sTxt = "女儿Chant在去年9月出世后，小成员令郭富城一家上下变得热闹，尤其令老人家更加开心。去年郭富城自家成立的护肤品和洗发水生意，外界反应好，不排除未来做服装品牌生意，还有意助太太方媛创业。他表示：她对时装向来很有兴趣，如果有时间，希望进修读时装设计。如果有机会，或考虑做有关小朋友元素的生意，我会支持她！方媛在微博透露坐月后患上腰痛，郭富城替太太多谢大家关心，因为当父母后照顾小朋友是辛苦事、不容易，方媛现在有做运动，希望身体回复正常。变身二十四孝爸爸和丈夫，郭富城主动为爱妻解画，力挺她购物有理：有报道指她买了很多鞋，事实只是9对、共18双鞋。这天我也穿着她买给我的限量版狗年鞋，也有送给我妈妈，其实是为家人办年货才买的。（颖颖）";
    MMLabel* labTest = MMLabel::createWithTTF(sTxt.c_str(), "", 30);
    labTest->setPosition(300, 300);
    addChild(labTest);

    auto labInfo = Label::createWithTTF(sTxt, "fzcy_gbk.ttf", 30);
    labInfo->setPosition(300, 500);
    addChild(labInfo);
    
    int  iCount  = labTest->getStringCount();
    int  iMaxWidth = 300;
    std::string sMsg = StringUtils::format("字符串字符数量%d", iCount);
    std::string sLine = "";
    labTest->setMaxWidth(iMaxWidth);
    labTest->splitString();
    int  iTotalWidth = 0;
    for(int i = 0; i < iCount; i++){
        auto letter = labTest->getLetter(i);
        iTotalWidth += letter->getContentSize().width;
        if(iTotalWidth > iMaxWidth){
            CCLOG("长度为：%d, i = %d", iTotalWidth, i);
            iTotalWidth = 0;
        }
    }
    
    labInfo->setString(sMsg);
    return true;
}
