//
//  KZLinkLabel.h
//  LinkTest
//
//  Created by joywii on 14/12/8.
//  Copyright (c) 2014年 . All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NSAttributedString+Emotion.h"

// 链接类型
typedef NS_ENUM(NSInteger, KZLinkType)
{
    KZLinkTypeUserHandle,     //用户昵称  eg: @kingzwt
    KZLinkTypeHashTag,        //内容标签  eg: #hello
    KZLinkTypeURL,            //链接地址  eg: http://www.baidu.com
    KZLinkTypePhoneNumber,    //电话号码  eg: 13888888888
    KZLinkTypeCustom,         // 用户自定义 eg: {@"链接" : @"http://www.baidu.com"}
};

// 可用于识别的链接类型
typedef NS_OPTIONS(NSUInteger, KZLinkDetectionTypes)
{
    KZLinkDetectionTypeUserHandle  = (1 << 0),
    KZLinkDetectionTypeHashTag     = (1 << 1),
    KZLinkDetectionTypeURL         = (1 << 2),
    KZLinkDetectionTypePhoneNumber = (1 << 3),
    KZLinkDetectionTypeCustom      = (1 << 4),
    
    KZLinkDetectionTypeNone        = 0,
    KZLinkDetectionTypeAll         = NSUIntegerMax
};

typedef void (^KZLinkHandler)(KZLinkType linkType, NSString *string, NSRange range);

@interface KZLinkLabel : UILabel <NSLayoutManagerDelegate>

@property (nonatomic, assign, getter = isAutomaticLinkDetectionEnabled) BOOL automaticLinkDetectionEnabled;

@property (nonatomic, strong) UIColor *linkColor;

@property (nonatomic, strong) UIColor *linkHighlightColor;

@property (nonatomic, strong) UIColor *linkBackgroundColor;

@property (nonatomic, assign) CGFloat lineSpacing;

@property (nonatomic, assign) KZLinkDetectionTypes linkDetectionTypes;

@property (nonatomic, copy) KZLinkHandler linkTapHandler;

@property (nonatomic, copy) KZLinkHandler linkLongPressHandler;

- (void)addlinkWithLinkDisplayString:(NSString *)displayString linkUrlString:(NSString *)urlString atPostionIndex:(NSUInteger)pos;

@end
