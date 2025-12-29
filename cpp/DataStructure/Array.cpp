#include <iostream>
using namespace std;

int main() {
    int arr[100], n = 0, choice;

    while(true) {
        cout << "\n--- ARRAY CRUD MENU ---\n";
        cout << "1. Create\n";
        cout << "2. Read\n";
        cout << "3. Update\n";
        cout << "4. Delete\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1) {
            cout << "Enter number of elements: ";
            cin >> n;
            cout << "Enter elements:\n";
            for(int i = 0; i < n; i++)
                cin >> arr[i];
        }
        else if(choice == 2) {
            cout << "Array: ";
            for(int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
        else if(choice == 3) {
            int index, val;
            cout << "Enter index: ";
            cin >> index;
            cout << "Enter new value: ";
            cin >> val;

            if(index >= 0 && index < n)
                arr[index] = val;
            else
                cout << "Invalid index!\n";
        }
        else if(choice == 4) {
            int index;
            cout << "Enter index to delete: ";
            cin >> index;

            if(index >= 0 && index < n) {
                for(int i = index; i < n - 1; i++)
                    arr[i] = arr[i + 1];
                n--;
            } else {
                cout << "Invalid index!\n";
            }
        }
        else if(choice == 5) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}
