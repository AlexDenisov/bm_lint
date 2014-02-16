//
//  ast.cpp
//  bm_lint
//
//  Created by AlexDenisov on 2/11/14.
//  Copyright (c) 2014 Railsware. All rights reserved.
//

#include "ast.h"
#include "objc_class.h"
#include "objc_protocol.h"
#include "annotation.h"

ast::~ast()
{
    auto cit = _classes.begin();
    while (cit != _classes.end()) {
        objc_class *c = *cit;
        cit++;
        delete c;
    }
    
    auto pit = _protocols.begin();
    while (pit != _protocols.end()) {
        objc_protocol *p = *pit;
        pit++;
        delete p;
    }
    
    _classes.clear();
    _protocols.clear();
    _class_map.clear();
    _protocol_map.clear();
}

objc_class *ast::lookup_class(const std::string &class_name)
{
    objc_class *c = _class_map[class_name];
    if (!c) {
        c = new objc_class(class_name);
        _class_map[class_name] = c;
        _classes.push_back(c);
    }
    
    return c;
}

objc_protocol *ast::lookup_protocol(const std::string &protocol_name)
{
    objc_protocol *protocol = _protocol_map[protocol_name];
    if (!protocol) {
        protocol = new objc_protocol(protocol_name);
        _protocol_map[protocol_name] = protocol;
        _protocols.push_back(protocol);
    }
    
    return protocol;
}

annotation *ast::lookup_annotation(const std::string &annotation_name)
{
    annotation *ann = _attribute_map[annotation_name];
    if (!ann) {
        ann = new annotation(annotation_name);
        _attribute_map[annotation_name] = ann;
    }
    
    return ann;
}

const class_list &ast::objc_classes() const
{
    return _classes;
}

const protocol_list &ast::objc_protocols() const
{
    return _protocols;
}
