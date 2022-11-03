#include<iostream>
using namespace std;

class node
{
    public:
     int data;
     node *next;
};

node *head=NULL;

void insert_at_beginning(int val)
{
    node *new_node=new node();
    new_node->data = val;

    
    if(head==NULL)
    {
        new_node->next = NULL;
        head=new_node;
    }

    else
    {
        new_node->next = head;
        head=new_node;
    }

    cout<<"THE VALUE "<<val<<" IS INSERTED SUCCESSFULLY \n"<<endl;
    
}   

void insert_at_position(int pos, int val)
{
    node *new_node=new node();
    node *temp=head;
    new_node->data=val;


    for(int i=0; i<pos; i++)
    {
         temp = temp->next;

        if(temp==NULL)
        {
            cout<<"SORRY! OUT OF POSITION! \n ENTER CORRECT POSITION:"<<endl;
            return;
        }
    }
    
      new_node->next = temp->next;
      temp->next = new_node;

      cout<<"\nTHE VALUE "<<val<<"IS INSERTED SUCCESSFULLY AT POSITION "<<pos<<endl;

}

void delete_at_position(int pos)
{
    int p=pos;
    node *temp=head;
    node *temp1=NULL;

    for(int i=0; i<p; i++)
    {
         temp = temp->next;
         temp1=temp;

         if(temp==NULL)
        {
            cout<<"SORRY! OUT OF POSITION! \n ENTER CORRECT POSITION:"<<endl;
            return;
        }
    }

    temp1->next = temp->next;
    temp->next=NULL;
    free(temp);     //delete the memory of temp node
   
}

void delete_at_beginning()
{
    node* temp=head;

    head=temp->next;
    free(temp);
}

void display()
{
    node *temp=head;

    if(head==NULL)
    {
        cout<<"\nLINKED LIST IS EMPTY . \n";
        return;
    }

    cout<<endl;
    cout<<"THE VALUE IS : ";

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}

int main()
{
    node *head=NULL;
    int choice,val,pos;

    while(1)
    {
        cout<<"\n----------------------------------\n";
        cout<<"******** LINKED LIST MENU ********";
        cout<<"\n----------------------------------\n";
        cout<<"1. INSERTED AT THE BEGINNING \n";
        cout<<"2. INSERTED AT A SPECIFIC POSITION \n";
        cout<<"3. DELETE AT A SPECIFIC POSITION \n";
        cout<<"4. DISPLAY A VALUE \n";
        cout<<"5. EXIT \n";
        cout<<"\n enter your choice......\n";

        cin>>choice;

    switch (choice)
    {
      case 1:cout<<"ENTER THE VALUE :"<<endl;
             cin>>val;

             insert_at_beginning(val);

             break;

      case 2:cout<<"ENTER THE VALUE :"<<endl;
             cin>>val;

             cout<<"ENTER THE POSITION (starts from 1):"<<endl;
             cin>>pos;

             if(pos==1)
                insert_at_beginning(val);

             else
                insert_at_position(pos,val);

             break;

      case 3:cout<<"ENTER THE POSITION (starts from 1):"<<endl;
             cin>>pos;

             if(pos==1)
                delete_at_beginning();

             else
                delete_at_position(pos);

             break;

      case 4:
             display();
             break;

      case 5:exit(0);
             
      default:cout<<"SORRY! WRONG CHOICE!\nPLEASE ENTER CORRECT CHOICE: "<<endl;

    }

}

    return 0;

}   // first time i wrote a program for 200 lines iam very happy ******* 