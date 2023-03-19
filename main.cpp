#include <iostream>
#include "listrand.h"


int main()
{
    ListRand rand;
    ListRand newrand;
    FILE* output = fopen("text.bin","wb");
    rand.push_back("test saber");
    rand.serialize(output);
    fclose(output);
    FILE* input = fopen("text.bin","rb");
    newrand.deserialize(input);
    newrand.push_back("saber test");
    newrand.print();

}
