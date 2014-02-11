//
//  main.cpp
//  unit_tests
//
//  Created by AlexDenisov on 2/10/14.
//  Copyright (c) 2014 Railsware. All rights reserved.
//

#include "ZingBDD.h"

int main(int argc, const char * argv[])
{
    ZingBDD::StreamReporter reporter(std::cout);
    return ZingBDD::Runner::getInstance().run(reporter);
}

