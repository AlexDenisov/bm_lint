//
//  main.cpp
//  bm_lint
//
//  Created by AlexDenisov on 2/10/14.
//  Copyright (c) 2014 Railsware. All rights reserved.
//

#include <iostream>
#include "Index.h"


int main(int argc, const char * argv[])
{
    CXIndex index = clang_createIndex(0, 1);
    
    CXTranslationUnit tu = clang_parseTranslationUnit(index, "", NULL, 0, NULL, 0, CXTranslationUnit_SkipFunctionBodies);
    
    clang_visitChildrenWithBlock(clang_getTranslationUnitCursor(tu), ^(CXCursor cursor, CXCursor parent) {
        return CXChildVisit_Recurse;
    });
    
    clang_disposeTranslationUnit(tu);
    clang_disposeIndex(index);
    
    return 0;
}

