#include "listrand.h"



ListRand::ListRand()
{

}
void ListRand::serialize(FILE* file) {
    assert(file);
    std::map<ListNode*, int> map;

    size_t byte = 0;
    ListNode *node_ptr = head;
    for (int id = 0; id != count; id++)
    {
        map.emplace(node_ptr, id);
        node_ptr = node_ptr->next;
    }
    byte += fwrite(&count, sizeof(count), 1, file);
    for (ListNode* node = head; node != nullptr; node = node->next) {
        size_t string_len = node->data.size();
        byte += fwrite(&string_len, sizeof(size_t), 1, file);
        byte += fwrite(node->data.c_str(), string_len, 1, file);
    }
    for (ListNode* node = head; node != nullptr; node = node->next) {
        int rand = -1;
        if(node->rand != nullptr){
            rand = map[node->rand];
        }
        else{
            rand = -1;
        }
        byte += fwrite(&rand, sizeof(int), 1, file);
    }
    std::cout << "Сериализация: "<< byte << std::endl;
    delete node_ptr;
}
void ListRand::deserialize(FILE* file) {
    int count = -1;
    ListNode *node_ptr = head;
    size_t byte = 0;
    assert(file);
    byte += fread(&count, sizeof(int), 1, file);
    assert(!(byte < 0));
    std::map<int, ListNode*> map;
    for (int id = 0; id < count; id++)
    {
        size_t size = 0;
        byte+= fread(&size, sizeof(size_t), 1, file);
        if (size > 0) {
            std::string data;
            data.resize(size);
            byte+= fread(&data[0], size, 1, file);
            push_back(data);
            map.insert(std::make_pair(id, tail));
        }
    }
    for (int id = 0; id!= count; id++)
    {
        int rand = -1;
        byte+= fread(&rand, sizeof(int), 1, file);
        if (rand >= 0 && rand < count)
        {
            node_ptr->rand = map[rand];
            node_ptr = node_ptr->next;
        }
    }
    delete node_ptr;
    std::cout<<"Десериализация: "<<byte<<std::endl;
}

void ListRand::push_back(std::string data)
{
    ListNode* node = new ListNode;
    node->data = data;
    node->next = nullptr;
    node->rand = nullptr;
    node->prev = tail;
    if (head != nullptr)
    {
        tail->next = node;

    }
    else{
        head = node;
    }
    tail = node;
    count++;
}
void ListRand::print(){
    ListNode* node_ptr = head;
    while (node_ptr) {
        std::cout << node_ptr->data << std::endl;
        node_ptr = node_ptr->next;
    }
}











