# Supermarket Application

This is a C++ program that simulates a simple supermarket system. It includes functionalities for managing products and a shopping cart. The system is divided into two main roles: Administrator and User.

## Features

### Administrator
- **Add Perishable Product**: Add a product with an expiry date.
- **Add Non-Perishable Product**: Add a product with a warranty period.

### User
- **Add Product to Cart**: Add available products to the shopping cart.
- **Remove Product from Cart**: Remove products from the shopping cart.
- **Display Cart**: View all products currently in the shopping cart.
- **Checkout**: Calculate and display the total bill for the products in the cart.

## Object-Oriented Programming (OOP) Concepts

The application uses several OOP concepts such as inheritance, encapsulation, polymorphism, and abstraction.

### Classes
- **Product**: Base class for all products. Contains common attributes like `id`, `name`, and `price`.
- **Perishable**: Derived class for perishable products. Adds an `expiryDays` attribute.
- **NonPerishable**: Derived class for non-perishable products. Adds a `warranty` attribute.
- **Shopping**: Base class for managing a collection of products.
- **Administrator**: Derived class from `Shopping` for managing product inventory.
- **User**: Derived class from `Shopping` for managing the user's shopping cart.

### OOP Benefits in This Application
- **Encapsulation**: Data members are protected and accessed via public methods.
- **Inheritance**: Enables code reuse by creating specific product types (`Perishable` and `NonPerishable`) that inherit from the base `Product` class.
- **Polymorphism**: Allows for dynamic method binding using virtual functions, enabling different behaviors for `display()` in derived classes.
- **Abstraction**: Simplifies interaction with complex systems by exposing only necessary components and operations.

## Standard Template Library (STL)

The application makes use of STL containers to manage collections of products efficiently.

### STL Components Used
- **Vector**: The `std::vector` container is used to store and manage dynamic arrays of `Product` pointers in the `Shopping` class and its derived classes (`Administrator` and `User`).

## Getting Started

### Prerequisites
- A C++ compiler (e.g., g++, clang++)
- Git (for cloning the repository)

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/USERNAME/supermarket-app.git
   cd supermarket-app
