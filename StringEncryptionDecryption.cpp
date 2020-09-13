#include <iostream>
#include <string>

using namespace std;

int main() {
    char user_response {};
    char user_repeat {};
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
    
    do {
        cout << "Hello! Enter 'E' to encrypt a message and 'D' to decrypt a message: ";
        cin >> user_response;
        if (user_response == 'E' || user_response == 'e') {
            string secret_message {};
            cout << "\nEnter your secret message: ";
            cin.ignore();
            getline(cin, secret_message);
            string encrypted_message {};
            cout << "\nEncrypting message..." << endl;
            cout << endl;
            
            for (char c:secret_message) {
                size_t position = alphabet.find(c);
            if (position!=string::npos) {
                char new_char = key.at(position);
                encrypted_message += new_char;
            }
            else {
                encrypted_message += c;
            }
          }
    
            cout << "The encrypted message is: " << encrypted_message << endl;
        }
        
        else if (user_response == 'D' || user_response == 'd') {
            string hidden_message {};
            cout << "Enter a message to decrypt: ";
            cin.ignore();
            getline(cin, hidden_message);
            cout << "\nDecrypting message... " << endl;
            
            string decrypted_message {};
            for (char c:hidden_message) {
                size_t position = key.find(c);
                if (position!=string::npos) {
                    char new_char = alphabet.at(position);
                    decrypted_message += new_char;
             } 
                else {
                 decrypted_message += c;
                }
            }
            
            cout <<"The decrypted message is: " << decrypted_message << endl;
    
        }
        else {
            cout << "Invalid user input" << endl;
        }
        cout << endl;
        cout << "\nWould you like to run the program again? Type Y or N: ";
        cin >> user_repeat;
        cout << endl;
        cout << endl;
    }
    while (user_repeat == 'Y'|| user_repeat == 'y');
    cout << endl;
    cout << "===END OF PROGRAM===" << endl;
    cout << endl;
    
    return 0;
}
    
    
    
    
    