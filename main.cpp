//
//  main.cpp
//  BloomFilter
//
//  Created by Farhan Abrol on 12/18/14.
//  Copyright (c) 2014 Farhan Abrol. All rights reserved.
//

#include "bloom.h"

void testBloomFilter() {
    bool found;
    BloomFilter<unsigned, unsigned> * blm = new BloomFilter<unsigned, unsigned> (1000U, 2U);
    blm->insert(1, 2);
    assert(blm->get(1, &found) == 2);
    blm->insert(2, 2);
    assert(blm->get(2, &found) == 2);
    blm->remove(2, 2);
    assert(!blm->get(2, &found));

}
int main(int argc, const char * argv[]) {
    testBloomFilter();
    return 0;
}
