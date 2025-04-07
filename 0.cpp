#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Game {
    public:
        string name;
        double price;
        int stock;
        string category;
    };
    
class CartItem {
    public:
        string name;
        int count;
        double fee;
    };

class Store {

    private:
    Game games[100];
    int gameCount = 0;

    CartItem cart[100];
    int cartCount = 0;

    double cust_wallet = 0, admin_wallet = 0;

    string password = "admin1admin";
    
    //---------------------
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
        cout << "Enter game name: ";
        cin.ignore();
        getline(cin, games[gameCount].name);
        cout << "Enter price: ";
        cin >> games[gameCount].price;
        cout << "Enter stock: ";
        cin >> games[gameCount].stock;
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

    void changePassword() {
        cout << "Enter new password: ";
        cin.ignore();
        getline(cin, password);
        cout << "Password changed." << endl;

    }
};