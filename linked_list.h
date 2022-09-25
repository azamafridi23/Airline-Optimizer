#include "node.h"

// Linked list of type vectors
class linked_list
{
private:
    node *head;

public:
    linked_list()
    {
        head = NULL;
    }

    linked_list(vector<int> path1)
    {
        head = new node(path1);
    }

    node *gethead()
    {
        return head;
    }

    void sethead(node *h1)
    {
        head = h1;
    }

    void insert(vector<int> p1)
    {
        node *ptr = new node(p1);
        node *temp = head;
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
        node *temp = head;
        while (temp != NULL)
        {
            vector<int> temp2 = temp->getdata();
            for (int i = 0; i < temp2.size(); i++)
            {
                cout << temp2[i] << "\t";
            }
            cout << endl;
            temp = temp->getnext();
        }
    }
};

