//
//  objc_category.cpp
//  bm_lint
//
//  Created by AlexDenisov on 2/16/14.
//  Copyright (c) 2014 Railsware. All rights reserved.
//

#include "objc_category.h"

objc_category::objc_category(const std::string &name)
: _name(name)
{
}

const std::string &objc_category::name() const
{
    return _name;
}
