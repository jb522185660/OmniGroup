// Copyright 2008-2013 Omni Development, Inc. All rights reserved.
//
// This software may only be used and reproduced according to the
// terms in the file OmniSourceLicense.html, which should be
// distributed with this project and can also be found at
// <http://www.omnigroup.com/developer/sourcecode/sourcelicense/>.
//
// $Id$

#import <Foundation/NSObject.h>

@class OFXServerAccount, OFXServerAccountType;

/*
 OFXServerAccountRegistry maintains the set of accounts configured by the user.
 */


@interface OFXServerAccountRegistry : NSObject

// The default persistent registry
+ (OFXServerAccountRegistry *)defaultAccountRegistry;

- initWithAccountsDirectoryURL:(NSURL *)accountsDirectoryURL error:(NSError **)outError;

@property(nonatomic,readonly,copy) NSArray *allAccounts; // KVO observable
@property(nonatomic,readonly,copy) NSArray *validatedAccounts; // The subset of allAccounts that have a credentialServiceIdentifier set. KVO observable.

- (NSArray *)accountsWithType:(OFXServerAccountType *)type;
- (OFXServerAccount *)accountWithUUID:(NSString *)uuid;
- (OFXServerAccount *)accountWithDisplayName:(NSString *)name;

// To remove accounts, call -prepareForRemoval on them.
- (BOOL)addAccount:(OFXServerAccount *)account error:(NSError **)outError;

@end
