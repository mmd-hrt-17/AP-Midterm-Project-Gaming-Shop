#include <iostream>
#include <vector>
#include <string>

using namespace std;

//game class
class Game {
    public:
        string name;
        double price;
        int stock;
        string category;
    };

//shopping cart class
class CartItem {
    public:
        string name;
        int count;
        double fee;
    };

//main store class & settings
class Store {

    //private data
    private:
    Game games[100];
    int gameCount = 0;

    CartItem cart[100];
    int cartCount = 0;

    double cust_wallet = 0, admin_wallet = 0;

    string password = "admin1admin";
    
    //public data
    public:
    void chargeWallet(string rule) {
        double amount;
        if (rule == "admin"){
            cout << "Enter the amount to charge: ";
            cin >> amount;
            admin_wallet += amount;
            cout << "Wallet charged successfully." << endl;
        }
        else if (rule == "cust"){
            cout << "Enter the amount to charge: ";
            cin >> amount;
            cust_wallet += amount;
            cout << "Wallet charged successfully." << endl;
        }
    }

    void addGame(){
        string name;
        label2:
        cout << "Enter game name: ";
        cin.ignore();
        getline(cin, name);
        for (int i = 0; i < gameCount; i++){
            if (games[gameCount].name == name){
                cout << "The name of game is repetition, Enter again" << endl;
                cout << "-------------------------" << endl;
                goto label2;
            }
        }
        games[gameCount].name = name;
        cout << "Enter price: ";
        cin >> games[gameCount].price;
        label1:
        cout << "Enter stock: ";
        cin >> games[gameCount].stock;
        if (games[gameCount].stock <= 0){
            cout << "Enter valid stock(positive & not zero)" << endl;
            cout << "-------------------------" << endl;
            goto label1;
        }
        cout << "Enter category: ";
        cin >> games[gameCount].category;
        gameCount++;
        cout << "Game added successfully." << endl;
    }

    void removeGame() {
        string name;
        cin.ignore();
        cout << "Enter the name of the game you want to remove: ";
        getline(cin, name);
        for (int i = 0; i < gameCount; i++) {
            if (games[i].name == name) {
                for (int j = i; j < gameCount - 1; j++) {
                    games[j] = games[j + 1];
                }
                gameCount--;
                cout << "Game removed." << endl;
                return;
            }
        }
        cout << "Game not found." << endl;
    }

    void searchGame() {
        string name;
        cin.ignore();
        cout << "Enter game name: ";
        getline(cin, name);
        for (int i = 0; i < gameCount; i++) {
            if (games[i].name == name) {
                cout << "Game found: " << games[i].name << ", Price: " << games[i].price << ", Stock: " << games[i].stock << endl;
                return;
            }
        }
        cout << "Game not found." << endl;
    }

    void editGame() {
        int target_game, opr, opr2;
        string name;

        cin.ignore();
        cout << "Enter game name: ";
        getline(cin, name);
        for (int i = 0; i < gameCount; i++) {
            if (games[i].name == name) {
                target_game = i;
            }
            else{
                cout << "Game not found." << endl;
                return;
            }
            cout << "Wich one do you want to edit ?" << endl;
            cout << "1. name | 2. stock | 3. price | 4. category" << endl;
            cin >> opr;
            switch (opr)
            {
            case 1:
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, name);
                cin >> name;
                games[target_game].name = name;
                cout << "Name changed successfully.";
                break;
        
            case 2:
                cout << "1. charge game | 2. set again " << endl;
                cin >> opr2;
                switch (opr2)
                {
                case 1:
                    cout << "Enter stock: ";
                    cin >> opr;
                    games[target_game].stock += opr;
                    cout << "stock chanrged successfully.";
                    break;
                
                case 2:
                    cout << "Enter new stock: ";
                    cin >> opr;
                    games[target_game].stock = opr;
                    cout << "stock changed successfully.";
                    break;
                
                default:
                    cout << "Invalid choice." << endl;
                    break;
                }
                break;
            
            case 3:
                cout << "Enter new price: ";
                cin >> opr;
                games[target_game].price = opr;
                cout << "Price changed successfully.";
                break;

            case 4:
                cout << "Enter new category: ";
                cin >> name;
                games[target_game].category = name;
                cout << "Category changed successfully.";
                break;

            default:
                cout << "Invalid choice." << endl;
            }
        }

    }

    void displayGames() {
        if (gameCount == 0) {
            cout << "No games available." << endl;
            return;
        }
        for (int i = 0; i < gameCount; i++) {
            cout << games[i].name << " | " << games[i].price << " | " << games[i].stock << " | " << games[i].category << endl;
        }
    }

    void displayStockStatus() {
        for (int i = 0; i < gameCount; i++) {
            cout << games[i].name << " - Stock: " << games[i].stock << endl;
        }
    }

    void calculateTotalValue() {
        double total = 0;
        for (int i = 0; i < gameCount; i++) {
            total += games[i].price * games[i].stock;
        }
        cout << "Total value of inventory: " << total << endl;
    }

    void showByCategory() {
        string cat;
        cout << "Enter category: ";
        cin >> cat;
        for (int i = 0; i < gameCount; i++) {
            if (games[i].category == cat) {
                cout << games[i].name << " - Price: " << games[i].price << ", Stock: " << games[i].stock << endl;
            }
        }
    }

    void buyGame() {
        string name;
        int count;
        cin.ignore();
        cout << "Enter game name: ";
        getline(cin, name);
        cout << "Enter quantity: ";
        cin >> count;

        for (int i = 0; i < gameCount; i++) {
            if (games[i].name == name) {
                if (count <= games[i].stock) {
                    double total = count * games[i].price;
                    if (cust_wallet >= total) {
                        cart[cartCount].name = games[i].name;
                        cart[cartCount].count = count;
                        cart[cartCount].fee = games[i].price;
                        cartCount++;
                        cust_wallet -= total;
                        games[i].stock -= count;
                        cout << "Item added to cart." << endl;
                        return;
                    } else {
                        cout << "Insufficient balance. Please charge your wallet." << endl;
                        return;
                    }
                } else {
                    cout << "Insufficient stock. Only " << games[i].stock << " available." << endl;
                    return;
                }
            }
        }
        cout << "Game not found." << endl;
    }

    void showCart() {
        double sum = 0;
        if (cartCount == 0) {
            cout << "Shopping cart is empty." << endl;
            return;
        }

        for (int i = 0; i < cartCount; i++) {
            cout << "Game: " << cart[i].name << ", Count: " << cart[i].count << endl;
            sum += cart[i].count * cart[i].fee;
        }
        cout << "Total: " << sum << endl;
    }

    void adminMenu() {
        string pass;
        cout << "Enter admin password: ";
        cin >> pass;
        if (pass != password) {
            cout << "Incorrect password." << endl;
            return;
        }

        int option;
        while (true) {
            cout << "-------------------------" << endl;
            cout << "(Adminstrator menu)" << endl;
            cout << "Total Credit: " << admin_wallet << endl;
            cout << "1. Add Game" << endl;
            cout << "2. Remove Game" << endl;
            cout << "3. Search Game" << endl;
            cout << "4. Display All Games" << endl;
            cout << "5. Calculate Total Value" << endl;
            cout << "6. Stock Status" << endl;
            cout << "7. Change Password" << endl;
            cout << "8. charge Wallet" << endl;
            cout << "9. edit games data" << endl;
            cout << "10. Exit" << endl;
            cout << "-------------------------" << endl;
            cin >> option;
            switch (option) {
                case 1: 
                    addGame();
                    break;
                case 2: 
                    removeGame(); 
                    break;
                case 3: 
                    searchGame(); 
                    break;
                case 4: 
                    displayGames(); 
                    break;
                case 5: 
                    displayStockStatus(); 
                    break;
                case 6: 
                    calculateTotalValue(); 
                    break;
                case 7: 
                    changePassword(); 
                    break;
                case 8: 
                    chargeWallet("admin"); 
                    break;
                case 9: 
                    editGame();
                    break;
                case 10: 
                    return;
                    
                default: 
                    cout << "Invalid choice." << endl;
            }
        }
    }

    void changePassword() {
        cout << "Enter new password: ";
        cin.ignore();
        getline(cin, password);
        cout << "Password changed." << endl;

    }

    void customerMenu() {
        double cust_amount;
        int opr;
        while (true) {
            cout << "-------------------------" << endl;
            cout << "(Customer menu)" << endl;
            cout << "Total Credit: " << cust_wallet << endl;
            cout << "1. Search Game" << endl;
            cout << "2. Display All Games" << endl;
            cout << "3. Stock Status" << endl;
            cout << "4. Charge Wallet" << endl;
            cout << "5. Search By Category" << endl;
            cout << "6. Buy Games" << endl;
            cout << "7. Show Shopping Cart" << endl;
            cout << "8. Exit" << endl;
            cout << "-------------------------" << endl;
            cin >> opr;
            switch (opr) {
                case 1: 
                    searchGame(); 
                    break;
                case 2: 
                    displayGames(); 
                    break;
                case 3: 
                    displayStockStatus(); 
                    break;
                case 4: 
                    chargeWallet("cust"); 
                    break;
                case 5: 
                    showByCategory(); 
                    break;
                case 6: 
                    buyGame(); 
                    break;
                case 7: 
                    showCart(); 
                    break;
                case 8: 
                    return;
                default: 
                    cout << "Invalid choice." << endl;
            }
        }
    }
};

int main() {

    Store store;
    
    int opr;
    while (true) {
        cout << "-------------------------" << endl;
        cout << "Select access type:" << endl;
        cout << "1. Adminstrator" << endl << "2. Customer" << endl << "3. Turn off" << endl;
        cout << "-------------------------" << endl;
        cin >> opr;
        switch (opr) {
            case 1: 
                store.adminMenu(); 
                break;

            case 2: 
                store.customerMenu(); 
                break;

            case 3: 
                return 0;
            
                default: 
                cout << "Invalid choice." << endl;
        }
    }
}