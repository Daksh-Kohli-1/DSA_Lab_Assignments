#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice = 0;

    while (choice != 6) {
        cout << "\n================== MENU ==================\n";
        cout << "Enter 1 to CREATE an array" << endl;
        cout << "Enter 2 to DISPLAY an array" << endl;
        cout << "Enter 3 to INSERT an ELEMENT IN array" << endl;
        cout << "Enter 4 to DELETE an ELEMENT FROM array" << endl;
        cout << "Enter 5 to LINEAR SEARCH an array" << endl;
        cout << "Enter 6 to QUIT an array" << endl;
        cout << "==========================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                cout << "Enter number of elements: ";
                cin >> size;
                if(size > MAX_SIZE) {
                    cout << "Size exceeds maximum allowed. Try again.\n";
                    size = 0;
                    break;
                }
                cout << "Enter elements:\n";
                for(int i = 0; i < size; i++) {
                    cin >> arr[i];
                }
                cout << "Array created successfully.\n";
                break;
            }

            case 2: {
                if(size == 0) {
                    cout << "Array is empty.\n";
                } else {
                    cout << "Array elements: ";
                    for(int i = 0; i < size; i++) {
                        cout << arr[i] << " ";
                    }
                    cout << endl;
                }
                break;
            }

            case 3: {
                if(size >= MAX_SIZE) {
                    cout << "Array is full. Cannot insert more elements.\n";
                    break;
                }
                int pos, val;
                cout << "Enter position to insert (0 to " << size << "): ";
                cin >> pos;
                if(pos < 0 || pos > size) {
                    cout << "Invalid position.\n";
                    break;
                }
                cout << "Enter value to insert: ";
                cin >> val;

                for(int i = size; i > pos; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[pos] = val;
                size++;
                cout << "Element inserted.\n";
                break;
            }

            case 4: {
                if(size == 0) {
                    cout << "Array is empty. Nothing to delete.\n";
                    break;
                }
                int pos;
                cout << "Enter position to delete (0 to " << size - 1 << "): ";
                cin >> pos;
                if(pos < 0 || pos >= size) {
                    cout << "Invalid position.\n";
                    break;
                }
                for(int i = pos; i < size - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                size--;
                cout << "Element deleted.\n";
                break;
            }

            case 5: {
                if(size == 0) {
                    cout << "Array is empty.\n";
                    break;
                }
                int val, found = -1;
                cout << "Enter value to search: ";
                cin >> val;
                for(int i = 0; i < size; i++) {
                    if(arr[i] == val) {
                        found = i;
                        break;
                    }
                }
                if(found != -1) {
                    cout << "Element found at index " << found << endl;
                } else {
                    cout << "Element not found.\n";
                }
                break;
            }

            case 6:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
