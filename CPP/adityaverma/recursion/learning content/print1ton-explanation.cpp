#include<bits/stdc++.h>
using namespace std;

    void printR(int n){// Step 1: hypothesis == method signature

        if(n == 1){ // Step 3: base condition : smalllest valid input
            cout<< 1 << " ";
            return;
        }
        cout<< n << " "; // step 2: induction **** Most IMP as this will determine if our function will work correctly or not
        printR(n - 1);
    }

    void print(int n){ // Disigning method == hypothesis
        // base case : 1 is the smallest possible valid input. if it is the case print it directly.
        if(n == 1){
            cout << 1 << " ";
            return; // **** IMP
        }

        print(n - 1); // it will do the work of printing form 1 to n - 1

        cout<< n << " "; // do the remaining work of printing n
    }

/**
 * Hypothesis = design our function
 * print(n) will print from 1 to n
 * 
 * make our function run for n and n - 1
 * determine what work need to be done between n and n - 1
 * That work need to be implemented in induction step
 * 
 * Induction = work need to be done between n and n - 1
 * In this problem if we call fn(n) it will print all element from 1 to n
 * fn(n - 1) will print from 1 to n - 1
 * therefore if we call fn(n - 1) in fn(n) it will do all the work of printing elements from 1 to n - 1
 * we only need to do work for printhing nth element
 * 
 * base case = smallest valid input == 1 in this case
 * 
 */
int main(){
    print(10);
    cout<< "\n";
    printR(10);
}