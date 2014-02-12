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

objc_class *ast::lookup_class(const std::string &class_name)
{
    objc_class *c = _classes[class_name];
    if (!c) {
        c = new objc_class(class_name);
        _classes[class_name] = c;
    }
    
    return c;
}

objc_protocol *ast::lookup_protocol(const std::string &protocol_name)
{
    objc_protocol *protocol = _protocols[protocol_name];
    if (!protocol) {
        protocol = new objc_protocol(protocol_name);
        _protocols[protocol_name] = protocol;
    }
    
    return protocol;
}

const class_map &ast::objc_classes() const
{
    return _classes;
}
