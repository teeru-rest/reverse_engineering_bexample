#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string text;

    while (true) {
        cout << "Enter the password: ";
        getline(cin, text);

        transform(text.begin(), text.end(), text.begin(), ::tolower);

        if (text == "wed") {
            cout << "Well done! Correct password" << endl;
            break;
        } else {
            cout << "Nope, try again" << endl;
        }
    }

    cout << "Press Enter to exit...";
    cin.get();

    return 0;
}

