#include<iostream>
using namespace std;

// Node for int type
class node2
{
    private:
    int data;
    node2 *next;
    
    public:
    node2()
    {
        data=0;
        next = NULL;
    }

    node2(int val)
    {
        data = val;
        next = NULL;
    }

    void setdata(int val)
    {
        data = val;
    }

    int getdata()
    {
        return data;
    }

    void setnext(node2 *n1)
    {
        next = n1;
    }

    node2 *getnext()
    {
        return next;
    }
};