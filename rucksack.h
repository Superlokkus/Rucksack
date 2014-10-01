//
//  rucksack.h
//  Rucksack
//
//  Created by Markus Klemm on 01.10.14.
//  Copyright (c) 2014 net.markusklemm. All rights reserved.
//

#ifndef Rucksack_rucksack_h
#define Rucksack_rucksack_h

#include <string>

namespace rucksack
{
    struct Item
    {
        unsigned size;
        std::string name;
        
        Item (const unsigned s, const std::string &n) : size(s),name(n) {}
        Item() : Item(0,"Nothing") {}
        
        
    };
}

#endif
