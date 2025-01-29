
#include <iostream>
#include <map>
#include <unordered_map>

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    if (!head) return nullptr;

    Node* current = head;
    Node* new_head = new Node(head->val);
    Node* new_current = new_head;
    std::unordered_map<Node*, Node*> mapping{ {head, new_head} };

    while (current != nullptr) {
        if (current->next) {
            if (!mapping.count(current->next))
                mapping[current->next] = new Node(current->next->val);

            new_current->next = mapping[current->next];
        }

        if (current->random) {
            if (!mapping.count(current->random))
                mapping[current->random] = new Node(current->random->val);

            new_current->random = mapping[current->random];
        }

        current = current->next;
        new_current = new_current->next;
    }

    return new_head;
}

void printList(Node* head) {
    while (head != nullptr) {
        std::cout << "Node value: " << head->val;
        if (head->random) {
            std::cout << ", Random value: " << head->random->val;
        }
        else {
            std::cout << ", Random value: nullptr";
        }
        std::cout << std::endl;
        head = head->next;
    }
}

int main()
{
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);

    node1->next = node2;
    node2->next = node3;

    // Ustawianie wskaźników random
    node1->random = node3; // Random dla node1 wskazuje na node3
    node2->random = node1; // Random dla node2 wskazuje na node1
    node3->random = node2; // Random dla node3 wskazuje na node2

    // Wyświetlenie oryginalnej listy
    std::cout << "Original List:" << std::endl;
    printList(node1);

    Node* copiedList = copyRandomList(node1);

    std::cout << "\nCopied List:" << std::endl;
    printList(copiedList);
    return 0;
}