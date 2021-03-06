//
//  LOXWebViewController.h
//  LauncherOSX
//
//  Created by Boris Schneiderman.
//  Copyright (c) 2012-2013 The Readium Foundation.
//
//  The Readium SDK is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#import <Foundation/Foundation.h>

#import <WebKit/WebKit.h>

#import "LOXSpineViewController.h"

#import <WebKit/WebResourceLoadDelegate.h>

@class LOXePubSdkApi;
@class LOXPageNumberTextController;
@class LOXBookmarksController;
@class LOXAppDelegate;
@class LOXPackage;
@class LOXCurrentPagesInfo;
@class LOXBookmark;
@class LOXPreferences;
@class LOXCSSStyle;
@class WebView;
@class PackageResourceServer;

@interface LOXWebViewController : NSObject<LOXSpineViewControllerDelegate> {

@private
    IBOutlet WebView *_webView;
    @private PackageResourceServer *m_resourceServer;
}
- (LOXPackage *) loxPackage;

- (void) clear;

- (void)onOpenPage:(NSString *)currentPaginationInfo;

- (void)onMediaOverlayStatusChanged:(NSString*) status;

- (void)onMediaOverlayTTSSpeak:(NSString*) tts;
- (void)onMediaOverlayTTSStop;

- (bool)isMediaOverlayAvailable;

-(void)setStyles:(NSArray *)styles;

- (void)onReaderInitialized;

- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context;


@property (nonatomic, retain) NSNumber *isZipVsCache;
//@property (assign) IBOutlet NSButton *toggleButtonZipVsCache;
//- (IBAction)onToggleZipVsCache:(id)sender;


@property (assign) IBOutlet NSButton *leftPageButton;
@property (assign) IBOutlet NSButton *rightPageButton;

@property (assign) IBOutlet LOXAppDelegate *appDelegate;

@property (nonatomic, retain) LOXCurrentPagesInfo *currentPagesInfo;


- (IBAction)onLeftPageClick:(id)sender;
- (IBAction)onRightPageClick:(id)sender;

- (void)openSpineItem:(id)idref elementCfi:(NSString *)cfi;

- (void)openSpineItem:(NSString *)idref pageIndex:(int)pageIx;

- (void)openPage:(int)pageIndex;

- (void)openContentUrl:(NSString *)contentRef fromSourceFileUrl:(NSString *)sourceRef;

- (LOXBookmark *)createBookmark;

- (NSString *)getCurrentPageCfi;

- (void)openPackage:(LOXPackage *)package onPage:(LOXBookmark*) bookmark;

-(void)observePreferences:(LOXPreferences *)preferences;

- (void)resetStyles;

- (void)mediaOverlaysOpenContentUrl:(NSString *)contentRef fromSourceFileUrl:(NSString*) sourceRef forward:(double) offset;
- (void)toggleMediaOverlay;
- (void)nextMediaOverlay;
- (void)previousMediaOverlay;
- (void)escapeMediaOverlay;
- (void)ttsEndedMediaOverlay;

@end
