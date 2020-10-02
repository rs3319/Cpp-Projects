#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
#include <iterator>

using namespace std;

void display_menu();
char get_selection();
void handle_display(const vector<int> &v);
void display_list(const vector<int> &v);
void handle_add(vector<int> &v, int add_value);
void handle_mean(const vector<int> &v);
double calculate_mean(const vector<int> &v);
void handle_smallest(const vector<int> &v);
void handle_largest(const vector<int> &v);
void handle_find(const vector<int> &v);
bool find(const vector<int> &v, int target);
void handle_quit();
void handle_unknown();

int main() {
    
    char selection {};
    vector<int> numbers;
    int add_value;
    
    do{
        display_menu();
        selection = get_selection();
        switch (selection) {
            case 'P':
            handle_display(numbers);
            break;
            
            case 'A':
            handle_add(numbers, add_value);
            break;
            
            case 'M':
            handle_mean(numbers);
            break;
            
            case 'S':
            handle_smallest(numbers);
            break;
            
            case 'L':
            handle_largest(numbers);
            break;
            
            case 'F':
            handle_find(numbers);
            break;
            
            case 'Q':
            handle_quit();
            break;
            
            default:
            handle_unknown();
        }
    } while (selection!='Q');
    cout << endl;
    return 0;
}

void display_menu() {
    cout << "P - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "F - Find a number" << endl;
    cout << "Q - Quit" << endl;
    cout << "\nEnter your choice: ";
}

char get_selection() {
    char selection{};
    cin >> selection;
    return toupper(selection);
}

void handle_display(const vector<int> &v) {
    if (v.size() == 0) {
        cout <<"[] - the list is empty" << endl;
    }
    else {
        display_list(v);
    }
}

void handle_add(vector<int> &v, int add_value) {
    cout << "Enter an integer to add to the list: ";
    cin >> add_value;
    v.push_back(add_value);
    cout << endl;
    cout << add_value << " added" << endl;
    cout << endl;
}

void handle_mean(const vector<int> &v) {
    if (v.size()!=0) {
        cout << "The mean is: " << calculate_mean(v) << endl;
        cout << endl;
    }
    else {
        cout << "Unable to calculate the mean - no data" << endl;
        cout << endl;
    }
}

void handle_smallest(const vector<int> &v) {
    if (v.size()!= 0) {
        cout << "The smallest number is: " << *min_element(v.begin(), v.end()) << endl;
        cout << endl;
    }
    else {
        cout << "Unable to calculate the smallest number - the list is empty" << endl;
        cout << endl;
    }
}

void handle_largest(const vector<int> &v) {
    if (v.size()!= 0) {
        cout << "The largest number is: " << *max_element(v.begin(), v.end()) << endl;
        cout << endl;
    }
    else {
        cout << "Unable to calculate the largest number - the list is empty" << endl;
        cout << endl;
    }
}

void handle_find(const vector<int> &v) {
    int target;
    cout << "Enter a target number to find: ";
    cin >> target;
    
    if (find(v, target)) {
        cout << target << " Target was found" <<endl;
    }
    else {
        cout << "Target not found" << endl;
    }
}

void handle_quit() {
    cout << "Goodbye" << endl;
    cout << endl;
}

void handle_unknown() {
    cout << "Unknown selection - please try again";
    cout << endl;
}

void display_list(const vector<int> &v) {
    cout << "[ ";
    for (auto num:v) {
        cout << num << " ";
    }
    cout << "]" << endl;
}

double calculate_mean(const vector<int> &v) {
    int total {};
    for (auto value:v) {
        total += value;
    }
    return static_cast<double>(total)/v.size();
}

bool find(const vector<int> &v, int target) {
    for (auto num:v) {
        if (num==target) {
            return true;
        }
        else {
            return false;
        }
    }
}