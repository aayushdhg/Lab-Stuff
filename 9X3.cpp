// #include <iostream>
// #include <stdexcept>  // For standard exceptions
// using namespace std; 
// int main() {
//     try {
//         int choice;
//         std::cout << "Enter a number (1 for integer exception, 2 for char exception, 3 for string exception): ";
//         std::cin >> choice;

//         // Based on the choice, throw different types of exceptions
//         if (choice == 1) {
//             throw 10;  // Throw an integer exception
//         } else if (choice == 2) {
//             throw 'A';  // Throw a character exception
//         } else if (choice == 3) {
//             throw std::string("String exception!");  // Throw a string exception
//         } else {
//             throw std::runtime_error("Unknown exception type!");  // Throw a standard exception
//         }
//     }
//     catch (int e) {
//         std::cout << "Caught an integer exception: " << e << std::endl;
//     }
//     catch (char e) {
//         std::cout << "Caught a character exception: " << e << std::endl;
//     }
//     catch (std::string& e) {
//         std::cout << "Caught a string exception: " << e << std::endl;
//     }
//     catch (std::exception& e) {
//         std::cout << "Caught a standard exception: " << e.what() << std::endl;
//     }

//     std::cout << "Program continues after exception handling." << std::endl;
//     return 0;
// }










#include <iostream>
#include <stdexcept> //for standard exception classes
using namespace std;

int main() {
    try {
        int choice;
        cout << "Enter 1 for division, 2 for array access: ";
        cin >> choice;

        if (choice == 1) {
            double numerator, denominator;
            cout << "Enter numerator: ";
            cin >> numerator;
            cout << "Enter denominator: ";
            cin >> denominator;

            if (denominator == 0) {
                throw "Division by zero error!";
            } else {
                cout << "Result: " << numerator / denominator << endl;
            }
        } else if (choice == 2) {
            int index;
            int arr[3] = {10, 20, 30};
            cout << "Enter index (0-2): ";
            cin >> index;

            if (index < 0 || index >= 3) {    //using standard exception classes defined in the <stdexcept> header
                throw out_of_range("Array index out of range"); //thrown when an operation attempts to access an element outside the bounds of a container
                cout << "Value at index " << index << " is " << arr[index] << endl; //out_of_range is derived from the logic_error class, which in turn is derived from the exception class
            }
        } else {
            throw invalid_argument("Invalid choice"); //thrown to indicate an argument provided to a function is invalid
        }                                             //invalid_argument is also derived from the logic_error class
    }
    catch (const char* msg) {
        cerr << "Caught an exception: " << msg << endl;
    }
    catch (out_of_range& e) {
        cerr << "Caught an exception: " << e.what() << endl; //the what method is used to access error messages of exception cases (these are typically caught using references, creating copy of the exception OBJECT avoided)
    }  // If we catch exceptions by value, we might accidentally slice off derived parts of an exception object if the exception is derived from another class. Catching by reference avoids this issue and ensures that we handle the full object
    catch (invalid_argument& e) {
        cerr << "Caught an exception: " << e.what() << endl;
    }

    cout << "Program ended normally." << endl;
    return 0;
}
