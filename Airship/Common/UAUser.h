/*
 Copyright 2009-2012 Urban Airship Inc. All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.

 2. Redistributions in binaryform must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided withthe distribution.

 THIS SOFTWARE IS PROVIDED BY THE URBAN AIRSHIP INC``AS IS'' AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 EVENT SHALL URBAN AIRSHIP INC OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>
#import "UAObservable.h"

typedef enum _UAUserState {
    UAUserStateEmpty = 0,
    UAUserStateCreating = 1,
    UAUserStateCreated = 2
} UAUserState;

@protocol UAUserObserver <NSObject>
@optional

// Notified when user created or modified
- (void)userUpdated;
- (void)userUpdateFailed;

@end

@interface UAUser : UAObservable

// Public interface
@property (nonatomic, readonly, assign) UAUserState userState;
@property (nonatomic, readonly, copy) NSString *username;
@property (nonatomic, readonly, copy, nonatomic) NSString *password;
@property (nonatomic, readonly, copy, nonatomic) NSString *url;

+ (UAUser *)defaultUser;
+ (void)land;

- (BOOL)defaultUserCreated;

//Specifies a default PRE-EXISTING username and password to use in the case a new user would 
//otherwise be created by [UAUser defaultUser]
+ (void)setDefaultUsername:(NSString *)defaultUsername withPassword:(NSString *)defaultPassword;

- (void)initializeUser;
- (void)loadUser;

@end