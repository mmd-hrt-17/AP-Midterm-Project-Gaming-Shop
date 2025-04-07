#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct Game {
    string name;
    double price;
    int stock;
    string category;
};

struct shoppingcart {
    string name;
    int count;
    double fee;
};

double customer_amount = 0;
double admin_amount = 0;

vector<Game> games;
vector<shoppingcart> shopping_cart;

string PASSWORD = "admin1admin";


void add(const string& name, const double& price, const int& stock, const string& cat) {
    Game newGame = {name, price, stock, cat}; 
    games.push_back(newGame); 
}


void remove(const string& name) {
    for (int i = 0; i < games.size(); ++i) { 
        if (games[i].name == name) { 
            games.erase(games.begin() + i); 
            return; 
        } 
    } 
    cout << "The specified game was not found." << endl;
}


void search(const string& name) {
    for (int i = 0; i < games.size(); ++i) {
        if (games[i].name == name) {
            cout << "Game name: " << games[i].name << ", Price: " << games[i].price << ", Stock: " << games[i].stock << endl;
            return;
        }
    }
    cout << "The specified game was not found." << endl;
}


void stockStatus () {
    if (games.size() != 0){
        for (int i = 0; i < games.size(); ++i) {
            cout << "Game name: " << games[i].name << ", Stock: " << games[i].stock << endl;
        }
    }
    else {
        cout << "The stock is empty." << endl;
    }
}


void displayall() {
    if (games.size() != 0){
        for (int i = 0; i < games.size(); ++i) {
            cout << "Game name: " << games[i].name << ", Price: " << games[i].price;
            cout << ", Stock: " << games[i].stock << ", Category: " << games[i].category << endl;
        }
    }
    else{
        cout << "The stock is empty." << endl;
    }
}


double calcvalue() {
    double totalValue = 0;
    for (int i = 0; i < games.size(); ++i) {
        totalValue += games[i].price * games[i].stock;
    }
    return totalValue;
}


string password (const string& pass){
    if (pass == PASSWORD){
        return "correct";
    }
    else {
        return "wrong";
    }
}


void changepass (){
    cout << "Your current password: " << PASSWORD << endl;
    cout << "Please enter the new password: " << endl;
    getline(cin,PASSWORD);
    cout << "Your password successfully changed." << endl;
}


int cont (){
    int cmd;
    cout << "If you want to continue, enter (1), otherwise press any number: ";
    cin >> cmd;
    if (cmd == 1){
        return 1;
    }
    else{
        return 2;
    }
}


void charge(int sts){
    double amount;
    cout << "Enter the desire amount: ";
    cin >> amount;
    if (sts == 1){
        customer_amount += amount;
        cout << "Your wallet charged successfully." << endl;
    }
    else{
        admin_amount += amount;
        cout << "Your wallet charged successfully." << endl;
    }
}


void ShowByCat(string& cat){
    if (games.size() != 0){
        for (int i = 0; i < games.size(); ++i) {
            if (games[i].category == cat){
                cout << "Game name: " << games[i].name << ", Price: " << games[i].price;
                cout << ", Stock: " << games[i].stock << endl;
            }
            else {
                cout << "There is no game in " << cat << "category." << endl;
            }
        }
    }
    else{
        cout << "The stock is empty." << endl;
    }
}


void AddShoppingCart(){
    
    string gn;
    int st,target;
    double totalValue;

    cout << "Enter game name: ";

    cin.ignore();
    getline(cin,gn);

    cout << "How many do you want? ";

    cin >> st;

    for (int i=0; i < games.size(); ++i){
        if (games[i].name == gn){

            totalValue += games[i].price * st;

            if (st > games[i].stock){
                cout << "We don't have as much stock as you want , We only have "<< games[i].stock << " in stock." << endl;
            }

            else if (customer_amount < totalValue){
                cout << "Charge your wallet first, Then start shopping." << endl;
            }

            else {
                shoppingcart newgame = {games[i].name,st,games[i].price};
                shopping_cart.push_back(newgame);
                games[i].stock -= st; 
                customer_amount -= totalValue;
                cout << "Your order has been added successfully." << endl;
            }
        }
    }    
}

void ShowShoppingCart(){

    int total = 0;

    if (shopping_cart.size() != 0){
        for (int i = 0; i < shopping_cart.size(); ++i) {
            cout << "Game name: " << shopping_cart[i].name << ", count: " << shopping_cart[i].count << endl;
        }

        for (int j = 0; j < shopping_cart.size(); ++j) {
            total += ((shopping_cart[j].fee)*(shopping_cart[j].count)) ;
        }
        cout << "Total price: " << total << endl;
    }

    else{
        cout << "The stock is empty." << endl;
    }
}

void admin_menu() {
    while (true) {
        cout << "-------------------------" << endl;
        cout << "(Adminstrator menu)" << endl;
        cout << "Total Credit: " << admin_amount << endl;
        cout << "1. Add Game" << endl;
        cout << "2. Remove Game" << endl;
        cout << "3. Search Game" << endl;
        cout << "4. Display All Games" << endl;
        cout << "5. Calculate Total Value" << endl;
        cout << "6. Stock Status" << endl;
        cout << "7. Change Password" << endl;
        cout << "8. charge Wallet" << endl;
        cout << "9. Exit" << endl;
        cout << "-------------------------" << endl;
        
        int choice, command;
        cin >> choice;

        string name;
        double price;
        int stock;
        string category;
        
        switch (choice) {
            case 1:
                label1:
                cout << "Game name: ";
                cin.ignore();
                getline(cin,name);
                cout << "Price: ";
                cin >> price;
                cout << "Stock: ";
                cin >> stock;
                cout << "Category: ";
                cin >> category;
                add(name, price, stock, category);
                command = cont();
                if (command == 1){
                    goto label1;
                }
                else{
                    break;
                }

            case 2:
                label2:
                cout << "Game name: ";
                cin.ignore();
                getline(cin,name);
                remove(name);
                command = cont();
                if (command == 1){
                    goto label2;
                }
                else{
                    break;
                }

            case 3:
                label3:
                cout << "Game name: ";
                cin.ignore();
                getline(cin,name);
                search(name);
                command = cont();
                if (command == 1){
                    goto label3;
                }
                else{
                    break;
                }

            case 4:
                displayall();
                break;

            case 5:
                cout << "Total value of games: " << calcvalue() << endl;
                break;

            case 6:
                cout << "The status of game stock: " << endl ;
                stockStatus(); 
                break;

            case 7:
                changepass();
                break;

            case 8:
                charge(2);
                command = cont();
                if (command == 1){
                    goto label1;
                }
                else{
                    break;
                }

            case 9:
                return;

            default:
                cout << "Invalid choice" << endl;
        }
    }
}

void customer_menu() {
    while (true) {
        cout << "-------------------------" << endl;
        cout << "(Customer menu)" << endl;
        cout << "Total Credit: " << customer_amount << endl;
        cout << "1. Search Game" << endl;
        cout << "2. Display All Games" << endl;
        cout << "3. Stock Status" << endl;
        cout << "4. Charge Wallet" << endl;
        cout << "5. Search By Category" << endl;
        cout << "6. Buy Games" << endl;
        cout << "7. Show Shopping Cart" << endl;
        cout << "8. Exit" << endl;
        cout << "-------------------------" << endl;
        
        int choice, command;
        cin >> choice;

        string name,category;
        double price;
        int stock;

        switch (choice) {
            case 1:
                label1:
                cout << "Game name: ";
                cin.ignore();
                getline(cin,name);
                search(name);
                command = cont();
                if (command == 1){
                    goto label1;
                }
                else{
                    break;
                }

            case 2:
                displayall();
                break;

            case 3:
                cout << "The status of game stock: " << endl ;
                stockStatus(); 
                break;

            case 4:
                charge(1);
                command = cont();
                if (command == 1){
                    goto label1;
                }
                else{
                    break;
                }

            case 5:
                cout << "Enter your desire category: ";
                cin >> category;
                ShowByCat(category);
                command = cont();
                if (command == 1){
                    goto label1;
                }
                else{
                    break;
                }

            case 6:
                AddShoppingCart();
                command = cont();
                if (command == 1){
                    goto label1;
                }
                else{
                    break;
                }

            case 7:
                ShowShoppingCart();
                break;

            case 8:
                return;

            default:
                cout << "Invalid choice" << endl;
        }
    }

}

int main() {

    int opr;
    string status,pass;

    label1:
    cout << "-------------------------" << endl;
    cout << "Select access type:" << endl;
    cout << "1. Adminstrator" << endl << "2. Customer" << endl << "3. Turn off" << endl;
    cout << "-------------------------" << endl;

    cin >> opr;
    switch (opr)
    {
    case 1:
        cout << "Please enter the password :" << endl;
        cin >> pass;
        status = password(pass);
        if (status == "correct"){
            admin_menu();
            goto label1;
        }
        else {
            cout << "Wrong password." << endl << "-------------------------" << endl;
            goto label1;
        } 
        break;
    
    case 2:
        customer_menu();
        goto label1;
        break;

    case 3:
        return 0;

    default:
        cout << "Please select available choice.";
        break;
    }
}