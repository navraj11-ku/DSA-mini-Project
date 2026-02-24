#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {

    stack<string> undoStack;
    stack<string> redoStack;
    string currentText = "";

    int choice;

    while (true) {
        cout << "\n------ TEXT EDITOR ------\n";
        cout << "1. Add Text\n";
        cout << "2. Undo\n";
        cout << "3. Redo\n";
        cout << "4. Display Current Text\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;
        cin.ignore();

        switch (choice) {

        case 1: {
            cout << "Enter text to add: ";
            string newText;
            getline(cin, newText);

            undoStack.push(currentText);
            currentText += newText;

            while (!redoStack.empty()) {
                redoStack.pop();
            }
            break;
        }

        case 2:
            if (!undoStack.empty()) {
                redoStack.push(currentText);
                currentText = undoStack.top();
                undoStack.pop();
                cout << "Undo successful.\n";
            } else {
                cout << "Nothing to undo.\n";
            }
            break;

        case 3:
            if (!redoStack.empty()) {
                undoStack.push(currentText);
                currentText = redoStack.top();
                redoStack.pop();
                cout << "Redo successful.\n";
            } else {
                cout << "Nothing to redo.\n";
            }
            break;

        case 4:
            cout << "Current Text: " << currentText << endl;
            break;

        case 5:
            cout << "Exiting program.\n";
            return 0;

        default:
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}