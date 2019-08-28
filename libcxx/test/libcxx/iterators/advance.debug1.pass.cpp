//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// Can't test the system lib because this test enables debug mode
// MODULES_DEFINES: _LIBCUDACXX_DEBUG=1
// UNSUPPORTED: c++98, c++03
// UNSUPPORTED: windows
// UNSUPPORTED: with_system_cxx_lib

// <list>

// Call advance(non-bidi iterator, -1)

#define _LIBCUDACXX_DEBUG 0

#include <iterator>
#include "debug_mode_helper.h"

#include "test_iterators.h"

int main(int, char**)
{
    int a[] = {1, 2, 3};
    
    bidirectional_iterator<int *> bidi(a+1);
	std::advance(bidi,  1);  // should work fine
	std::advance(bidi,  0);  // should work fine
    std::advance(bidi, -1);  // should work fine

    forward_iterator<int *> it(a+1);
	std::advance(it, 1);  // should work fine
	std::advance(it, 0);  // should work fine
    EXPECT_DEATH( std::advance(it, -1) ); // can't go backwards on a FwdIter

  return 0;
}

