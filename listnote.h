#ifndef LISTNOTE_H
#define LISTNOTE_H
#include <string>

class ListNode
{
public:
    ListNode();
    ListNode *prev = nullptr;
    ListNode *next = nullptr;
    ListNode *rand = nullptr;
public:
    std::string data = " ";

};

#endif // LISTNOTE_H
