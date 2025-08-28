#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isVowel(char c){
    c = tolower(c);
    return (c=='a' || c=='e' || c=='o' || c=='i' || c=='u' );
}

/*int main(){
    string str1,str2;
    cout << "Enter the first string" << endl;
    getline(cin,str1);
    cout << "Enter the second string\n";
    getline(cin,str2);


    string result = str1 + str2;
    cout << "Concatemated string: " << result << endl;


    //reverse of string
    reverse(str1.begin(),str1.end());
    cout << "Reversed string" << str1 << endl;

    //Delete all vowels from a string
    string result2 = "";
    for(char c : str2){
        if(!isVowel(c)){
            result2 += c ;
        }
    }
    cout << "String without vowels: " << result2 << endl;

    return 0;
}*/

int main(){
    int n;
    cout << "Enter the number of strings" << endl;
    cin >> n;

    string arr[n];
    cout << "Enter" << n << "Strings: " << endl;
    for(int i=0;i<n;i++){
        getline(cin,arr[i]);
    }
    sort(arr, arr + n);
    cout << "Strings in alphabetical order:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}