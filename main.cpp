#include <iostream>
#include <list>
#include <iterator>

class IntegerList {
private:
    std::list<int> lst;

public:
    void append(int value) {
        lst.push_back(value);
    }

    void prepend(int value) {
        lst.push_front(value);
    }

    void insertAt(int value, int position) {
        if (position < 0 || position > lst.size()) {
            std::cerr << "Invalid position\n";
            return;
        }
        auto it = lst.begin();
        std::advance(it, position);
        lst.insert(it, value);
    }

    void print() const {
        if (lst.empty()) {
            std::cout << "NULL\n";
        } else {
            for (int val : lst) {
                std::cout << val << " ";
            }
            std::cout << "\n";
        }
    }

    size_t count() const {
        return lst.size();
    }
};

int main() {
    IntegerList myList;
    char command;

    // Used Switch case because i like it more

    while (true) {
        std::cin >> command;

        switch (command) {
        case 'q': // Quit
            return 0;

        case 'a': { // Append
            int value;
            std::cin >> value;
            myList.append(value);
            break;
        }

        case 'c': // Count
            std::cout << myList.count() << "\n";
            break;

        case 'f': { // Prepend
            int value;
            std::cin >> value;
            myList.prepend(value);
            break;
        }

        case 'p': // Print
            myList.print();
            break;

        case 'i': { // Insert at position
            int value, position;
            std::cin >> value >> position;
            myList.insertAt(value, position);
            break;
        }

        default: // Invalid command
            std::cerr << "Invalid command\n";
            break;
        }
    }
}
