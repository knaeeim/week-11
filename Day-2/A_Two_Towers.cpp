#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using order_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl "\n"
#define ll long long int
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define vi vector<int>
#define vll vector<ll>
#define vp vector<pair<ll,ll>>
#define sorta(arr) sort(arr.begin(), arr.end());
#define sortd(arr) sort(arr.begin(), arr.end(), greater<int>());
#define All(X) (X).begin(),(X).end()
#define Unique(X) (X).erase(unique((X).begin(),(X).end()),(X).end())
#define range(arr) for(auto el: arr) cout<<el<<" ";

bool possible(string a, string b){
    int n = a.size(); 
    int m = b.size(); 

    for(int i = 0; i < m - 1; i++){
        if(b[i] == b[i+1]){
            return false;
        }
    }

    char lastA = a.back(); 
    char lastB = b.back();

    for(int i = n - 1; i >= 1; i--){
        if(a[i] == a[i-1]){
            if(lastA == lastB) return false;
            lastA = a[i]; 
            lastB = a[i];
        }
    }

    return true; 
}


int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    

    int t; 
    cin>>t; 

    while(t--){
        int n, m; 
        cin>>n>>m; 

        string s, k; 
        cin>>s>>k; 

        bool ok = possible(s,k);

        if(!ok){
            ok = possible(k, s);
        }

        if(!ok) no; 
        else yes; 
    }
    return 0; 
}