#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
class sequenceList
{
private:
    float* myList;
    int curNumberOfItem;
    int maxCapcity;
    
public:
    sequenceList(const int&, const int&, float[]);
    ~sequenceList();

    bool addItem(const float&);
    bool insertItem(const int&,const float&);
    int deleteItem(const float&);
    bool locate(const int&, float&);
    int locate(const float&);
    void reverse();
    void print();
};

class linkList;
class listNode{
    friend class linkList;
    friend void merge(linkList&, linkList&);
private:
    float data;
    listNode* next;
    
public:
    listNode(){next = NULL;}
    listNode(float nodeData, listNode *succ = nullptr) : data(nodeData), next(succ){};
    ~listNode() {};
};

class linkList
{
private:
    listNode* firstNode;
    listNode* curNode;
    listNode* lastNode;

    int listSize;
public:
    linkList();
    linkList(const int&, float[]);
    ~linkList();
    friend void merge(linkList &, linkList &);
    bool headInsertItem(const float&);          //按值头插
    //头插一个值怎么会出现false的情况阿？难道是机器内存不足吗？
    //这个感觉改为void 函数更合适
    //尾插也是
    bool tailInsertItem(const float&);          //按值尾插
    int insertItem(const int&,const float&);    //插入特定位置
    int deleteItem(const float&);               //按值删除
    bool locate(const int&, float&);            //按位查找
    int locate(const float&);                   //按值查找
    void ascendingOrder();                      //升序
    void reverse();                             //倒排
    void print();                               //打印元素
    
};

void merge(linkList&, linkList&);


