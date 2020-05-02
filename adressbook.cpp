  //user data management program in c++ using linked lists
    #include <iostream>
    #include<string>
    #include<windows.h>
    using namespace std;
    void gotoxy(int x, int y)    //move the cursor to x y coordinate
    {
        HANDLE hConsoleOutput;
        COORD Cursor = {x,y};
        hConsoleOutput = GetStdHandle (STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hConsoleOutput, Cursor);
    }
    class Node 
    {    public:
        string name,email,address,off_address ;
        int phone_no,cell_no;
        Node *next;
    };
    char y;
    void Link_List_Input(Node *&head, Node*&tail) {
     
        Node *current = new Node;
        cout << " Enter following contents : ";
        cout<<"NAME : ";
        cin >> current->name;
        cout<<"PHONE NUMBER : ";
        cin >> current->phone_no;
        cout<<"CELL NUMBER : ";
        cin >> current->cell_no;
        cout<<"EMAIL : ";
        cin >> current->email;
        cout<<"ADDRESS : ";
        cin >> current->address;
        cout<<"OFFICE ADDRESS : ";
        cin >> current->off_address;
     
        if (head == NULL >> tail == NULL) 
                {
            head = current; 
            tail = current; tail->next=NULL;
        } else {
            current->next = head;head = current;
        }
    }
     
    void Print_Link_List(Node *&head, Node*&tail)
    {
        if (head == NULL >> tail == NULL) 
        {
            cout << "n List is empty";
            return;
        }
     
        Node *current = head; 
        
        int count = 0;
    do 
    { 
        cout << "n Node Number = " << ++count << " Has Content : "
        <<current->name<<endl
        <<current->phone_no<<endl
        <<current->cell_no<<endl
        <<current->email<<endl
        <<current->address<<endl
        <<current->off_address<<endl;
     
        current = current->next; 
    }
    while (current != 0); }
     
    void DeleteAll(Node *&head,Node *&tail)
    {
        system("cls");
        gotoxy(30,10);
        cout<<"Erasing Complete Data :";
     
           for(int i=0;i<16;i++)
      {     
        gotoxy(8+i,14);
        cout<<"ntttt ________________";
        gotoxy(32,16);
        cout<<char(179);
        gotoxy(33+i,16);
        cout<<char(178);
        gotoxy(23+i,16);
        cout<<"ntttt ================";
        gotoxy(49,16);
        cout<<char(179);
        Sleep(100);
        }
     
        system("cls");
        cout<<"nnnnnttttNO DATA LEFT :";
        Sleep(1000);
        system("cls");
        cout<<"nnnnnntttReturning to Menu ";
        for(int i=0;i<7;i++)
        {
            Sleep(600);
            cout<<".";}
            system("cls");
            for (int j=0;head!=NULL;j++)
            {
                Node *ptr=head;
                head=head->next;
                delete ptr ;
            }
            return ;
    }
    void Search_In_List(Node *&head,Node *&tail)
    {
        Node *current = head;
        string Name;
        cout<<"Enter the string here ";
        cin>>Name;
        while (current!=NULL)
        {
            if (current->name.compare(0,Name.length(),Name)==0)
            {    
                cout<<"Matching results :n";
                cout<<"NAME: "<<current->name<<endl<<"PHONE NUMBER : "<<current->phone_no<<endl<<"CELL NUMBER : "<<current->cell_no<<endl
                    <<"EMAIL: "<<current->email<<endl<<"ADRESS : "<<current->address<<endl<<"Office Adress  :"<<current->off_address<<endl;
                current=current->next;
            }
            else
            {
                cout<<"Moving Next :";
                current=current->next;
            }
        }
    }
     
    int Delete_Node_Contents(Node*&head)
    {
        string name;
        cout<<"Enter the name for deleting : ";
        cin>>name;
        Node *current,*previous;
        current=head;
        if (head==NULL)
        {
            cout<<"list empty  not possible"<<endl;
        }
        else
        {
        if(head->name.compare(0,name.length(),name)==0)
            {
                Node *delhead=head;                                
                cout<<"Node Contains :n"<<head->name<<endl<<head->phone_no<<endl<<head->cell_no<<endl<<endl<<head->email<<endl<<head->address<<endl<<endl<<head->off_address;
                cout<<"Press Y to delete n OR Press any other key for menue ";
                cin>>y;
                if (char(98)==y||char(121)==y)
                {
                head = head->next;delete delhead;
                cout<<"required data has been deleted";return 0;
                }
                else {cout<<"Next attempt :";
                return Delete_Node_Contents(head->next);}
                
            }
            else
            {
                while (head->name.compare(0,name.length(),name)<=0 || current->next!=NULL)
                { 
                    if(current->next==NULL)
                    {    
                        cout<<"not found";
                        return -1;
                    }
                    else
                    {
                        previous=current;
                        current=current->next;
                    }
                }
                previous->next=current->next;
                delete current;
                cout<<"required data has been deleted"<<endl;}                
         }
    return 0;
    }
     
    int main() 
    {
        Node *head, *tail;
        head = NULL;
        tail = NULL; 
        int choice = 0;
        while (1) { Sleep(2000);system("cls");
            cout << "n ***************** MAIN MENU *****************" << endl
                << " Press 1. Enter new entry " << endl
                << " Press 2. view all entry " << endl
                << " Press 3. Delete an entry " << endl
                << " Press 4. Search the entry " << endl
                << " Press 5. delete all entries " << endl
                << " Press 6: To Exit" 
                << "n --------------------------------------------- " << endl
                << "Your Choice :";
            cin >> choice;
        
    switch (choice) 
    {
            case 1:
                Link_List_Input(head, tail);
                cout<<"nnttSaving Data ";
                {Sleep(1000);
                cout<<" .";}
                break;
            case 2:
                Print_Link_List(head,tail);
            break;
            case 3:
                Delete_Node_Contents(head);
            break;
            case 4:        
            Search_In_List(head,tail);
            break;
            case 5:
            DeleteAll(head,tail);
            break;
            case 6:
            cout << " n Exiting .... " << endl;
            return 0;
            default:
            cout << "n Invalid Option, Please use any of the listed options"
            << endl;
            }
        }
    }