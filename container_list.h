#ifndef CONTAINER_LIST_H
#define CONTAINER_LIST_H

#include <initializer_list>
template <typename Type>
class container_list
{
private:
    Type *list;
    int amount;
public:
    container_list();// конструктор по умолчанию +
    ~container_list(); // дизструктор +
    container_list(const container_list<Type> &lst);// конструктор копирования
    container_list(container_list<Type> &&lst); // конструктор переноса +
    explicit container_list(std::initializer_list<Type> lst);// явный конструктор со список инициализации +
};

template <typename Type>
container_list<Type>::~container_list<Type>()
{
    delete[] list;
}

template <typename Type>
container_list<Type>::container_list(container_list<Type> &&lst)
{
    list=lst.list;
    lst.list=nullptr;
}

template <typename Type>
container_list<Type>::container_list(std::initializer_list<Type> lst){
    amount =lst.size();
    int i=0;
    for(Type item: lst)
        list[i++]=item;
}

#endif // CONTAINER_LIST_H
