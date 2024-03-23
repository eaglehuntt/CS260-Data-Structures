#include <iostream>
#include "bst.cpp"

bool test_add_and_search() {
    BinarySearchTree bst;
    bst.add(10);
    bst.add(5);
    bst.add(15);
    bst.add(7);
    bst.add(12);

    // Test search for existing and non-existing values
    bool result = (bst.search(10) && bst.search(5) && bst.search(15) && bst.search(7) && bst.search(12) &&
                   !bst.search(3) && !bst.search(20));
    
    std::cout << "Test add and search: ";
    if (result)
        std::cout << "Passed" << std::endl;
    else
        std::cout << "Failed" << std::endl;
    
    return result;
}

bool test_add() {
    BinarySearchTree bst;
    bst.add(10);
    bst.add(5);
    bst.add(15);
    bst.add(7);
    bst.add(12);

    // After adding these values, verify if they exist in the BST
    bool result = (bst.search(10) && bst.search(5) && bst.search(15) && bst.search(7) && bst.search(12));

    // Also, verify if a value that was not added does not exist in the BST
    result = result && !bst.search(20);

    std::cout << "Test add method: ";
    if (result)
        std::cout << "Passed" << std::endl;
    else
        std::cout << "Failed" << std::endl;

    return result;
}

bool test_remove() {
    BinarySearchTree bst;
    bst.add(10);
    bst.add(5);
    bst.add(15);
    bst.add(7);
    bst.add(12);

    bst.remove(5);
    bst.remove(15);
    bst.remove(7);

    // Test search for removed values
    bool result = (!bst.search(5) && !bst.search(15) && !bst.search(7) && bst.search(10) && bst.search(12));
    
    std::cout << "Test remove: ";
    if (result)
        std::cout << "Passed" << std::endl;
    else
        std::cout << "Failed" << std::endl;
    
    return result;
}

bool run_bst_tests() {
    bool result = (test_add_and_search() && test_remove() && test_add());
    return result;
}

void displayMenu() {
    std::cout << "1. Add value to BST" << std::endl;
    std::cout << "2. Remove value from BST" << std::endl;
    std::cout << "3. Search for a value in BST" << std::endl;
    std::cout << "4. In-order traversal of BST" << std::endl;
    std::cout << "5. Exit" << std::endl;
}

// cli made with chatgpt
int main() {
    run_bst_tests();
    BinarySearchTree bst;
    int choice;
    int value;

    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to add: ";
                std::cin >> value;
                bst.add(value);
                std::cout << "Value added to BST." << std::endl;
                std::cout << std::endl;
                break;
            case 2:
                std::cout << "Enter value to remove: ";
                std::cin >> value;
                if (bst.remove(value) == 0)
                    std::cout << "Value removed from BST." << std::endl;
                else
                    std::cout << "Value not found in BST." << std::endl;
                std::cout << std::endl;
                break;
            case 3:
                std::cout << "Enter value to search: ";
                std::cin >> value;
                if (bst.search(value))
                    std::cout << "Value exists in BST." << std::endl;
                else
                    std::cout << "Value does not exist in BST." << std::endl;
                std::cout << std::endl;
                break;
            case 4:
                std::cout << "In-order traversal of BST: ";
                bst.in_order_traversal();
                std::cout << std::endl;
                break;
            case 5:
                std::cout << "Exiting..." << std::endl;
                std::cout << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 5." << std::endl;
                std::cout << std::endl;
        }

    } while (choice != 5);

    return 0;
}