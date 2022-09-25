#include "linked_list.h"

class queue1
{
private:
    node *front;
    node *rear;

public:
    queue1()
    {
        front = NULL;
        rear = NULL;
    }
    void enqueue(vector<int> x)
    {
        node *ptr = new node;
        if (ptr == NULL)
        {
            // cout << "Queue full" << endl;
        }
        else
        {
            if (rear == NULL)
            {
                ptr->setdata(x);
                ptr->setnext(NULL);
                front = rear = ptr;
            }
            else
            {
                ptr->setdata(x);
                ptr->setnext(NULL);
                rear->setnext(ptr);
                rear = ptr;
            }
        }
    }

    vector<int> dequeue()
    {
        vector<int> x;
        if (front == NULL)
        {
            // cout << "Queue is empty!" << endl;
        }
        else
        {
            node *temp = front;
            front = front->getnext();
            if (front == NULL)
            {
                rear = NULL;
            }
            x = temp->getdata();
            temp->setnext(NULL);
            free(temp);
        }
        return x;
    }

    int empty()
    {
        if (front == NULL)
        {
            return 1;
        }
        return 0;
    }

    // void display()
    // {
    //     node *temp=front;
    //     while(temp!=NULL)
    //     {
    //         int x=temp->getdata();
    //         cout<<x<<"\t";
    //         temp=temp->getnext();
    //     }
    //     cout<<endl;
    // }
};
