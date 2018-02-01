
//
//  comObjectC
//
//
//  Created by Ma YiCi on 2016-04-28.
//  Copyright 2016年 mafengwoo All rights reserved.
//  这个类用做C++ 调用 ObjectC 类的桥梁
//
#ifndef cocos2dx01_comObjectC_h
#define cocos2dx01_comObjectC_h

#include "cocos2d.h"

class comObjectC : public cocos2d::Ref
{
private:
    static void showVedioAd_dianview();
    static void showVedioAd_waps();
public:
    comObjectC();
    ~comObjectC();
    //显示插屏广告
    static void showPopAd();
    //显示广告BANNER
    static void showBanner();
    //显示视频广告
    static void showVedioAd();
    //手机震动
    static void setVibrate();
    //进行苹果内购
    static void doAppIap(int iChannel, int iMoney, const char* sUdid, const char* sVersion);
    
    //奖励积分、扣减积分、查询积分
    static void doJiangliJifen(int iValue);
    static void doKoujianJifen(int iValue);
    static void doChaxunJifen();
    
    //是否正在内购中
    static bool isPuring();
    //前往官网反馈信息
    static void feedback();
    //前往商店评分
    static void gotoPingfen();
    //前往商店显示我的应用
    static void showMyGame();
    //打开网页
    static void openUrl(const char* sUrl);
    //是否可以联网
    static bool isNetworkOK();
    //保存图片到相册
    static bool savePhotosAlbum(const char* sFileName);
    //进行社交分享
    static bool shareToNetwork(const char* sFileName);
    //获取下载状态
    static bool getDownloadStatus();
    //取消下载
    static void downloadCancel();
    //下载
    static void download(std::string sFileName);
    //提示信息(自动消失的Toast)
    static void showNotice(std::string sNotice);
    //获取下载进度相关信息
    static const char* getProgressInfo();
    
    //进行友盟统计
    static void umengStatistics(const char* sEvenID);
    
    //检查版本跳转更新(主动)
    static void checkVerUpdate();
    //检查更新提示更新(自动)
    static void checkForUpdate();
    
    static std::string formatNumber(int iMoney);
    
    // 获取电池电量，范围0到1.0。－1表示电量未知。
    static float getBatteryLeve();

    //微信授权登录
    static void wxLogin();
    //微信分享(文字)
    static void wxShareTxt(int iScene);
    //微信分享(链接)
    static void wxShareLink(int iScene);
    static CGSize getStringSize(const char *text, const char * pFontName, int nSize);
};

#endif
