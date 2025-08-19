#include <iostream>
#include <vector>
#include <string>
#include <array>
using namespace std;

// =====================================================================
// 4) Example function: Returning an array (method 1 - dynamic allocation)
int* createArray() {
    int* arr = new int[3]{1, 2, 3}; // allocated on heap
    return arr; // caller must free memory
}

// 4) Example function: Returning a vector (safe)
vector<int> createVector() {
    return {10, 20, 30};
}

// =====================================================================
// 5) OOP Example: Class definition
class Person {
private:
    string name; // data hidden from outside
    int age;

public:
    // Constructor
    Person(string n, int a) : name(n), age(a) {}

    // Getter
    string getName() { return name; }

    // Setter
    void setName(string n) { name = n; }

    // Method
    void display() {
        cout << name << " is " << age << " years old.\n";
    }

    // Destructor
    ~Person() {
        cout << "Destructor called for " << name << endl;
    }
};

// =====================================================================
int main() {
    // 1) VECTORS -------------------------------------------------------
    cout << "\n=== 1) VECTORS ===\n";
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    cout << "Vector size: " << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";

    // 2) STRINGS -------------------------------------------------------
    cout << "\n=== 2) STRINGS ===\n";
    string s = "Hello";
    s += " World";
    cout << "String: " << s << endl;
    cout << "Length: " << s.length() << endl;
    cout << "Substring (0,5): " << s.substr(0, 5) << endl;
    cout << "Find 'World': " << s.find("World") << endl;

    // 3) POINTERS ------------------------------------------------------
    cout << "\n=== 3) POINTERS ===\n";
    int x = 42;
    int* p = &x; // pointer to x
    cout << "Address of x: " << p << endl;
    cout << "Value via pointer: " << *p << endl;
    *p = 100; // change value via pointer
    cout << "New value of x: " << x << endl;

    // Pointer to array
    int arr[] = {5, 6, 7};
    int* ptr = arr; // array decays to pointer
    cout << "Second element: " << *(ptr + 1) << endl;

    // 4) RETURNING ARRAYS ----------------------------------------------
    cout << "\n=== 4) RETURNING ARRAYS ===\n";
    int* heapArr = createArray(); // method 1: dynamic array
    cout << "Heap array: " << heapArr[0] << ", " << heapArr[1] << ", " << heapArr[2] << endl;
    delete[] heapArr; // free memory

    vector<int> vecFromFunc = createVector(); // method 2: vector
    cout << "Vector from function: ";
    for (int val : vecFromFunc) cout << val << " ";
    cout << endl;

    // 5) CLASSES & OOP -------------------------------------------------
    cout << "\n=== 5) CLASSES & OOP ===\n";
    Person p1("Alice", 25);
    p1.display();
    p1.setName("Bob");
    cout << "Updated name: " << p1.getName() << endl;

    // 6) DYNAMIC MEMORY ALLOCATION -------------------------------------
    cout << "\n=== 6) DYNAMIC MEMORY ALLOCATION ===\n";
    // Single variable
    int* dynInt = new int(50); // allocate int on heap
    cout << "Dynamic int: " << *dynInt << endl;
    delete dynInt; // free memory

    // Dynamic array
    int n;
    cout << "Enter size of dynamic array: ";
    cin >> n;
    int* dynArr = new int[n];
    for (int i = 0; i < n; i++) {
        dynArr[i] = i + 1; // fill with values
    }
    cout << "Dynamic array contents: ";
    for (int i = 0; i < n; i++) {
        cout << dynArr[i] << " ";
    }
    cout << endl;
    delete[] dynArr; // free memory

    cout << "\n=== PROGRAM END ===\n";
    return 0;
}
