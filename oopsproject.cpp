#include<iostream>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

class Item {
public:
    int id;
    string name;
    float price;
    int quantity;
};

class OnlineShoppingSystem {
public:
    Item item;
    ifstream f1;
    ofstream f2;

public:
    void displayMenu() {
        char choice;
        while (true) {
            cout << "********** |MAIN MENU| ***********" << endl;
            cout << "Please enter your choice for the menu:" << endl;
            cout << "1. ADMIN" << endl;
            cout << "2. CUSTOMER" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case '1':
                    adminMenu();
                    break;
                case '2':
                    customerMenu();
                    break;
                case '3':
                    exit(1);
                default:
                    cout << "Incorrect Input" << endl;
                    cout << "Press any key to continue";
                    cin.ignore();
                    cin.get();
                    break;
            }
        }
    }

    void adminMenu() {
        int choice;
        string name="krishnam";
        string password="admin123";
        string admin;
        cout<<"Enter the admin name:"<<endl;
        cin>>admin;
        string pass;
        cout<<"Enter the password:"<<endl;
        cin>>pass;
        if((name==admin) && (password==pass))
        {
        while (true) {
            
            cout << "******* ADMIN SCREEN *******" << endl;
            cout << "1. Add an Item" << endl;
            cout << "2. Display Items" << endl;
            cout << "3. Search an Item" << endl;
            cout << "4. Update Items" << endl;
            cout << "5. Delete an Item" << endl;
            cout << "6. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addItem();
                    break;
                case 2:

                    displayItems();
                    break;
                case 3:
                    
                    searchItem();
                    break;
                case 4:
                    
                    updateItem();
                    break;
                case 5:
            
                    deleteItem();
                    break;
                case 6:
                    return ;
                    break;
                default:
                    
                    cout << "Incorrect Input" << endl;
                    cout << "Press any key to continue";
                    cin.ignore();
                    cin.get();
                    break;
            }
        }
    }
    }
    

    void addItem() {
        cout << "Add Item You Want to Add" << endl;
        cout << "Enter the ID of the item: ";
        cin >> item.id;
        cout << "Enter the item you want to add: ";
        cin.ignore();
        getline(cin, item.name);
        cout << "Enter the price of the given item: ";
        cin >> item.price;
        cout << "Enter the quantity of the given item: ";
        cin >> item.quantity;
        
        f2.open("file.txt", ios::app| ios::out | ios::binary);
        if (f2) {
            f2.write(reinterpret_cast<char*>(&item), sizeof(item));
            f2.close();
            cout << "Item added successfully!" << endl;
        }
        else {
            cout << "Error opening file." << endl;
        }

        cout << "Do you want to add more items? (1 for Yes, 2 for No): ";
        int choice;
        cin >> choice;
        if (choice != 2) {
            addItem();
        }
    }

    void displayItems() {
        f1.open("file.txt", ios::binary|ios::in);
        if (f1) {
            cout << "ID\tNAME\t\t\tPRICE\t\tQUANTITY" << endl;
            while (f1.read(reinterpret_cast<char*>(&item), sizeof(item))) {
                cout<<left;
                cout.width(8);
                cout << item.id ;
                
                cout<<left;
                cout.width(24);
                
                
                cout<< item.name;
                cout<<left;
                cout.width(16);
                
                
                cout<<item.price;
                cout<<left;
                cout.width(14);
                
                cout<<item.quantity << endl;
            }
            f1.close();
        }
        else {
            cout << "Error opening file." << endl;
        }

        cout << "Press any key to continue";
        cin.ignore();
        cin.get();
    }

    void searchItem() {
        int id, flag = 0;
        cout << "SEARCH ITEMS..." << endl;
        cout << "Enter ID of the item: ";
        cin >> id;

        f1.open("file.txt", ios::binary|ios::in);
        if (f1) {
            while (f1.read(reinterpret_cast<char*>(&item), sizeof(item))) {
                if (item.id == id) {
                    flag = 1;
                    cout << "Name of item: " << item.name << endl;
                    cout << "Price of item: " << item.price << endl;
                    cout << "----------------------------------------" << endl;
                 //   cout<<" ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
                }
            }
            f1.close();
        }
        else {
            cout << "Error opening file." << endl;
        }

        if (!flag) {
            cout << "Record not found" << endl;
        }

        cout << "Press any key to continue";
        cin.ignore();
        cin.get();
    }

    void deleteItem() {
        int id, flag = 0;
        cout << "DELETE ITEM" << endl;
        cout << "Enter ID of the item you want to delete: ";
        cin >> id;

        f1.open("file.txt", ios::binary|ios::in);
        f2.open("file2.txt", ios::binary | ios::app| ios::out);

        if (f1 && f2) {
            while (f1.read(reinterpret_cast<char*>(&item), sizeof(item))) {
                if (item.id == id) {
                    flag = 1;
                }
                else {
                    f2.write(reinterpret_cast<char*>(&item), sizeof(item));
                }
            }
            f1.close();
            f2.close();

            if (flag) {
                remove("file.txt");
                rename("file2.txt", "file.txt");
                cout << "Item deleted successfully" << endl;
            }
            else {
                cout << "Item not found" << endl;
            }
        }
        else {
            cout << "Error opening files." << endl;
        }

        cout << "Press any key to continue";
        cin.ignore();
        cin.get();
    }

    void updateItem() {
        int id, flag = 0;
        cout << "UPDATE ITEM" << endl;
        cout << "Enter ID to update: ";
        cin >> id;

        f1.open("file.txt", ios::binary|ios::in);
        f2.open("file2.txt", ios::binary | ios::out|ios::app);

        if (f1 && f2) {
            while (f1.read(reinterpret_cast<char*>(&item), sizeof(item))) {
                if (item.id == id) {
                    flag = 1;
                    cout << "Name of ID: " << item.name << "\tPrice of ID: " << item.price << endl;
                    cout << "Enter the new name: ";
                    cin.ignore();
                    getline(cin, item.name);
                    cout << "Enter new price: ";
                    cin >> item.price;
                    cout<<"Enter new quantity: ";
                    cin>>item.quantity;
                }
                f2.write(reinterpret_cast<char*>(&item), sizeof(item));
            }
            f1.close();
            f2.close();

            if (flag) {
                remove("file.txt");
                rename("file2.txt", "file.txt");
                cout << "Item updated successfully" << endl;
            }
            else {
                cout << "Item not found" << endl;
            }
        }
        else {
            cout << "Error opening files." << endl;
        }

        cout << "Press any key to continue";
        cin.ignore();
        cin.get();
    }

    void customerMenu() {
        int choice;
        while (true) {
            cout << "******* CUSTOMER SCREEN *******" << endl;
            cout << "1. Display Items" << endl;
            cout << "2. Search Items" << endl;
            cout << "3. Purchase Items" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    displayItems();
                    break;
                case 2:
                    searchItem();
                    break;
                case 3:
                    purchaseItem();
                    break;
                case 4:
                    return;
                    break;
                default:
                    cout << "Incorrect Input" << endl;
                    cout << "Press any key to continue";
                    cin.ignore();
                    cin.get();
                    break;
            }
        }
    }

    void purchaseItem() {
        int id, quantity;
        float total_amount = 0;
        cout << "PURCHASE ITEM" << endl;
        cout << "Enter the ID of the item: ";
        cin >> id;
        cout << "Enter the quantity of item: ";
        cin >> quantity;

        f1.open("file.txt", ios::binary|ios::in);
        if (f1) {
            while (f1.read(reinterpret_cast<char*>(&item), sizeof(item))) {
                if (item.id == id) {
                    total_amount = item.price * quantity;
                    cout << "BILL" << endl;
                    cout << "Name of item: " << item.name << endl;
                    cout << "Quantity Sold: " << quantity << endl;
                    cout << "Total Amount: " << total_amount << endl;
                }
            }
            f1.close();
        }
        else {
            cout << "Error opening file." << endl;
        }

        cout << "Press any key to continue";
        cin.ignore();
        cin.get();
    }
};

int main() {
    OnlineShoppingSystem system;
    system.displayMenu();
    return 0;
}

