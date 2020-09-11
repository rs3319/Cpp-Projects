#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    char user_input {};
    vector<int> list;
    int add_value;
    int sum = 0;
    int mean_data;
    
    do {
        cout << "P - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit" << endl;
        cout << "\nEnter your choice: ";
        cin >> user_input;
        
        if (user_input == 'P'|| user_input == 'p') {
            if (list.size()!=0) {
                cout << "[ ";
                for (auto num:list) {
                    cout << num << " ";
                }
                cout << "]" << endl;
            }
            else {
                cout << "[] - the list is empty" << endl;
                cout << endl;
            }
        }
        
        else if (user_input == 'A'|| user_input == 'a') {
            cout << "Enter an integer to add to the list: ";
            cin >> add_value;
            list.push_back(add_value);
            cout << endl;
            cout << add_value << " added" << endl;
            cout << endl;
        }
        
        else if (user_input == 'M'|| user_input == 'm') {
            if (list.size()!=0) {
                for (auto value:list) {
                    sum += value;
                    mean_data = static_cast<double>(sum/list.size());
                }
                    cout << "The mean is: " << mean_data << endl;
                    cout << endl;
                }
            else {
                cout << "Unable to calculate the mean - no data" << endl;
                cout << endl;
            }
        }
        else if (user_input == 'S'|| user_input == 's') {
            if (list.size()!= 0) {
                cout << "The smallest number is: " << *min_element(list.begin(), list.end()) << endl;
                cout << endl;
            }
            else {
                cout << "Unable to calculate the smallest number - the list is empty" << endl;
                cout << endl;
            }
        }
        
        else if (user_input == 'L'|| user_input == 'l') {
            if (list.size()!=0) {
                cout << "The largest number is: " << *max_element(list.begin(), list.end()) << endl;
                cout << endl;
            }
            else {
                cout << "Unable to calculate the largest number - the list is empty" << endl;
                cout << endl;
            }
        }
        
        else if (user_input == 'Q'|| user_input == 'q') {
            cout << "Goodbye" << endl;
            cout << endl;
        }
        
        else {
            cout << "Unknown selection - please try again";
            cout << endl;
        }
        
    } while (user_input!='Q'|| user_input!='q');
    cout << endl;
    return 0;
}