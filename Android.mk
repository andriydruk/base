LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE		:= libbase
LOCAL_C_INCLUDES	:= $(LOCAL_PATH)/android \
LOCAL_C_INCLUDES	:= $(LOCAL_PATH)/android/config \
					   $(LOCAL_PATH)/Headers \
					   $(LOCAL_PATH)/Source \
					   $(LOCAL_PATH)/../libkqueue/include \
					   $(LOCAL_PATH)/../blocksruntime/BlocksRuntime \

LOCAL_CFLAGS		:= -fno-objc-arc 
LOCAL_SRC_FILES		:= 	Source/callframe.m \
						Source/CXXException.m \
						Source/externs.m \
						Source/GSArray.m \
						Source/GSAttributedString.m \
						Source/GSBlocks.m \
						Source/GSConcreteValue.m \
						Source/GSCountedSet.m \
						Source/GSDictionary.m \
						Source/GSFileHandle.m \
						Source/GSFormat.m \
						Source/GSFTPURLHandle.m \
						Source/GSHTTPAuthentication.m \
						Source/GSICUString.m \
						Source/GSPrivateHash.m \
						Source/GSQuickSort.m \
						Source/GSRunLoopWatcher.m \
						Source/GSSet.m \
						Source/GSShellSort.m \
						Source/GSStream.m \
						Source/GSString.m \
						Source/GSTimSort.m \
						Source/GSValue.m \
						Source/inet_ntop.m \
						Source/inet_pton.m \
						Source/NSAffineTransform.m \
						Source/NSArchiver.m \
						Source/NSArray.m \
						Source/NSAssertionHandler.m \
						Source/NSAttributedString.m \
						Source/NSAutoreleasePool.m \
						Source/NSBundle.m \
						Source/NSCache.m \
						Source/NSCachedURLResponse.m \
						Source/NSCalendar.m \
						Source/NSCalendarDate.m \
						Source/NSCallBacks.m \
						Source/NSCharacterSet.m \
						Source/NSClassDescription.m \
						Source/NSCoder.m \
						Source/NSConcreteHashTable.m \
						Source/NSConcreteMapTable.m \
						Source/NSConcretePointerFunctions.m \
						Source/NSConnection.m \
						Source/NSCopyObject.m \
						Source/NSCountedSet.m \
						Source/NSData.m \
						Source/NSDate.m \
						Source/NSDateFormatter.m \
						Source/NSDebug.m \
						Source/NSDecimal.m \
						Source/NSDecimalNumber.m \
						Source/NSDictionary.m \
						Source/NSDistantObject.m \
						Source/NSDistributedLock.m \
						Source/NSDistributedNotificationCenter.m \
						Source/NSEnumerator.m \
						Source/NSError.m \
						Source/NSException.m \
						Source/NSFileManager.m \
						Source/NSFormatter.m \
						Source/NSGarbageCollector.m \
						Source/NSGeometry.m \
						Source/NSHashTable.m \
						Source/NSHost.m \
						Source/NSHTTPCookie.m \
						Source/NSHTTPCookieStorage.m \
						Source/NSIndexPath.m \
						Source/NSIndexSet.m \
						Source/NSInvocation.m \
						Source/NSInvocationOperation.m \
						Source/NSJSONSerialization.m \
						Source/NSKeyedArchiver.m \
						Source/NSKeyValueMutableArray.m \
						Source/NSKeyValueObserving.m \
						Source/NSLocale.m \
						Source/NSLog.m \
						Source/NSMapTable.m \
						Source/NSMessagePort.m \
						Source/NSMessagePortNameServer.m \
						Source/NSMetadata.m \
						Source/NSMethodSignature.m \
						Source/NSNotification.m \
						Source/NSNotificationQueue.m \
						Source/NSNull.m \
						Source/NSNumber.m \
						Source/NSNumberFormatter.m \
						Source/NSObjCRuntime.m \
						Source/NSObject.m \
						Source/NSObject+NSComparisonMethods.m \
						Source/NSOperation.m \
						Source/NSPage.m \
						Source/NSPathUtilities.m \
						Source/NSPipe.m \
						Source/NSPointerArray.m \
						Source/NSPointerFunctions.m \
						Source/NSPort.m \
						Source/NSPortCoder.m \
						Source/NSPortMessage.m \
						Source/NSPortNameServer.m \
						Source/NSPredicate.m \
						Source/NSProcessInfo.m \
						Source/NSPropertyList.m \
						Source/NSProtocolChecker.m \
						Source/NSProxy.m \
						Source/NSRange.m \
						Source/NSRegularExpression.m \
						Source/NSRunLoop.m \
						Source/NSScanner.m \
						Source/NSSerializer.m \
						Source/NSSet.m \
						Source/NSSocketPort.m \
						Source/NSSocketPortNameServer.m \
						Source/NSSortDescriptor.m \
						Source/NSSpellServer.m \
						Source/NSString.m \
						Source/NSTask.m \
						Source/NSTextCheckingResult.m \
						Source/NSThread.m \
						Source/NSTimer.m \
						Source/NSTimeZone.m \
						Source/NSUnarchiver.m \
						Source/NSUndoManager.m \
						Source/NSURL.m \
						Source/NSURLAuthenticationChallenge.m \
						Source/NSURLCache.m \
						Source/NSURLConnection.m \
						Source/NSURLCredential.m \
						Source/NSURLCredentialStorage.m \
						Source/NSURLDownload.m \
						Source/NSURLHandle.m \
						Source/NSURLProtectionSpace.m \
						Source/NSURLRequest.m \
						Source/NSURLResponse.m \
						Source/NSUserDefaults.m \
						Source/NSUserNotification.m \
						Source/NSUUID.m \
						Source/NSValue.m \
						Source/NSValueTransformer.m \
						Source/NSXMLDocument.m \
						Source/NSXMLDTD.m \
						Source/NSXMLDTDNode.m \
						Source/NSXMLElement.m \
						Source/NSXMLNode.m \
						Source/NSXMLParser.m \
						Source/NSZone.m \
						Source/preface.m \
						Source/Additions/GCArray.m \
						Source/Additions/GCDictionary.m \
						Source/Additions/GCObject.m \
						Source/Additions/GSFunctions.m \
						Source/Additions/GSInsensitiveDictionary.m \
						Source/Additions/GSLock.m \
						Source/Additions/GSObjCRuntime.m \
						Source/Additions/GSTypeEncoding.c \
						Source/Additions/GSXML.m \
						Source/Additions/NSArray+GNUstepBase.m \
						Source/Additions/NSAttributedString+GNUstepBase.m \
						Source/Additions/NSBundle+GNUstepBase.m \
						Source/Additions/NSCalendarDate+GNUstepBase.m \
						Source/Additions/NSData+GNUstepBase.m \
						Source/Additions/NSDebug+GNUstepBase.m \
						Source/Additions/NSError+GNUstepBase.m \
						Source/Additions/NSFileHandle+GNUstepBase.m \
						Source/Additions/NSHashTable+GNUstepBase.m \
						Source/Additions/NSLock+GNUstepBase.m \
						Source/Additions/NSMutableString+GNUstepBase.m \
						Source/Additions/NSNumber+GNUstepBase.m \
						Source/Additions/NSProcessInfo+GNUstepBase.m \
						Source/Additions/NSPropertyList+GNUstepBase.m \
						Source/Additions/NSString+GNUstepBase.m \
						Source/Additions/NSTask+GNUstepBase.m \
						Source/Additions/NSThread+GNUstepBase.m \
						Source/Additions/NSURL+GNUstepBase.m \
						Source/Additions/Unicode.m \
						Source/NSLock.m \
						Source/NSFileHandle.m \
						Source/GSSocketStream.m \
						Source/GSTLS.m \
						Source/NSNotificationCenter.m \
						Source/Additions/GSMime.m \
						Source/unix/GSRunLoopCtxt.m \
						Source/unix/NSStream.m \
						Source/GSLocale.m \
						Source/NSURLProtocol.m \
						Source/GSHTTPURLHandle.m \
						Source/Additions/NSStream+GNUstepBase.m \
						Source/objc-load.m \

# Source/GSFFIInvocation.m \
# Source/cifframe.m \
# Source/GSAvahiClient.m \
# Source/GSConcreteValueTemplate.m \
# Source/GSFFCallInvocation.m \
# Source/GSMDNSNetServices.m \
# Source/NSNetServices.m \
# Source/libgnustep-base-entry.m \
# Source/NSKeyedUnarchiver.m \
# Source/NSKeyValueMutableSet.m \
# Source/NSKeyValueCoding.m \

LOCAL_LDLIBS := -lz -llog -objc2rt_static

LOCAL_STATIC_LIBRARIES := libobjectivec2

LOCAL_SHARED_LIBRARIES := icudata_shared icui18n_shared icuio_shared icule_shared iculx_shared icutu_shared icuuc_shared libxml2 gnustl_shared

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/Headers


include $(BUILD_SHARED_LIBRARY)

