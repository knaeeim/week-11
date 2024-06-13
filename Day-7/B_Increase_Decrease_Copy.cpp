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


int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    

    int t; cin>>t; 

    while(t--){
        int n; 
        cin>>n; 

        vll a(n), b(n+1); 

        for(int i = 0; i < n; i++) cin>>a[i];
        for(int i = 0; i < n+1; i++) cin>>b[i];

        ll sum = 0, ext = 1e18;

        for(int i = 0; i < n; i++){
            sum += abs(a[i] - b[i]);

            ext = min(ext, abs(a[i] - b[n]));
            ext = min(ext, abs(b[i] - b[n])); 

            if(min(a[i], b[i]) <= b[n] and b[n] <= max(a[i], b[i])){
                ext = 0;
            }
        } 

        cout << sum + ext + 1 << endl; 

    }
    return 0; 
}