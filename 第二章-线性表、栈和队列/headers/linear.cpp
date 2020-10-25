// File:    线性表.cpp
// Author:  csh
// Date:    2020/05/24
// ===================

#include <iostream>
#include "linear.hpp"


// ************************** 线性表的顺序存储 *********************************//

template <typename T>
void ArrList<T>::clear(){
    curLen = 0;
}

template <typename T>
bool ArrList<T>::isEmpty(){
    return curLen == 0;
}

template <typename T>
bool ArrList<T>::isFull(){
    return curLen == maxSize;
}

template <typename T>
int ArrList<T>::length(){
    return curLen;
}

template <typename T>
bool ArrList<T>::append(const T value){
    using std::cout;
    using std::endl;
    if(curLen >= maxSize){
        cout << "The list is overflow" << endl;
        return false;
    }
    aList[curLen] = value;
    curLen++;
    return true;
}

template <typename T>
bool ArrList<T>::getValue(const int p, T &value){
    using std::cout;
    using std::endl;
    if(p < 0 || p > curLen-1){      // 判断p位置是否合法
        cout << "Location is illegal" << endl;
        return false;
    }
    value = aList[p];
    return true;
}

template <typename T>
bool ArrList<T>::setValue(const int p, const T value){
    using std::cout;
    using std::endl;
    if(p < 0 || p > curLen-1){      // 判断p位置是否合法
        cout << "Location is illegal" << endl;
        return false;
    }
    aList[p] = value;
    return true;
}

template <typename T>
bool ArrList<T>::insert(const int p, const T value){
    using std::cout;
    using std::endl;
    if(curLen >= maxSize){          // 检查顺序表是否溢出
        cout << "The list is overflow" << endl;
        return false;
    }
    if(p < 0 || p > curLen){        // 检查位置是否合法
        cout << "Insertion point is illegal" << endl;
        return false;
    }
    for(int i = curLen; i > p; i--)
        aList[i] = aList[i-1];      // 将p位置以及之后的元素后移一位
    aList[p] = value;
    curLen++;
    return true;
}

template <typename T>
bool ArrList<T>::remove(const int p){
    using std::cout;
    using std::endl;
    if(curLen <= 0){
        cout << "No element to remove" << endl;
        return false;
    }
    if(p < 0 || p > curLen-1){
        cout << "remove is illegal" << endl;
        return false;
    }
    for(int i = p; i < curLen-1; i++)
        aList[i] = aList[i+1];
    curLen--;
    return true;
}

template <typename T>
bool ArrList<T>::getPos(int &p, const T value){
    for(int i = 0; i < maxSize-1; i++){
        if(value == aList[i]){
            p = i;
            return true;
        }
    }
    return false;
}

template <typename T>
void ArrList<T>::showAll(){
    using std::cout;
    using std::endl;
    if(curLen == 0)
        cout << "No element in the list" << endl;
    for(int i = 0; i < curLen; i++)
        cout << aList[i] << " ";
    cout << endl;
    return;
}

// *****************************************************************************//


// ************************** 线性表的链式存储 *********************************//
template <typename T>
LinkList<T>::LinkList(){
    head = tail = new Link<T>;
}

template <typename T>
LinkList<T>::~LinkList(){
    Link<T> *tmp;
    while(head){
        tmp = head;
        head = head->next;
        delete tmp;
    }
}

template <typename T>
Link<T>* LinkList<T>::setPos(const int p){
    using std::cout;
    using std::endl;
    int count = 0;
    if(p == -1)                     // -1是头节点，0是第一个结点
        return head;
    if(p >= length() || p < -1){
        cout << "position is error" << endl;
        return nullptr;
    }
    Link<T> *tmp = head->next;
    while(tmp && count < p){
        tmp = tmp->next;
        count++;
    }
    return tmp;
}

template <typename T>
void LinkList<T>::clear(){
    ~LinkList();
    head = tail = new Link<T>;
}

template <typename T>
int LinkList<T>::length(){
    // 该函数可增加计数属性，避免遍历链表
    int count = 0;
    Link<T> *tmp = head->next;
    while(tmp != nullptr){
        count ++;
        tmp = tmp->next;
    }
    return count;
}

template <typename T>
bool LinkList<T>::append(const T value){
    Link<T> *tmp;
    tmp = new Link<T>(value);
    if(head == tail){                           // 没有元素
        head->next = tmp;
        tail = tmp;
    }else{
        tail->next = tmp;
        tail = tmp;
    }
    return true;
}

template <typename T>
bool LinkList<T>::insert(const int p, const T value){
    using std::cout;
    using std::endl;
    Link<T> *pre, *q;
    if((pre = setPos(p-1)) == nullptr){            // p是第i个节点的前驱
        cout << "Insertion point is illegal" << endl;
        return false;
    }
    q = new Link<T>(value, pre->next);
    pre->next = q;
    if(pre == tail)
        tail = q;
    return true;
}

template <typename T>
bool LinkList<T>::remove(const int p){
    using std::cout;
    using std::endl;
    Link<T> *pre, *cur;
    if((pre = setPos(p-1)) == nullptr || pre == tail){
        cout << "Removal point is illegal" << endl;
        return false;
    }
    cur = pre->next;                            // 待删节点
    if(cur == tail){                            // 待删节点为尾节点
        tail = pre;
        pre->next = nullptr;
        delete cur;
    }else if(cur != nullptr){
        pre->next = cur->next;
        delete cur;
    }
    return true;
}

template <typename T>
bool LinkList<T>::getPos(int &p, const T value){
    Link<T> *tmp = head->next;
    int count = -1;
    while(tmp != nullptr){
        count ++;
        if(tmp->data == value){
            p = count;
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

template <typename T>
bool LinkList<T>::getValue(const int p, T &value){
    using std::cout;
    using std::endl;
    Link<T> *tmp;
    if((tmp = setPos(p)) == nullptr){
        cout << "Location is illegal" << endl;
        return false;
    }
    value = tmp->data;
    return true;
}

template <typename T>
void LinkList<T>::showAll(){
    using std::cout;
    using std::endl;
    Link<T> *tmp = head->next;
    while(tmp != nullptr){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

template <typename T>
Link<T>* LinkList<T>::getFirst(){
    return head->next;
}

// *****************************************************************************//
