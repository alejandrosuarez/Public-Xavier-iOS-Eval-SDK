//
//  SCIXavierViewController.h
//
//  Copyright (c) 2014 SimonComputing. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SCIMrzProcessor.h"
#import "SCIImageProcessor.h"

@class SCIMetrics;
@class SCIMrzProcessor;

@protocol SCIXavierClientProtocol <NSObject>

@required
-(void) onRawMrz: (NSString*) rawMrz;
-(void) onParsedXmlFromlMrz: (NSString*) parsedXmFromlMrz;
-(void) onMrzCaptureCompleted;
-(void) onError: (NSString*) errorMessage;

@optional
-(void)setPortraitMode:(BOOL) value;
-(void) onMetrics: (SCIMetrics*) metrics;
-(void) onClose;

@end


@interface SCIXavierViewController : UIViewController <SCIMrzProcessorProtocol, SCIImageProcessorProtocol>


/**
 init
 */
-(SCIXavierViewController *) init;
-(SCIXavierViewController *) init:(BOOL)portraitMode;


/**
 Shutdown the OCR previewing process and close the OCR previewing window
 */
-(void) close;


/**
 * Client application is required to implement SCIXavierClientProtocol
 */
@property (nonatomic, weak) id <SCIXavierClientProtocol> _clientProtocol;

@end
