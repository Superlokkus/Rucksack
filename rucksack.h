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
#include <vector>

namespace rucksack
{
    struct Item
    {
        unsigned size;
        std::string name;
        
        Item (unsigned s, const std::string &n) : size(s),name(n) {}
        Item() : Item(0,"Nothing") {}
        
        
    };
    
    class Rucksack
    {
    public:
        unsigned size() const {return psize;}
        void setsize(const unsigned s) {psize = s;}
        
        Rucksack(unsigned s, std::vector<Item> && i)
        : psize(s), items(std::move(i)) {}
        Rucksack(unsigned s) : psize(s) {}
        
    private:
        unsigned psize;
        std::vector<Item> items;
        
    };
}

#endif
