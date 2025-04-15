#pragma once
#include "tools.hxx"

namespace fwl
{
    using namespace tls;

    using Value = int;

    struct Elem
    {
        Value value = Value();
        Elem *next = nullptr;
    };
    struct forwardlist
    {
        Elem *begin = nullptr;
        Size size = 0;
    };

    auto pop(forwardlist *&list) -> void;
    auto push(forwardlist *&list, Value value) -> void;

    auto remove(forwardlist *&list) -> void;

    auto fill(forwardlist *&list) -> void;

    auto output(forwardlist const* list) -> void;

    auto pop(Elem *&head) -> void;
    auto push(Elem *&head, Value value) -> void;

    auto remove(Elem *&head) -> void;

    auto fill(Elem *head) -> void;

    auto output(Elem const *head) -> void;

}
auto fwl::pop(forwardlist *&list) -> void
{
    Elem *e = list->begin;
    list->begin = list->begin->next;
    delete[] e;
}
auto fwl::push(forwardlist *&list, Value value) -> void
{
    Elem* e = new Elem;
    e->value = value;
    e->next=list->begin;
    list->begin=e;
    list->size+=1;
}

auto fwl::remove(forwardlist *&list) -> void
{
    remove(list->begin);
    list->size = 0;
}

auto fwl::fill(forwardlist *&list) -> void
{
    Value v = Value();
    for (Elem *p = list->begin->next; p != nullptr; p = p->next)
    {
        p->value = v;
    }
}

auto fwl::output(forwardlist const* list) -> void
{
    for (Elem const *p = list->begin; p != nullptr; p = p->next)
    {
        std::cout << p->value << ' ';
    }
    std::cout << std::endl;
}

auto fwl::pop(Elem *&head) -> void
{
    Elem *e = head;
    head = head->next;
    delete[] e;
}
auto fwl::push(Elem *&head, Value value) -> void
{
    Elem *e = new Elem;
    e->value = value;
    e->next = head;
    head = e;
}
auto fwl::remove(Elem *&head) -> void
{
    while (head != nullptr)
    {
        pop(head);
    }
}
auto fwl::fill(Elem *head) -> void
{
    Value v = Value();
    for (Elem *p = head->next; p != nullptr; p = p->next)
    {
        p->value = v;
    }
}

auto fwl::output(Elem const *head) -> void
{
    for (Elem const *p = head; p != nullptr; p = p->next)
    {
        std::cout << p->value << ' ';
    }
    std::cout << std::endl;
}