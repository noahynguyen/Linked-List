/* PROGRAM 3
*  Noah Nguyen
*  11/3/2021
*/

#ifndef LIST342_H_
#define LIST342_H_
#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

template <class T>
struct Node
{
    T* data = nullptr;
    Node* next = nullptr;
};

template<class T>
class List342
{
    template <class Tfriend>
    friend ostream& operator<<(ostream& outstream, const List342<Tfriend>& list);
public:
    //constructor
    List342();
    //copy constructor
    List342(const List342& source);
    //destructor
    ~List342();

    bool BuildList(string file_name);
    //Insert an object in the list in the correct place. 
    bool Insert(T* obj);
    //Remove all the target item from the list
    bool Remove(T target, T& result);
    //Peek an item from the linked list
    bool Peek(T target, T& result) const;
    //check if the list is empty
    bool isEmpty() const;
    //remove all items from the list
    void DeleteList();
    // //Takes a sorted list and merges into the calling sorted list 
    bool Merge(List342& list1);
    //check for equality
    bool operator==(const List342& list1) const;
    //check for inequality
    bool operator!=(const List342& list1) const;
    //add two lists together
    List342& operator+=(const List342& list1);
    List342 operator+(const List342& list1);
    //assignment - deep copy
    List342 operator=(const List342& source);

private:
    Node<T>* head_;
};

/* IMPLEMENTATION
*  .cpp ------------------------------------
*/

//Constructor
template <class T>
List342<T>::List342() {
    head_ = nullptr;
}

//copy constructor
template <class T>
List342<T>::List342(const List342<T>& source) : head_(nullptr)
{
    Node<T>* temp = source.head_;
    while (temp != nullptr)
    {
        T* val = temp->data;
        Insert(val);
        temp = temp->next;
    }
}

//destructor
template <class T>
List342<T>::~List342()
{
    this->DeleteList();
}

//Given a string which represents a file, open the file, 
//read the objects from file, and build an ordered list. 
template <class T>
bool List342<T>::BuildList(string file_name)
{
    ifstream inFile;
    inFile.open(file_name);
    if (!inFile)
    {
        cout << "Invalid input file" << endl;
        return false;
    }
    T new_value;
    while (!inFile.eof())
    {   
        inFile >> new_value;
        Insert(&new_value);
    }
    inFile.close();
    return true;
}

//Insert an object in the list in the correct place.
template <class T>
bool List342<T>::Insert(T* obj)
{
    if (obj == nullptr)
    {
        return false;
    }
    //check if there is object already in the list
    if (Peek(*obj, *obj))
    {
        return false;
    }

    Node<T>* ins_node = new Node<T>;
    T* ins_val = new T;
    *ins_val = *obj;
    ins_node->data = ins_val;
    ins_node->next = nullptr;
    //empty list 
    if (head_ == nullptr)
    {
        head_ = ins_node;
        return true;
    }
    //insert at the begining of list
    if (*(ins_node->data) < *(head_->data))
    {
        ins_node->next = head_;
        head_ = ins_node;
        return true;
    }
    else
    {
        Node<T>* temp;
        temp = head_;
        while ((temp->next != nullptr) && (*(ins_node->data) > *(temp->next->data)))
        {
            temp = temp->next;
        }
        ins_node->next = temp->next;
        temp->next = ins_node;
        return true;
    }
}

//Remove the target item from the list.  
//Return the item using a second parameter that is passed in by reference.  
//If the item was found and removed return true, else return false.  
template <class T>
bool List342<T>::Remove(T target, T& result)
{
    //target is at the beginning of the linked list 
    if (head_ != nullptr && *(head_->data) == target)
    {
        result = target;
        Node<T>* del = head_;
        T* del_val = head_->data;
        head_ = head_->next;
        delete del;
        del = nullptr;
        delete del_val;
        del_val = nullptr;
        return true;
    }
    //find the target in the linked list 
    Node<T>* current = head_;
    while (current != nullptr && current->next != nullptr)
    {
        if (*(current->next->data) == target)
        {
            result = target;
            Node<T>* del = current->next;
            T* del_val = current->next->data;
            current->next = current->next->next;
            delete del;
            del = nullptr;
            delete del_val;
            del_val = nullptr;
            return true;
        }
        else
        {
            current = current->next;
        }
   }
    return false;
}

//The same as Remove except the item is not removed from the list.  
//The second item is returned by reference.
template <class T>
bool List342<T>::Peek(T target, T& result) const
{
    //target is at the beginning of the linked list 
    if (head_ != nullptr && *(head_->data) == target)
    {
        result = target;
        return true;
    }
    //find the target in the linked list
    Node<T>* current = head_;
    while (current != nullptr && current->next != nullptr)
    {
        if (*(current->next->data) == target)
        {
            result = target;
            return true;
        }
        else
        {
            current = current->next;
        }
    }
    return false;
}

template <class T>
bool List342<T>::isEmpty() const
{
    return (head_ == nullptr);
}

template <class T>
void List342<T>::DeleteList()
{
    while (head_ != nullptr)
    {
        Node<T>* del = head_;
        T* del_val = head_->data;
        head_ = head_->next;
        delete del;
        del = nullptr;
        delete del_val;
        del_val = nullptr;
    }
}

//Takes a sorted list and merges into the calling sorted list 
//(no new memory should be allocated)
template <class T>
bool List342<T>::Merge(List342<T>& list1)
{
    //terminate when the list passed in is null 
    if (list1.head_ == nullptr || this == &list1) 
    {
        return false;
    }
    //with current null list
    if (head_ == nullptr)
    {
        head_ = list1.head_;
        list1.head_ = nullptr;
        return true;
    }
    //merging in sorted order 
    Node<T> *trackingNode2;
    trackingNode2 = list1.head_;
    if ((*head_->data) >= *(trackingNode2->data))
    {
        list1.head_ = list1.head_->next;
        if (*head_->data == *(trackingNode2->data))
        {       
            delete (trackingNode2->data);
            delete trackingNode2;
        }
        else
        {
            trackingNode2->next = head_;
            head_ = trackingNode2;
        }
    }     
    Node<T> *trackingNode;
    trackingNode = head_;
    while (list1.head_ != nullptr)
    {
        if (trackingNode->next != nullptr)
        {
            trackingNode2 = list1.head_;
            if (*(trackingNode2->data) < *(trackingNode->next->data))
            {
                list1.head_ = list1.head_->next;
                trackingNode2->next = trackingNode->next;
                trackingNode->next = trackingNode2;
                trackingNode = trackingNode2;
                trackingNode2 = nullptr;
            }
            else if (*(trackingNode2->data) == *(trackingNode->next->data))
            {
                list1.head_ = list1.head_->next;
                delete trackingNode2->data;
                delete trackingNode2;
                trackingNode2 = nullptr;
            }
            else
            {
                trackingNode = trackingNode->next;
            }
        }
        else
        {
            trackingNode->next = trackingNode2;
            list1.head_ = nullptr;
            return true;
        }
    }
    return true;
}

//Check for equality
template <class T>
bool List342<T>::operator==(const List342<T>& list1) const
{
    if (head_ == nullptr || list1.head_ == nullptr)
    {
        return false;
    }
    Node<T> *track, *tracklist1;
    track = head_;
    tracklist1 = list1.head_;
    while (track != nullptr && tracklist1 != nullptr)
    {
        if (*(track->data) == *(tracklist1->data))
        {
            track = track->next;
            tracklist1 = tracklist1->next;
        }
        else
        {
            return false;
        }
    }
    if (track == nullptr && tracklist1 == nullptr || (track != nullptr && tracklist1 != nullptr))
    {
        return true;
    }
    return false;
}

//check for inequality
template <class T>
bool List342<T>::operator!=(const List342<T>& list1) const
{
    if (!(list1 == *this))
    {
        return true;
    }
    return false; 
}

//This should add two lists together.  
//The lists are assumed to be sorted and the returned list must also be sorted.
template <class T>
List342<T>& List342<T>::operator+=(const List342<T>& list1)
{
    //empty list
    if (list1.head_ == nullptr)
    {
        return *this;
    }
    if (head_ == nullptr)
    {
        *this = list1;
        return *this;
    }

    Node<T>* ins_node = new Node<T>;
    ins_node = list1.head_;
    while (ins_node != nullptr)
    {
        Insert(ins_node->data);
        ins_node = ins_node->next;
    }
    return *this;
}

template <class T>
List342<T> List342<T>::operator+(const List342<T>& list1)
{
    List342<T> result = *this;
    result += list1;
    return result;
}

//Assignment.  Make a deep copy of all new memory.   
template <class T> 
List342<T> List342<T>::operator=(const List342<T>& source) 
{

    //assigning to itself
    if (this == &source)
    {
        return *this;
    }
    //Empty the destination
    this->DeleteList();

    //source is empty
    if (source.head_ == nullptr)
    {
        return *this;
    }

    Node<T> *ins = new Node<T>;
    T *ins_val = new T;
    *ins_val = *(source.head_->data);
    ins->data = ins_val;
    head_ = ins;

    Node<T> *tracker, *current;
    tracker = head_;
    current = source.head_->next;
    while (current != nullptr)
    {
        ins = new Node<T>;
        ins_val = new T;
        *(ins_val) = *(current->data);
        ins->data = ins_val;
        ins->next = nullptr;  
        tracker->next = ins;
        tracker = tracker->next;
        current = current->next;
    }
    return *this;
}


//Display the list and only the List object, no extra blanks, no tabs, no endl.  
//Display the items on the list in increasing order.  
template <class Tfriend>
ostream& operator<<(ostream& outstream, const List342<Tfriend>& list)
{
    Node<Tfriend>* pNode;

    pNode = list.head_;
    while (pNode != nullptr)
    {
        outstream << *(pNode->data);
        pNode = pNode->next;
    }
    return outstream;
}

#endif 