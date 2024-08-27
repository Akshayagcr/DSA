#include<bits/stdc++.h>
using namespace std;

long long kthSmallest(long long arr[], long long n, long long k){
    priority_queue<long long> max_heap;
    for(long long  i = 0; i < n; i++){
        max_heap.push(arr[i]);
        if(max_heap.size() > k){
            max_heap.pop();
        }
    }
    return max_heap.top();
}

/**
 * https://www.geeksforgeeks.org/problems/sum-of-elements-between-k1th-and-k2th-smallest-elements3133/1
 */
long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2){
    long long e1 = kthSmallest(A, N, K1);
    long long e2 = kthSmallest(A, N, K2);

    long long sum = 0;

    for(long long i = 0; i < N; i++){
        if(e1 < A[i] && A[i] < e2){
            sum = sum + A[i];
        }
    }
    return sum;
}