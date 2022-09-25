#include "node3.h"

// Linked list of type float
class linked_list3
{
private:
    node3*head;

public:
    linked_list3()
    {
        head = NULL;
    }

    linked_list3(float val)
    {
        head = new node3(val);
    }

    node3 *gethead()
    {
        return head;
    }

    void sethead(node3 *h1)
    {
        head = h1;
    }

    void insert(float val)
    {
        node3 *ptr = new node3(val);
        node3 *temp = head;
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
        node3 *temp = head;
        while (temp != NULL)
        {
            int temp2 = temp->getdata();
            cout<<temp2<<"\t";
            cout << endl;
            temp = temp->getnext();
        }
    }
};

