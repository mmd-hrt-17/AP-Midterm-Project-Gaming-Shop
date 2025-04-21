**🎮 Game Store Management System (C++) /// AP midterm project - shahed university**

A console-based game store project built using C++ and Object-Oriented Programming (OOP). The system provides functionalities for both Admin and Customer roles, including game management, purchases, and wallet-based payments.

---------------------------------------------------------

✨ Features:


🔐 Admin Capabilities:

- Add new games

- Remove existing games

- Search for a game

- Edit game details (name, stock, price, category)

- Display all available games

- Check stock status

- Calculate total inventory value

- Change admin password

- Recharge admin wallet


🛒 Customer Capabilities:

- Search for a game

- Display all games

- Check stock status

- Recharge customer wallet

- Filter games by category

- Purchase games and add to cart

- View shopping cart

---------------------------------------------------------

💼 Class Structure :

- Game: Stores game details such as name, price, stock, and category.

- CartItem: Represents items added to the customer's shopping cart.

- Store: The core class that implements all system functionalities.

---------------------------------------------------------

⚠️ Notes:

- All data is stored in memory and will reset once the program closes.

- Default admin password: admin1admin

- goto statements are used for validation, but could be improved with cleaner loop/control structures.

---------------------------------------------------------

📌 Future Improvements (To-do):

- Save/load data from files for persistence

- Upgrade the interface using a GUI or graphical menus

- Implement user registration and login system

- Replace fixed-size arrays with std::vector for better memory management
