#include<bits/stdc++.h>
using namespace std;

class LinkedList
{
    struct node
    {
        int data;
        node *next;
        node(int d)
        {
            data = d;
            next = NULL;
        }
    };
    node *head,*tail;

    public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void insertAtBeginning(int data)
    {
        node *Newnode = new node(data);
        if(head == NULL)
        {
            head = Newnode;
            tail = Newnode;
        }
        else
        {
            Newnode->next = head;
            head = Newnode;
        }

    }
    void insertAtEnd(int data)
    {
        node *Newnode = new node(data);
        if(head == NULL)
        {
            head = Newnode; 
            tail = head; 
        }
        else
        {
            tail->next = Newnode;
            tail = tail->next;
        }
    }
    void insertAt_K_position(int k,int data)
    {
        node *Newnode = new node(data);
        if(head == NULL)
        {
            cout << "List is empty"<<endl;
        }
        if(k == 0)
        {
            Newnode->next=head;
            head = Newnode;
        }
        else
        {
            node *current = head;
            while(current != NULL && --k)
            {
                current = current->next;
            }
            if(k == 0)
            {
                Newnode->next = current->next;
                current->next = Newnode;

            }
            else
            {
                cout << "position doesn't exsit" << endl;
            }
        }

    }
    void print()
    {
        if(head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        else
        {
            node *current = head;
            while (current!=NULL)
            {
                cout << current->data<<" -> ";
                current = current->next;
            }
            cout <<"NULL" << endl;
        }
    }
    void deleteNode(int data)
    {
        node *current = head;
        if(head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else if(head->data == data)
        {
            head = head->next;
            free(current);
            return;
        }
        else
        {
            while(current->next != NULL && current->next->data != data)
            {
                current = current->next;
            }
            if(current->next == NULL)
            {
                cout << "Data doesn't exist" << endl;
                return;
            }
            else
            {
                node *temp = current->next;
                current->next = current->next->next;
                free(temp);
            }
        }
    }
};

int main()
{
    LinkedList ll = LinkedList();
    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtEnd(30);
    ll.insertAtBeginning(90);
    ll.insertAtBeginning(100);
    ll.deleteNode(100);
    ll.print();
    ll.insertAt_K_position(2,80);
    ll.print();

}