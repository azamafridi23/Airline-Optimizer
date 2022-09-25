#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Node of type vector
// Node class to store Paths.
// Each node will consist of a vector to store a path.
class node
{
private:
    vector<int> data;
    node *next;

public:
    node()
    {
        next = NULL;
    }

    node(vector<int> path1)
    {
        data = path1;
        next = NULL;
    }

    void setdata(vector<int> path1)
    {
        data = path1;
    }

    vector<int> getdata()
    {
        return data;
    }

    void setnext(node *n1)
    {
        next = n1;
    }

    node *getnext()
    {
        return next;
    }
};