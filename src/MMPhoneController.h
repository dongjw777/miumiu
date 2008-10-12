//
//  MMPhoneController.h
//  MiuMiu
//
//  Created by Peter Zion on 12/10/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MMIAX.h"
#import "MMCall.h"

@class MMPhoneController;

@protocol MMPhoneControllerDelegate <NSObject>

@required

-(void) phoneControllerDidBeginCall:(MMPhoneController *)phoneController;
-(void) phoneControllerDidEndCall:(MMPhoneController *)phoneController;

@end

@class MMCodec;
@class MMRingInjector;
@class MMBusyInjector;
@class MMFastBusyInjector;
@class MMAudioController;
@class MMDTMFInjector;
@class MMNullProducer;
@class MMComfortNoiseInjector;

@interface MMPhoneController : NSThread <MMIAXDelegate, MMCallDelegate>
{
@private
	id <MMPhoneControllerDelegate> delegate;
	MMAudioController *audioController;
	MMCodec *encoder, *decoder;
	MMIAX *iax;
	MMCall *call;
	MMRingInjector *ringtoneInjector;
	MMBusyInjector *busyInjector;
	MMFastBusyInjector *fastBusyInjector;
	MMDTMFInjector *dtmfInjector;
	MMNullProducer *nullProducer;
	MMComfortNoiseInjector *comfortNoiseInjector;
}

-(void) beginCallWithNumber:(NSString *)number;
-(void) pressedDTMF:(NSString *)dtmf;
-(void) releasedDTMF:(NSString *)dtmf;
-(void) endCall;

@property ( nonatomic, assign ) id <MMPhoneControllerDelegate> delegate;

@end
