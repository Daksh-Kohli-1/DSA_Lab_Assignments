#include <iostream>
using namespace std;
class Queue{
    int start;
    int end;
    int size;
    int space;
    int *arr;
    public:
        Queue(int n){
            size = 0;
            start = 0;
            end = size - 1;
            space = n;
            arr = new int[space];
        }
        ~Queue(){
            delete[] arr;
        }
        void enqeue(int ele){
            if(end == space - 1){
                cout << "No space to Enter an element" << endl;
            }
            else{
                arr[++end] = ele;
            }
        }
        int deqeue(){
            if(start > end){
                return -1;
            }else{
                return arr[start++];
            }
        }
        bool isEmpty(){
            if(start > end){
                return true;
            }else{
                return false;
            }
        }
        bool isFull(){
            if(end == space-1){
                return true;
            }else{
                return false;
            }
        }
        void display(){
            for(int i=start;i<=end;i++){
                cout << arr[i] << "," ;
            }
            cout << endl;
        }
        int peek(){
            return arr[start];
        }

};

class CircularQueue{
    int start;
    int end;
    int size;
    int space;
    int *arr;
    public:
        CircularQueue(int n){
            int start = 0;
            int end = size - 1;
            int size = 0;
            int space = n;
            arr = new int[n];
        }
        ~CircularQueue(){
            delete[] arr;
        }
        void enqeue(int ele){
            if(start != end){
                end = (end+1) % space;
                arr[end] = ele;
            }
        }
        int deqeue(){
            if(start < end){
                int temp = start;
                start = (start+1) % space;
                return arr[temp];
            }
        }
        bool isEmpty(){
            if(start == end){
                return true;
            }else{
                return false;
            }
        }
        bool isFull(){
            if(abs(end - start) == space){
                return true;
            }else{
                return false;
            }
        }
        void display(){
            if(start>end){
                for(int i=end;i<start;i++){
                    cout << arr[i] << ",";
                }
                cout << endl;
            }else{
                for(int i=start;i<end;i++){
                    cout << arr[i] << ",";
                }
                cout << endl;
            }
        }
        int peek(){
            return arr[start];
        }
};
int main(){
    CircularQueue q(5);
    q.enqeue(1);
    q.enqeue(2);
    q.enqeue(3);
    q.enqeue(4);
    q.enqeue(5);
    q.enqeue(6);
    q.display();

    return 0;
}
