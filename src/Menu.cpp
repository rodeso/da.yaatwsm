#include "Menu.h"

int Menu::LINE_SIZE_ = 119;


void Menu::run() {
    string decision;

    while (true) {
        cout << string(LINE_SIZE_, '-') << endl;
        cout << "Welcome to the Water Supply Management Analysis Tool!" << endl;
        cout << string(LINE_SIZE_, '-') << endl;
        cout << "Select your data folder:" << endl;
        cout << "1 - Mainland Portugal." << endl;
        cout << "2 - Madeira." << endl;
        cout << "3 - Custom." << endl;
        cout << "4 - Exit." << endl;
        cout << string(LINE_SIZE_, '-') << endl;
        cout << "Please select the task you wish to perform by inputting its number: ";

        while (true) {
            getline(cin, decision);
            cout << endl;
            if (decision.size() != 1) { cout << "Invalid input. Please enter a number between 1 and 4: "; continue;}
            switch (decision[0]) {
                case '1':
                    goto menu_text;
                case '2':
                    goto menu_text;
                case '3':

                    goto menu_text;
                case '4':
                    cout << "Goodbye!" << endl;
                    exit(0);
                default:
                    cout << "Invalid input. Please enter a number between 1 and 4: ";
                    break;
            }
        }
        menu_text:;
    }
}



#include "Menu.h"
