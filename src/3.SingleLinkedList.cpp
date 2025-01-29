#include "3.SingleLinkedList.h"
#include <iostream>
#include <memory>

using namespace std;

List::List() :
    first(nullptr)
{}

void List::add(std::shared_ptr<Node> node)
{
    if (!first)
    {
        first = std::move(node);
    }
    else
    {
        std::shared_ptr<Node> current = first;
        while (current->next)
        {
            current = current->next;
        }
        current->next = std::move(node);
    }
}

std::shared_ptr<Node> List::get(const int value)
{
    if (!first)
    {
        cout << "List is empty!" << endl;
        return nullptr;
    }
    else
    {
        std::shared_ptr<Node> current = first;
        do
        {
            if (current->value == value)
            {
                cout << "Found value " << current->value << endl;
                return current;
            }
            else
            {
                cout << "Going through " << current->value << endl;
                current = current->next;
            }
        } while (current);
        cout << "Not found: value " << value << endl;
        return nullptr;
    }
}

// With raw pointers
// Node::~Node()
// {
//     delete next;
// }
// 
// List::List()
// {
//     delete first;
// }

int main()
{
    List lista;
    std::shared_ptr<Node> node4 = std::make_shared<Node>(10);
    std::shared_ptr<Node> node7 = std::make_shared<Node>(7);

    lista.add(std::move(node4));
    lista.add(std::make_shared<Node>(2));
    lista.add(std::move(node7));
    lista.add(std::make_shared<Node>(9));
    auto node = lista.get(7);

    if (node)
        cout << node->value << '\n';
    return 0;
}
