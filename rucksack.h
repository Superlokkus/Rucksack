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
#include <iostream>

namespace rucksack
{
    struct Item
    {
        unsigned size;
        std::string name;
        
        Item (const unsigned s, const std::string &n) : size(s),name(n) {}
        Item (const unsigned s, const char *n) : size(s), name(n) {}
    };
    
    class Rucksack
    {
    public:
        unsigned size() const noexcept {return psize;}
        void setsize(const unsigned s) noexcept {psize = s;}
        
        void addItem (const Item &i) {items.push_back(i);}
        void addItem (Item &&i) {items.push_back(i);}
        
        void showAssigendItems (void) const
        {
            //std::ostream s;
            std::cout << "Name Size" << std::endl;
            for (const auto &i : items)
            {
                std::cout << i.name << i.size << std::endl;
            }
        }
        
        
        Rucksack(const unsigned s, std::vector<Item> && i)
        : psize(s), items(std::move(i)) {}
        Rucksack(const unsigned s) : psize(s) {}
        
    private:
        unsigned psize;
        std::vector<Item> items;
        
    };
}

#endif
