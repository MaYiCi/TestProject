//
//  comObjectC.mm
//  cocos2dx01
//
//  Created by Ma YiCi on 2016-04-28.
//
//

#include "comObjectC.h"
#import <SystemConfiguration/SCNetworkReachability.h>
#import <AudioToolbox/AudioToolbox.h>
#import <netinet/in.h>
//#import <SeaGameSDK/SeaGameSDK.h>

using namespace cocos2d;

comObjectC::comObjectC(){}

comObjectC::~comObjectC(){}

bool comObjectC::isNetworkOK(){
    struct sockaddr_in zeroAddress;
    bzero(&zeroAddress, sizeof(zeroAddress));
    zeroAddress.sin_len = sizeof(zeroAddress);
    zeroAddress.sin_family = AF_INET;
    SCNetworkReachabilityRef defaultRouteReachability = SCNetworkReachabilityCreateWithAddress(NULL, (struct sockaddr *)&zeroAddress);
    SCNetworkReachabilityFlags flags;
    
    BOOL didRetrieveFlags = SCNetworkReachabilityGetFlags(defaultRouteReachability, &flags);
    CFRelease(defaultRouteReachability);
    
    if (!didRetrieveFlags)
    {
        NSLog(@"Error. Could not recover network reachability flags");
        return false;
    }
    
    BOOL isReachable = flags & kSCNetworkFlagsReachable;
    BOOL needsConnection = flags & kSCNetworkFlagsConnectionRequired;
    return (isReachable && !needsConnection) ? true : false;
}

void comObjectC::download(std::string sFileName){
}

/*通过NSNumberFormatter，设置NSNumber输出的格式
 *  常用格式化如下
    NSNumberFormatterNoStyle        123456789
    NSNumberFormatterDecimalStyle   123,456,789
    NSNumberFormatterCurrencyStyle  ￥123,456,789.00
    NSNumberFormatterPercentStyle   -539,222,988%
    NSNumberFormatterScientificStyle    1.23456789E8
    NSNumberFormatterSpellOutStyle  一亿二千三百四十五万六千七百八十九
*/
std::string comObjectC::formatNumber(int iMoney){
    NSNumber *num1 = [NSNumber numberWithInt:iMoney];
    NSString *newAmount = [NSNumberFormatter localizedStringFromNumber:num1 numberStyle:NSNumberFormatterDecimalStyle];
    return newAmount.UTF8String;
}
///////////////// SDK 相关接口//////////////////////////
/*
CGSize comObjectC::getStringSize(const char *text, const char * pFontName, int nSize)
{
    NSString * str = [NSString stringWithUTF8String:text];
    NSString * fntName      = [NSString stringWithUTF8String:pFontName];
    CGSize dim, constrainSize;
    id font = [UIFont fontWithName:fntName size:nSize];
    
    if (font)
    {
        dim = _calculateStringSize(str, font, &constrainSize);
    }
    else
    {
        if (!font)
        {
            font = [UIFont systemFontOfSize:nSize];
        }
        if (font)
        {
            dim = _calculateStringSize(str, font, &constrainSize);
        }
    }
    return CCSizeMake(dim.width, dim.height);
    
}
*/

