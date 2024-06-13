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

bool check(ll mid, vll diffOfV, ll h){
    ll sum  = 0;
    for(auto x: diffOfV){
        sum +=min(mid, x);
    }
    sum += mid;
    return sum >= h;
}


int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    

    int t; cin>>t; 

    while(t--){
        ll n, h; 
        cin>>n>>h; 

        vll v(n); 
        for(int i = 0; i< n; i++) cin>>v[i]; 

        vll diffOfV(n-1);

        ll diff = 0; 

        for(ll i = 0; i < n - 1; i++){
            diff = abs(v[i+1] - v[i]);
            diffOfV[i] = diff; 
        }

        ll left = 0, right = 1e18;

        while(right > left){
            ll mid = (left + right) / 2;

            if(check(mid, diffOfV, h)){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }

        cout << left << endl; 
    }
    return 0; 
}