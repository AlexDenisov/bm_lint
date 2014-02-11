//
//  objc_class.cpp
//  bm_lint
//
//  Created by AlexDenisov on 2/11/14.
//  Copyright (c) 2014 Railsware. All rights reserved.
//

#include "objc_class.h"

objc_class::objc_class(const std::string &name)
: _name(name)
{}

const std::string &objc_class::name() const
{
    return _name;
}
