//
//  objc_class.h
//  bm_lint
//
//  Created by AlexDenisov on 2/11/14.
//  Copyright (c) 2014 Railsware. All rights reserved.
//

#pragma once

#include <string>

class objc_class
{
public:
    explicit objc_class(const std::string &name);
    const std::string &name() const;
private:
    std::string _name;
};
