#include<bits/stdc++.h>
using namespace std;
 
int main() {
    long long n;
    cin>>n;
    // n--;
    long long arr[n];
    long long sum = 0;
    long long miss = (n*(n+1))/2;
 
    for(int i =0; i<n-1; i++) {
        long long val;
        cin>>val;
        sum += val;
        arr[i] = val;
    }
    cout<<miss-sum<<endl;
    return 0;
}
