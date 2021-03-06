
/*!
 *  @brief      DSAlert-OC
 *
 *  @author     DS-Team
 *  @copyright  Copyright © 2016年 DS-Team. All rights reserved.
 *  @version    V1.1.0
 */

/*!
 *********************************************************************************
 ************************************ 更新说明 ************************************
 *********************************************************************************
 
 最新更新时间：2017-05-08 【倒叙】
 最新Version：【Version：1.1.0】
 更新内容：
 1.1.0.1、优化方法名命名规范
 1.1.0.2、新增键盘内部处理，详见 demo 5
 1.1.0.3、用原生 autoLayout 重构，自定义 alert 的布局再也不是问题了
 1.1.0.4、优化代码结构，修复内在隐藏内存泄漏
 1.1.0.5、新增 DSAlert_OC.h 文件，只需导入 DSAlert_OC.h 一个文件就可以使用 alert 和 actionSheet 了
 1.1.0.6、删除了部分代码和属性，具体见源码 和 demo
 
 */


#import <UIKit/UIKit.h>

/*! 背景高斯模糊枚举 默认：1 */
typedef NS_ENUM(NSInteger, DSAlertBlurEffectStyle) {
    /*! 较亮的白色模糊 */
    DSAlertBlurEffectStyleExtraLight = 1,
    /*! 一般亮的白色模糊 */
    DSAlertBlurEffectStyleLight,
    /*! 深色背景模糊 */
    DSAlertBlurEffectStyleDark
} NS_ENUM_AVAILABLE_IOS(7_0);

/*! 进出场动画枚举 默认：1 */
typedef NS_ENUM(NSUInteger, DSAlertAnimatingStyle) {
    /*! 缩放显示动画 */
    DSAlertAnimatingStyleScale = 1,
    /*! 晃动动画 */
    DSAlertAnimatingStyleShake,
    /*! 天上掉下动画 / 上升动画 */
    DSAlertAnimatingStyleFall,
};

@interface DSAlert : UIView

/*! 背景颜色 默认：半透明*/
@property (nonatomic, strong) UIColor *bgColor;

/*! 是否开启边缘触摸隐藏 alert 默认：NO */
@property (nonatomic, assign) BOOL isTouchEdgeHide;

/*! 背景图片名字 默认：没有图片*/
@property (nonatomic, strong) NSString *bgImageName;

/*! 是否开启进出场动画 默认：NO，如果 YES ，并且同步设置进出场动画枚举为默认值：1 */
@property (nonatomic, assign, getter=isShowAnimate) BOOL showAnimate;

/*! 进出场动画枚举 默认：1 ，并且默认开启动画开关 */
@property (nonatomic, assign) DSAlertAnimatingStyle animatingStyle;

/*! 背景高斯模糊枚举 默认：1 */
@property (nonatomic, assign) DSAlertBlurEffectStyle blurEffectStyle;

/*!
 * 按钮点击事件回调
 */
@property (strong, nonatomic) void (^buttonActionBlock)(NSInteger index);


/*!
 *  创建一个完全自定义的 alertView，注意：【自定义 alert 只适用于竖屏状态！】
 *
 *  @param customView    自定义 View
 *  @param configuration 属性配置：如 bgColor、buttonTitleColor、isTouchEdgeHide...
 */
+ (void)ds_showCustomView:(UIView *)customView
            configuration:(void (^)(DSAlert *tempView)) configuration;

/*!
 *  创建一个类似于系统的alert
 *
 *  @param title         标题：可空
 *  @param message       消息内容：可空
 *  @param image         图片：可空
 *  @param buttonTitles  按钮标题：不可空
 *  @param buttonTitles  按钮标题颜色：可空，默认蓝色
 *  @param configuration 属性配置：如 bgColor、buttonTitleColor、isTouchEdgeHide...
 *  @param action        按钮的点击事件处理
 */
+ (void)ds_showAlertWithTitle:(NSString *)title
                      message:(NSString *)message
                        image:(UIImage *)image
                 buttonTitles:(NSArray *)buttonTitles
            buttonTitlesColor:(NSArray <UIColor *>*)buttonTitlesColor
                configuration:(void (^)(DSAlert *tempView)) configuration
                  actionClick:(void (^)(NSInteger index)) action;

/*!
 *  视图显示
 */
- (void)ds_showAlertView;

/*!
 *  视图消失
 */
- (void)ds_dismissAlertView;


@end
