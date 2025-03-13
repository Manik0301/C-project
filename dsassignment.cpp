#include <bits/stdc++.h>
using namespace std;
struct ll
{
    int data;
    ll *ptr;
};
ll *cnode(int value)
{
    ll *ptr1 = new ll;
    ptr1->data = value;
    ptr1->ptr = nullptr;
    return ptr1;
}
ll *cll(ll *head)
{
    int value;
    cout << "enter value of the linked list:" << endl;
    cin >> value;
    ll *ptr1 = cnode(value);
    if (head == nullptr)
    {
        head = ptr1;
    }
    else
    {
        ll *ptr2 = nullptr;
        ptr2 = head;
        while (ptr2->ptr != nullptr)
        {
            ptr2 = ptr2->ptr;
        }
        ptr2->ptr = ptr1;
        ptr2 = ptr2->ptr;
    }
    return head;
}
ll *delatb(ll *&head)
{
    ll *ptr5 = head;

    if (head == nullptr)
    {
        cout << endl;
    }
    else
    {
        head = head->ptr;
        delete ptr5;
    }
    return head;
}
ll *dll(ll *&head)
{
    long int sum = 0;
    int even = 0, odd = 0;
    if (head == nullptr)
    {
        cout << "no linked list created:" << endl;
    }
    else
    {
        ll *ptr3 = nullptr;
        ptr3 = head;
        cout << "linked list is:" << endl;
        while (ptr3->ptr != nullptr)
        {
            cout << ptr3->data << " ";
            if ((ptr3->data) % 2 == 0)
            {
                even++;
            }
            else
            {
                odd++;
            }
            sum += ptr3->data;
            ptr3 = ptr3->ptr;
        }
        cout << ptr3->data << " " << endl;
        if ((ptr3->data) % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
        sum += ptr3->data;
        ptr3 = ptr3->ptr;
        cout << "sum of all the elements in linked list is:" << sum << endl;
        cout << "at the ASCII code" << " " << sum << " "<< "is:"<< " " << char(sum) << endl;
        cout << "number of even elements are:" << even << endl;
        cout << "number of odd elements are:" << odd << endl;
    }
    return head;
}
ll *insatb(ll *&head)
{
    int value;
    cout << "enter value of this link node:" << endl;
    cin >> value;
    if (head != nullptr)
    {
        ll *ptr4 = cnode(value);
        ptr4->ptr = head;
        head = ptr4;
    }
    return head;
}
ll *insatspe(ll *&head)
{
    int location;
    cout << "enter the location at which you want to insert element:" << endl;
    cin >> location;
    if (location <= 0 || head == nullptr)
    {
        cout << "invalid location" << endl;
    }
    else if (location == 1 || head == nullptr)
    {
        insatb(head);
    }
    else if (location > 1)
    {
        int value;
        cout << "enter the value of new node link:" << endl;
        cin >> value;
        ll *ptr6 = cnode(value);
        ll *ptr7 = head;
        for (int i = 1; i < location - 1 && ptr7->ptr != nullptr; i++)
        {
            ptr7 = ptr7->ptr;
        }
        ptr6->ptr = ptr7->ptr;
        ptr7->ptr = ptr6;
    }
    return head;
}
ll *insatend(ll *&head)
{
    int value;
    cout << "enter the value to insert at the end of the linked list:" << endl;
    cin >> value;
    ll *ptr8 = head;
    ll *ptr1 = cnode(value);
    if (head == nullptr)
    {
        head = ptr1;
    }
    while (ptr8->ptr != nullptr)
    {
        ptr8 = ptr8->ptr;
    }
    ptr8->ptr = ptr1;
    return head;
}
ll *delatend(ll *&head)
{
    ll *ptr9 = head;
    if (head == nullptr)
    {
        cout << "no link list to delete:" << endl;
    }
    if (head->ptr == nullptr)
    {
        delete head;
        return NULL;
    }
    while (ptr9->ptr->ptr != nullptr)
    {
        ptr9 = ptr9->ptr;
    }
    ptr9->ptr = nullptr;
    return head;
}
ll *delatspe(ll *&head)
{
    ll *ptr10 = head;
    ll *ptr11 = head;
    int location;
    cout << "enter the position at which you want to delete an element:" << endl;
    cin >> location;
    if (location <= 0)
    {
        cout << "invalid position" << endl;
    }
    if (location > 0)
    {
        if (location == 1 || head == nullptr)
        {
            delatb(head);
        }
        for (int i = 1; i < location; i++)
        {
            ptr10 = ptr10->ptr;
            if (ptr10->ptr == nullptr)
            {
                delatend(head);
                dll(head);
                break;
            }
        }
        for (int i = 1; i < location - 1; i++)
        {
            ptr11 = ptr11->ptr;
        }
        ptr11->ptr = ptr10->ptr;
        delete ptr10;
    }
    return head;
}
ll *sanele(ll *&head)
{
    int element = 0;
    int count = 1;
    cout << "enter the element you want to search in linked list:" << endl;
    cin >> element;
    ll *ptr12 = head;
    if (ptr12->data == element)
    {
        cout << "element found at " << count << " position in the link list." << endl;
    }
    count++;
    while (ptr12->ptr != nullptr)
    {
        ptr12 = ptr12->ptr;
        if (ptr12->data == element)
        {
            cout << "element is found at " << count << " " << "position" << endl;
            count++;
        }
        count++;
    }
    if (ptr12->data != element)
    {
        cout << "element not found in the list." << endl;
    }

    ptr12 = ptr12->ptr;
    if (ptr12->data == element)
    {
        cout << "element " << element << " found at " << count << " "
             << "position" << endl;
    }
    else if (ptr12->data != element)
    {
        cout << "element not present in the link list" << endl;
    }
    return head;
}

ll *reverseLinkedList(ll *&head) {
    if (head == nullptr || head->ptr == nullptr) {
        return head; // No need to reverse if the list is empty or has only one element.
    }
 else{
    ll *prev = nullptr;
    ll *current = head;
    ll *nextNode = nullptr;
  
     
     while (current != nullptr) {
        nextNode = current->ptr; // Store the next node.
        current->ptr = prev; // Reverse the link.
        prev = current; // Move prev and current one step forward.
        current = nextNode;
    }

    head = prev;
    } // Update the new head of the reversed list.
    return head;
}

int main()
{
   ll *head = nullptr;
    int n;
    cout << "enter the limit of the linked list:" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        head = cll(head);
    }
    cout << " The linked list is:" << endl;
    dll(head);
    int choice;
    do
    {
        cout << "--------MENU OPTIONS--------" << endl;
        cout << "1. INSERT ELEMENT AT THE BEGINNING OPERATION" << endl;
        cout << "2. INSERT ELEMENT AT SPECIFIC POSITION IN LINKED LIST" << endl;
        cout << "3. INSERT ELEMENT AT THE END OF THE LINKED LIST" << endl;
        cout << "4. DELETE ELEMENT AT THE BEGINNING OF THE LINKED LIST" << endl;
        cout << "5. DELETE ELEMENT AT A SPECIFIC POSITION IN THE LINKED LIST" << endl;
        cout << "6. DELETE THE LAST ELEMENT OF THE LINKED LIST" << endl;
        cout << "7. SEARCH WHETHER AN ELEMENT IS PRESENT IN LINKED LIST OR NOT" << endl;
        cout << "8. DISPLAY THE ELEMENTS OF THE LINKED LIST" << endl;
        cout << "9. DELETE THE LINKED LIST AND CREATE NEW ONE" << endl;
        cout << "10. EXIT THE PROGRAM" << endl;
        cout << endl;
        cout << "ENTER YOUR CHOICE" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            insatb(head);
            dll(head);
            break;
        case 2:
            insatspe(head);
            dll(head);
            break;
        case 3:
            insatend(head);
            dll(head);
            break;
        case 4:
            delatb(head);
            dll(head);
            break;
        case 5:
            delatspe(head);
            dll(head);
            break;
        case 6:
            delatend(head);
            dll(head);
            break;
        case 7:
            sanele(head);
            break;
        case 8:
            dll(head);
            break;
        case 9:
            char ch;
            cout << "ARE YOU SURE YOU WANT TO DELETE THE EXISTING LINKED LIST(Y,y/N,n):" << endl;
            cin >> ch;
            if (ch == 'y' || ch == 'Y')
            {
                delete head;
                main();
            }
            else
            {
                return 0;
            }
            break;
        case 10:
           reverseLinkedList(head);
           dll(head);
           break;    
        case 11:
            cout << "ENDING THE PROGRAM" << endl;
            exit(1);
            cout << endl;
            break;
        default:
            cout << "\t INVALID CHOICE: \t" << endl;
            break;
        }

    } while (choice != 11);
    return 0;
}
