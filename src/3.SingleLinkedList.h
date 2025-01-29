#pragma once
#include <memory>
class Node
{
public:
    Node(const int v) :
        next(nullptr),
        value(v)
    {}

    std::shared_ptr<Node> next;
    int value;
    // ~Node();
};

class List
{
public:
    List();
    void add(std::shared_ptr<Node> node);
    std::shared_ptr<Node> get(const int value);
    // ~List();

private:
    std::shared_ptr<Node> first;
};

void run3();