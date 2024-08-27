#include<bits/stdc++.h>
using namespace std;

    void printOneToN(int num){

        if(num == 1){ // Base case
            cout<< 1 << " ";
            return;
        }
        printOneToN(num - 1); // hypothesis
        cout<< num << " "; // Induction
    }

    void printNtoOne(int num){

        if(num == 1){ // Base condition
            cout<< 1<< " ";
            return;
        }
        cout<< num << " "; // Induction
        printNtoOne(num - 1); // Hypothesis
    }

int main(){
    int num;
    cin>> num;
    printOneToN(num);
    cout << "\n";
    printNtoOne(num);
}