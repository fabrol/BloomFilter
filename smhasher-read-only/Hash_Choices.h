//
//  Hash_Choices.h
//  BloomFilter
//
//  Created by Farhan Abrol Home on 12/19/14.
//  Copyright (c) 2014 Farhan Abrol. All rights reserved.
//

#ifndef BloomFilter_Hash_Choices_h
#define BloomFilter_Hash_Choices_h

#include "Platform.h"
#include "Hashes.h"
#include "KeysetTest.h"
#include "SpeedTest.h"
#include "AvalancheTest.h"
#include "DifferentialTest.h"
#include "PMurHash.h"

namespace hasher {
    
    struct HashInfo
    {
        pfHash hash;
        int hashbits;
        uint32_t verification;
        const char * name;
        const char * desc;
    };
    
    HashInfo g_hashes[] =
    {
        { DoNothingHash,        32, 0x00000000, "donothing32", "Do-Nothing function (only valid for measuring call overhead)" },
        { DoNothingHash,        64, 0x00000000, "donothing64", "Do-Nothing function (only valid for measuring call overhead)" },
        { DoNothingHash,       128, 0x00000000, "donothing128", "Do-Nothing function (only valid for measuring call overhead)" },
        
        { crc32,                32, 0x3719DB20, "crc32",       "CRC-32" },
        
        { md5_32,               32, 0xC10C356B, "md5_32a",     "MD5, first 32 bits of result" },
        { sha1_32a,             32, 0xF9376EA7, "sha1_32a",    "SHA1, first 32 bits of result" },
        
        { FNV,                  32, 0xE3CBBE91, "FNV",         "Fowler-Noll-Vo hash, 32-bit" },
        { Bernstein,            32, 0xBDB4B640, "bernstein",   "Bernstein, 32-bit" },
        { lookup3_test,         32, 0x3D83917A, "lookup3",     "Bob Jenkins' lookup3" },
        { SuperFastHash,        32, 0x980ACD1D, "superfast",   "Paul Hsieh's SuperFastHash" },
        { MurmurOAAT_test,      32, 0x5363BD98, "MurmurOAAT",  "Murmur one-at-a-time" },
        { Crap8_test,           32, 0x743E97A1, "Crap8",       "Crap8" },
        
        { CityHash64_test,      64, 0x25A20825, "City64",      "Google CityHash64WithSeed" },
        { CityHash128_test,    128, 0x6531F54E, "City128",     "Google CityHash128WithSeed" },
        
        { SpookyHash32_test,    32, 0x3F798BBB, "Spooky32",    "Bob Jenkins' SpookyHash, 32-bit result" },
        { SpookyHash64_test,    64, 0xA7F955F1, "Spooky64",    "Bob Jenkins' SpookyHash, 64-bit result" },
        { SpookyHash128_test,  128, 0x8D263080, "Spooky128",   "Bob Jenkins' SpookyHash, 128-bit result" },
        
        // MurmurHash2
        
        { MurmurHash2_test,     32, 0x27864C1E, "Murmur2",     "MurmurHash2 for x86, 32-bit" },
        { MurmurHash2A_test,    32, 0x7FBD4396, "Murmur2A",    "MurmurHash2A for x86, 32-bit" },
        { MurmurHash64A_test,   64, 0x1F0D3804, "Murmur2B",    "MurmurHash2 for x64, 64-bit" },
        { MurmurHash64B_test,   64, 0xDD537C05, "Murmur2C",    "MurmurHash2 for x86, 64-bit" },
        
        // MurmurHash3
        
        { MurmurHash3_x86_32,   32, 0xB0F57EE3, "Murmur3A",    "MurmurHash3 for x86, 32-bit" },
        { MurmurHash3_x86_128, 128, 0xB3ECE62A, "Murmur3C",    "MurmurHash3 for x86, 128-bit" },
        { MurmurHash3_x64_128, 128, 0x6384BA69, "Murmur3F",    "MurmurHash3 for x64, 128-bit" },
        
        { PMurHash32_test,      32, 0xB0F57EE3, "PMurHash32",  "Shane Day's portable-ized MurmurHash3 for x86, 32-bit." },
    };
    
    HashInfo * findHash ( const char * name )
    {
        for(size_t i = 0; i < sizeof(g_hashes) / sizeof(HashInfo); i++)
        {
            if(_stricmp(name,g_hashes[i].name) == 0) return &g_hashes[i];
        }
        
        return NULL;
    }
    

}

#endif
