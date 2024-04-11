// 4-laskin.cpp
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <algorithm>
#include <iterator>

using namespace std;

// Tämä funktio poistaa whitespace-merkit syötteen alusta ja lopusta.
string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    size_t last = str.find_last_not_of(" \t\n\r");
    if (first == string::npos || last == string::npos)
        return "";
    return str.substr(first, (last - first + 1));
}

// Tämä funktio suorittaa laskutoimituksen pinoon tallennetuilla arvoilla.
void performOperation(stack<float>& values, char operation) {
    if (values.size() < 2) {
        cout << "Error: not enough values for the operation '" << operation << "'." << endl;
        return;
    }
    float right = values.top();
    values.pop();
    float left = values.top();
    values.pop();

    switch (operation) {
        case '+': values.push(left + right); break;
        case '-': values.push(left - right); break;
        case '*': values.push(left * right); break;
        case '/':
            if (right != 0) values.push(left / right);
            else cout << "Error: division by zero is not allowed."  << endl;
            break;
        default: cout <<"Unknown operator: " << operation << endl; break;
    }
}

int main() {
    stack<float> values;
    string line;

    cout << "4-calculator. Enter numbers and operators one at a time. '=' displays the result." << endl;

    while (true) {
        cout << "Enter input (one per line): ";
        getline(cin, line);
        line = trim(line);

        // Tarkistetaan, onko syöte operaattori
        if (line == "+" || line == "-" || line == "*" || line == "/") {
            performOperation(values, line[0]);
        } 
        // '=' tulostaa tuloksen
        else if (line == "=") {
            if (!values.empty()) {
                cout << "Result: " << values.top() << endl;
                values.pop();
            } else {
                cout << "Stack empty" << endl;
            }
            break;
        } 
        // Muutoin oletetaan, että syöte on luku ja lisätään se pinoon
        else {
            try {
                float value = stof(line);
                values.push(value);
            } catch (const invalid_argument& e) {
                cout << "Invalid input. Please enter a number or operator." << endl;
            }
        }
    }

    return 0;
}
