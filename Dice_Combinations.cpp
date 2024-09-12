#include<bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define db double
#define str string
#define endl "\n"
#define bl bool
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pss pair<string,string>
#define p pair
#define V vector
#define fs first
#define ss second
#define vi vector<int>
#define vc vector<char>
#define vb vector<bl>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vvb vector<bl>
#define vvs vector<vector<string>>
#define vvc vector<vector<char>>
#define vs vector<string>
#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define f(i,s,e) for(ll i =s; i<e; i++)
#define fi(i,s,e,x) for(ll i = s; i<e; i+=x)
#define ef(i,s,e) for(ll i = s; i<=e; i++)
#define rf(i,e,s) for(ll i = e; i>=s; i--)
#define af(i,x) for(auto i : x)
#define aff(i,x) for(auto &i: x)
#define all(p) p.begin(),p.end()
#define out(x) cout<<x<<endl
#define wh while
#define si(x) x.size();
ll mod = 1e9+7;

template<typename Var,typename Val,typename Limit> void in(Var &x,Limit n) {f(i,0,n) {Val val; cin>>val; x.pb(val);}}
template<typename Var> void outall(Var x) {af(i,x) {cout<<i<<" ";} cout<<endl;}

class disjointSet {
    vector<int> rank,parent,size;
    public:

    disjointSet(int n) {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i =0;i<=n; i++) {
            parent[i] =i;
        }
    }

    int findUparent(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findUparent(parent[node]);
    }
    void addbySize(int u,int v) {
        int Uu = findUparent(u);
        int Uv = findUparent(v);
        if(Uu == Uv) return;
        if(size[Uu] < size[Uv]) {
            parent[Uu] = Uv;
            size[Uv] += size[Uu];
        }
        else {
            parent[Uv] = Uu;
            size[Uu] += size[Uv];
        }
    }
    void addbyRank(int u,int v) {
        int Uu = findUparent(u);
        int Uv = findUparent(v);
        if(Uu == Uv) return;
        if(rank[Uu]<rank[Uv]) {
            parent[Uu] = Uv;
        }
        else if(rank[Uv] < rank[Uu]) {
            parent[Uv] = Uu;
        }
        else {
            parent[Uv] =Uu;
            rank[Uu]++;
        }
    }
};

template<typename T> T hcf(T x,T y) {
    if(x == 0) return y;
    if(y == 0) return x;
    if(x > y) return hcf(x%y,y);
    return hcf(x,y%x);
}

template<typename T> T power(T base,T pow) {
    if(pow == 0) return 1;
    T temp = power(base,pow/2);
    if(pow & 1) return base*temp*temp;
    return temp*temp;
}

ll find(ll n,ll arr[]) {
    if(n < 0) return 0;
    if(n == 0) return 1;
    if(arr[n] != -1) return arr[n];
    ll ans = 0;
    f(i,1,7) {
        ans = (ans+find(n-i,arr))%mod;
    }
    return arr[n] = ans;
}

int main() {
    // ll t;
    // fast_io
    // cin>>t;
    // wh(t--) {
        fast_io
        ll n;
        cin>>n;
        ll arr[n+1];
        memset(arr,-1,sizeof(arr));
        //af(i,arr) out(i);
        ll ans = find(n,arr);
        out(ans);
    // }
    return 0;
}