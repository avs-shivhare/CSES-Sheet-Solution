#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin>>n;
    set<int> mpp;
    int ans = 0;
    for(int i =0; i<n; i++) {
        int val;
        cin>>val;
        mpp.insert(val);
    }
    for(auto i:mpp) ans++;
    cout<<ans<<endl;
    return 0;
}