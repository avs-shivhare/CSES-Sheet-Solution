#include<bits/stdc++.h>
using namespace std;
 
int main() {
    string n;
    cin>>n;
    int s = n.size();
    int cnt =1;
    int out = INT_MIN;
    char ans = n[0];
    for(int i =1; i<s; i++) {
        if(n[i] == ans) {
            cnt++;
        }else {
            out = max(out,cnt);
            cnt = 1;
            ans = n[i];
        }
    }
    out = max(out,cnt);
    cout<<out<<endl;
}