#include "linearList.h"

using namespace std;
//顺序表打印

void sequenceList::print()
{

    cout << curNumberOfItem << ":";

    for(int i = 0; i < curNumberOfItem-1; i++)
    {
        cout << myList[i] << ",";
    }

    cout << myList[curNumberOfItem-1] << endl;

}



//链表打印
void linkList::print()
{
    curNode = firstNode;

    cout << listSize << ":";

    while(curNode != lastNode)
    {
        if(curNode->next == lastNode)
            cout << curNode->next->data << endl;
        else
        {
            cout << curNode->next->data << ",";
        }
        
        
        curNode = curNode->next;
    }
}

sequenceList::sequenceList(const int& maxcapcity, const int& curnumberofitem, float list[] )
{
    myList = new float[1000];
    curNumberOfItem = curnumberofitem;
    maxCapcity = maxcapcity;
    for (int i = 0; i < curNumberOfItem; ++i) {
        myList[i] = list[i];
    }
}

sequenceList::~sequenceList() {
    if (myList != nullptr) {
        delete[] myList;
        myList = nullptr; // 将指针设置为 nullptr，以防后续代码尝试使用已释放的内存
    }
}

bool sequenceList::addItem(const float& item)
{
    if (this->curNumberOfItem < this->maxCapcity) {
        this->myList[this->curNumberOfItem] = item;
        this->curNumberOfItem++;
        return true;
    } else {
        return false;
    }
}

bool sequenceList::insertItem(const int& pos, const float& item)
{
    if (pos < 0 || pos > this->curNumberOfItem || this->curNumberOfItem >= this->maxCapcity) {
        return false;
    }
    if (pos == curNumberOfItem) {
        addItem(item);
        return true;
    }
    for (int i = this->curNumberOfItem; i > pos; --i) {
        this->myList[i] = this->myList[i - 1];
    }
    this->myList[pos] = item;
    this->curNumberOfItem++;
    return true;
}

int sequenceList::deleteItem(const float& item) {
    int pos = locate(item);
    if (pos != -1) {
        for (int i = pos; i < curNumberOfItem - 1; ++i) {
            myList[i] = myList[i + 1];
        }
        curNumberOfItem--;
    }
    return pos;
}

bool sequenceList::locate(const int& pos, float& item) {
    if (pos < 0 || pos >= curNumberOfItem) {
        return false;
    }
    item = myList[pos];
    return true;
}

int sequenceList::locate(const float& item) {
    for (int i = 0; i < curNumberOfItem; ++i) {
        if (myList[i] == item) {
            return i;
        }
    }
    return -1;
}

void sequenceList::reverse() {
    for (int i = 0; i < this->curNumberOfItem / 2; ++i) {
        float temp = this->myList[i];
        this->myList[i] = this->myList[this->curNumberOfItem - i - 1];
        this->myList[this->curNumberOfItem - i - 1] = temp;
    }
}
linkList::linkList() : firstNode(nullptr), curNode(nullptr), lastNode(nullptr), listSize(0) {}

linkList::linkList(const int &listsize, float list[]) {
    listSize = listsize;
    firstNode = new listNode();
    curNode = new listNode();
    firstNode->next = curNode;
    for (int i = 0; i < listSize; ++i) {
        curNode->data = list[i];
        if (i<listSize-1) {
            listNode *nextNode = new listNode();
            curNode->next = nextNode;
            curNode = nextNode;
        }
    }
    lastNode = curNode; 
}
linkList::~linkList() {
    listNode *node = firstNode;
    while (node != nullptr) {
        listNode *temp = node;
        node = node->next;
        delete temp;
    }
    // 释放完节点后，将指针置为 nullptr
    firstNode = nullptr;
    curNode = nullptr;
    lastNode = nullptr;
}
bool linkList::headInsertItem(const float& item) {
    listNode *node = new listNode();
    node->data = item;
    listNode *temp = firstNode->next;
    firstNode->next = node;
    node->next = temp;
    listSize++;
    return true;
}
bool linkList::tailInsertItem(const float& item) {
    listNode *node = new listNode();
    node->data = item;
    lastNode->next = node;
    node->next = nullptr;
    lastNode = node;
    listSize++;
    return true;
}
int linkList::insertItem(const int& index, const float& item) {
    if (index > listSize||index<0) return -1;
    listNode *node = new listNode();
    node->data = item;
    int temp = index;
    listNode *cur = firstNode;
    while (temp > 0) {
        cur = cur->next;
        temp--;
    }
    node->next = cur->next;
    cur->next = node;
    listSize++;
    return index;
}
int linkList::deleteItem(const float& item) {
    listNode *cur = firstNode;
    int index = 0;
    while (cur->next!=nullptr) {
        if (cur->next->data == item) {
            listNode *temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
            listSize--;
            return index;
        }
        cur = cur->next;
        index++;
    }
    return -1;
}
bool linkList::locate(const int& index, float& item) {
    if (index > listSize||index<0) return false;
    int temp = 0;
    listNode *cur = firstNode;
    while (temp < index) {
        cur = cur->next;
    }
    item = cur->next->data;
    return true;
}
int linkList::locate(const float& item) {
    int index = 0;
    listNode *cur = firstNode;
    while (cur->next != nullptr) {
        if (cur->next->data == item) {
            return index;
        } 
        cur = cur->next;
        index++;
    }
    return -1;
}
void linkList::ascendingOrder() {
    listNode *cur = firstNode;
    vector<float> temp;
    while (cur->next != nullptr) {
        temp.push_back(cur->next->data);
        cur = cur->next;
    }
    sort(temp.begin(), temp.end());
    cur = firstNode;
    int index = 0;
    while (cur->next != nullptr) {
        cur->next->data = temp[index];
        index++;
        cur = cur->next;
    }
}
void linkList::reverse() {
    stack<float> temp;
    listNode *cur = firstNode;
    while (cur->next) {
        temp.push(cur->next->data);
        cur = cur->next;
    }
    cur = firstNode;
    while (cur->next) {
        cur->next->data = temp.top();
        temp.pop();
        cur = cur->next;
    }
}
void merge(linkList &a, linkList &b) {
    listNode *curB = b.firstNode;
    listNode *curA = a.lastNode;
    a.listSize = a.listSize + b.listSize;
    while (curB->next) {
        listNode *node = new listNode();
        node->data = curB->next->data;
        curA->next = node;
        curA = curA->next;
        curB = curB->next;
    }
    a.lastNode = curA;
    a.ascendingOrder();
    a.reverse();
}
