//
//  utils.h
//  BloomFilter
//
//  Created by Farhan Abrol Home on 12/19/14.
//  Copyright (c) 2014 Farhan Abrol. All rights reserved.
//

#ifndef BloomFilter_utils_h
#define BloomFilter_utils_h

#include <vector>

template<typename T>
void print_vec(std::vector<T> container) {
    for (auto it = container.begin(); it != container.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
}
#endif
