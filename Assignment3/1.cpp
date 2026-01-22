#include <iostream>
#include <string>
using namespace std;



class Intstack{
    int top;
    int n;
    int* arr;
    public: 
        Intstack(int size){
            top = -1;
            n = size;
            arr = new int[n];
        }
        ~Intstack(){
            delete[] arr;
        }
        void isEmpty(){
            if(top == -1){
                cout << "Stack is Empty" << endl;
            }
        }
        void isFull(){
            if(top == n-1){
                cout << "Stack is full" << endl;
            }
        }
        void push(int ele){
            arr[++top] = ele;
        }
        int pop(){
            return arr[top--];
        }
        int peek(){
            return arr[top];
        }
        int display(){
            if(top == -1){
                return -1;
            }
            for(int i=0;i<=top;i++){
                cout << arr[i] << " ";
            }
            cout << endl;
            return 0;
        }
        
};
class Charstack{
    int top;
    int n;
    char* arr;
    public: 
        Charstack(int size){
            top = -1;
            n = size;
            arr = new char[n];
        }
        ~Charstack(){
            delete[] arr;
        }
        bool isEmpty(){
            if(top == -1){
                return true;
            }else{
                return false;
            }
        }
        void isFull(){
            if(top == n-1){
                cout << "Stack is full" << endl;
            }
        }
        void push(char ele){
            arr[++top] = ele;
        }
        char pop(){
            return arr[top--];
        }
        char peek(){
            return arr[top];
        }
        int display(){
            if(top == -1){
                return -1;
            }
            for(int i=0;i<=top;i++){
                cout << arr[i] << " ";
            }
            cout << endl;
            return 0;
        }
        
};
int main(){
    Charstack s1(20);
    string s;
    cout << "Enter the string: " << endl;
    getline(cin,s);
    int len = s.length();
    for(int i=0;i<len;i++){
        s1.push(s[i]);
    }
    cout << "Reversed string: ";
    while (!s1.isEmpty()) {
        cout << s1.pop();
    }
    cout << endl;

}
