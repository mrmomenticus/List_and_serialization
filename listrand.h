#ifndef LISTRAND_H
#define LISTRAND_H
#include "listnote.h"
#include <iostream>
#include <assert.h>
#include <map>

class ListRand
{
public:
    ListRand();
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
public:
    void serialize(FILE *file);
    void deserialize(FILE *file);
    void push_back(std::string data);
    void print();
public:
    int count = 0;
};

#endif // LISTRAND_H
