#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout<< "stack size : " << s.size() << endl;

    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }

// ***** queue *****

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<< "queue size :" << q.size() << " front :" << q.front() << " back :" << q.back() << endl;

    while(!q.empty()){
        cout<< q.front() << endl;
        q.pop();
    }


}