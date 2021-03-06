//
// Copyright (c) 2002-2015 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// The SeparateArrayInitialization function splits each array initialization into a declaration and an assignment.
// Example:
//     type[n] a = initializer;
// will effectively become
//     type[n] a;
//     a = initializer;
//
// Note that if the array is declared as const, the initialization is still split, making the AST
// technically invalid. Because of that this transformation should only be used when subsequent
// stages don't care about const qualifiers.

#ifndef COMPILER_TRANSLATOR_SEPARATEARRAYINITIALIZATION_H_
#define COMPILER_TRANSLATOR_SEPARATEARRAYINITIALIZATION_H_

class TIntermNode;

void SeparateArrayInitialization(TIntermNode *root);

#endif  // COMPILER_TRANSLATOR_SEPARATEARRAYINITIALIZATION_H_
