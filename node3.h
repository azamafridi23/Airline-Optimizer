#include<iostream>
using namespace std;

// Node for float type
class node3
{
    private:
    float data;
    node3 *next;
    
    public:
    node3()
    {
        data=0;
        next = NULL;
    }

    node3(float val)
    {
        data = val;
        next = NULL;
    }

    void setdata(float val)
    {
        data = val;
    }

    int getdata()
    {
        return data;
    }

    void setnext(node3 *n1)
    {
        next = n1;
    }

    node3 *getnext()
    {
        return next;
    }
};