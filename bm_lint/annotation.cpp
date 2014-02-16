//
//  annotation.cpp
//  bm_lint
//
//  Created by AlexDenisov on 2/16/14.
//  Copyright (c) 2014 Railsware. All rights reserved.
//

#include "annotation.h"

annotation::annotation(const std::string &name)
: _name(name)
{
}

const std::string &annotation::name() const
{
    return _name;
}
