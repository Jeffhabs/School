//
//  debug.h
//  Compiler
//
//  Created by Jeffrey Haberle on 2/21/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#ifndef debug_h
#define debug_h

#define ShowMessages 0

#include <iostream>

#if ShowMessages
#define MSG(X) cout << X << endl;
#else
#define MSG(X) ;
#endif


#endif /* debug_h */
