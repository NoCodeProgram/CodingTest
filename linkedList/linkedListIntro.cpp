#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printNodes(ListNode * node)
{
    ListNode * crntNodePtr = node;
    while (crntNodePtr != nullptr)
    {
        std::cout << crntNodePtr->val << " ";
        crntNodePtr = crntNodePtr->next;
    }
    std::cout << "\n";
}

void recurPrint(ListNode * node)
{
    if(node == nullptr)
    {
        return;
    }
    std::cout << node->val << " ";
    recurPrint(node->next);
}


int main()
{
    ListNode node1 = ListNode(1);
    ListNode node2 = ListNode(2);
    ListNode node3 = ListNode(3);
    ListNode node4 = ListNode(4);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    printNodes(&node1);
    recurPrint(&node1);
}