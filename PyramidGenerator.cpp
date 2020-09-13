#include <iostream>
#include <string>

using namespace std;

int main() {
    
    string user_input {}, pyra {""};
    cout << "Enter a sequence of characters: ";
    cin >> user_input;
    cout<<endl; 
    string space (user_input.length() - 1, ' ');   
    for (size_t i{0}; i < user_input.length(); ++i) {
        pyra = user_input.substr(0, i+1 );  
        cout << space << pyra;

       for (auto j {pyra.length()}; j > 0; --j) {
           cout << pyra.at(j-1);   
      }
      space.erase(0, 1);
      cout << endl;
    }
    cout << endl;
    return 0;
}