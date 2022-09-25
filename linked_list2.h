#include "node2.h"

// Linked list of type int
class linked_list2
{
private:
    node2 *head;

public:
    linked_list2()
    {
        head = NULL;
    }

    linked_list2(int val)
    {
        head = new node2(val);
    }

    node2 *gethead()
    {
        return head;
    }

    void sethead(node2 *h1)
    {
        head = h1;
    }

    void insert(int val)
    {
        node2 *ptr = new node2(val);
        node2 *temp = head;
        if (head == NULL)
        {
            head = ptr;
        }
        else
        {
            while (temp->getnext() != NULL)
            {
                temp = temp->getnext();
            }
                    temp->setnext(ptr);
                    ptr->setnext(NULL);
        }
    }

    void display()
    {
        cout << "Displaying LL : " << endl;
        node2 *temp = head;
        while (temp != NULL)
        {
            int temp2 = temp->getdata();
            cout<<temp2<<"\t";
            cout << endl;
            temp = temp->getnext();
        }
    }
};

