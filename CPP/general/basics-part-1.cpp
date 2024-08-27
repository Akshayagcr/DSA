#include<bits/stdc++.h>
using namespace std;

  /**
   * below function prints input vector
   * We have used const to make the vector immutable and it ensures that we dont accidentally modify it.
   * And we have used & to pass vector by reference which avoids making unnecessary copies.
   */
  void printVector(const vector<int> &v){
    for(auto &ele : v){
      cout << ele << " ";
    }
    cout << "\n";
  }

  /**
   * In the below function we return vector by value i.e. copy of vector v
   * This is preferred approach as we cannot return reference to local objects like vector v
   * As they will go out of scope when the function terminates
   * if we try to use reference in return value to refer local object it will result in compile time error.
   * 
   * 
   * STL containers that are temporary or constructed locally within the function.
   * In C++11 and later, returning by value is often the most efficient approach because modern compilers can optimize 
   * it using copy elision or move semantics.
   * 
   *      When you return an object by value, the compiler will try to use Return Value Optimization (RVO) or 
   *      Named Return Value Optimization (NRVO) to avoid copying the object. These optimizations make the return of 
   *      large objects highly efficient.
   * 
   *      If copy elision is not applied, the compiler will use move semantics to transfer ownership of the object 
   *      (using the move constructor) instead of copying it.
   *      
   *      For small containers (e.g., std::array or trivially copyable types), the compiler may choose to copy them directly, 
   *      which is typically very cheap.
   * 
   * 
   */
  vector<int> generateRange(){
    vector<int> v;
    for(int i = 0; i < 5; i++){
      v.push_back(i);
    }
    return v;
  }

int main(){
    /*
    Data types:

        char        single quotes
        int         -10^9 to 10^9   INT_MIN < int < INT_MAX
        long        -10^12 to 10^12
        long long   -10^18 to 10^18 can be represented using "LL" eg "1LL"
        float
        double
        bool : 0 is consider as false, every other value is consider as true even negative integers
        ***  Variables are not initalized by default.
    
        int i = 1e5  (10^5)

        ** We don't generally use float and double in calculations even though it has higher range because of precision. 
        They store higher range at cost of precision.
    */

   int a;
   char b;
   bool c;
   cin >> a >> b >> c;
   cout << "a :" << a << endl << "b :" << b << endl << "c :" << c << endl;

   /*
    IO:
    cin takes input util it finds space or new line character. It also ignores the starting blank spaces and new line characters

   */

  /*
    numbers:

    Calculations always happens in higher data type
    result of 3/2 is 1 where as 3/2.0 is 1.5
    calculation precedence
    char < int < long < long long < float < double
  */

    cout << "3/2 : " << 3/2 << endl << "3/2.0 : " << 3/2.0 << endl;

    /*
    Control statements and loops
    if else, elseif, switch, break, continue
    for, while, do while
    */

   /*
   strings:

   string s = "hello" double quotes
   we can concatenate strings using +
   two strings can be compared using ==
   can access character in string using indexing s1[index]
   we can modify a character in string s1[0] = 'a';
   s1.size() to get length of string
   getline(cin, s1) use to take entire line as input ** getline() does not ignore the spaces which are appended before the string like cin.
   cin.ignore() ignores white space and new line and moves the cursor to new line like cin()

   s1.push_back('a'); append character at the end of the string

   To take any input number of range greater than 10^18 then we cannot use long long. we have to use string in that case to take input.
   */

  /*
  if we need to add a character to a string n number of times then use push_back('char') function
  as its time complexity is O(1) where as if we use s = s + 'char' then c++ needs to make copy of s then add character to it then assign its value
  so its time complexity becomes O(s.size())
  */

 /*
 Arrays:
  2d array : arr[row][column]
  We can only declare array of 10^5 order locally i.e inside main()
  and we can declare an array of order 10^7 globally i.e above main

    const int SIZE = 1e7; // we need to make variable constant which are declared globally. 
    int arr[SIZE];
    int main(){...}

 */

/*
pass by value, pass by reference:

just add '&' to the function/method parameter name to pass that parameter by reference.
void addNumber(int &a){...}
string, vectors, map, list etc all are passed by value by default therefore need to add '&'

arrays are by default passed by reference
void printArray(int arr[], int arraySize){....}

**Note : we can pass 1D array without mentioning size. But for 2D and ND array we need to specify the size.
1D : void func1(int arr[])
2D : void func2(int arr[][20])
In competitive programming we avoid passing array to function as we cannot mention the size of the array in function signature as mention above.
instead we declare array globally with max size i.e. upper bound of the constrain mentioned in the question. 
also by declaring array globally we can directly access it without passing it to function.
*/

/*
Inbuild functions:
swap()
max()
min()
*/




return 0; // Optional

}