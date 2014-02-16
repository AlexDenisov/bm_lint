//
//  parser.cpp
//  bm_lint
//
//  Created by AlexDenisov on 2/11/14.
//  Copyright (c) 2014 Railsware. All rights reserved.
//

#include "parser.h"
#include "ast.h"

#include "objc_class.h"
#include "objc_property.h"

#include "Index.h"

#include <iostream>

static inline const char *cursor_name(CXCursor &cursor)
{
    CXString cxname = clang_getCursorSpelling(cursor);
    const char *name = clang_getCString(cxname);
    clang_disposeString(cxname);
    return name;
}

parser::parser(ast *ast)
: _ast(ast)
{
}

void parser::parse(const std::string &filename)
{
    CXIndex index = clang_createIndex(0, 1);
    
    CXTranslationUnit tu = clang_parseTranslationUnit(index, filename.c_str(), NULL, 0, NULL, 0, CXTranslationUnit_SkipFunctionBodies);
    
    clang_visitChildrenWithBlock(clang_getTranslationUnitCursor(tu), ^(CXCursor cursor, CXCursor parent) {
        
        CXCursorKind cursorKind = clang_getCursorKind(cursor);
        const char *name = cursor_name(cursor);
        
        switch (cursorKind) {
                
            case CXCursor_ObjCInterfaceDecl:
            case CXCursor_ObjCImplementationDecl:
                handle_objc_class(name);
                break;
                
            case CXCursor_ObjCSuperClassRef:
                handle_objc_super_class(name);
                break;
                
            case CXCursor_ObjCPropertyDecl:
                handle_objc_property(name);
                break;
                
            case CXCursor_AnnotateAttr:
                handle_annotation(name);
                break;
                
            case CXCursor_ObjCDynamicDecl:
                handle_objc_dynamic(name);
                break;
                
                //            case CXCursor_ObjCDynamicDecl:
                //                handleDynamic(cursor);
                //                break;
                //            case CXCursor_ObjCSynthesizeDecl:
                //                handleSynthesize(cursor);
                //                break;
                //            case CXCursor_AnnotateAttr:
                //                handleAnnotation(cursor);
                //                break;
                //            case CXCursor_ObjCClassMethodDecl:
                //                handleMethod(cursor);
                //                break;
                //
            default:
            {
                CXString name = clang_getCursorSpelling(cursor);
                CXString cursorName = clang_getCursorKindSpelling(clang_getCursorKind(cursor));
                
                std::cout << clang_getCString(cursorName) << "\t" << clang_getCString(name) << std::endl;
                
                clang_disposeString(name);
                clang_disposeString(cursorName);
            }break;
        }
        
        return CXChildVisit_Recurse;
    });
    
    clang_disposeTranslationUnit(tu);
    clang_disposeIndex(index);
}

void parser::handle_objc_class(const std::string &name)
{
    _current_class = _ast->lookup_class(name);
}

void parser::handle_objc_super_class(const std::string &name)
{
    objc_class *objc_class = _ast->lookup_class(name);
    if (_current_class) {
        _current_class->set_superclass(objc_class);
    }
}

void parser::handle_objc_property(const std::string &name)
{
    _current_property = _current_class->lookup_property(name);
}

void parser::handle_objc_dynamic(const std::string &name)
{
    objc_property *property = _current_class->lookup_property(name);
    property->set_dynamic(true);
}

void parser::handle_annotation(const std::string &name)
{
    annotation *ann = _ast->lookup_annotation(name);
    _current_property->add_annotation(ann);
}
