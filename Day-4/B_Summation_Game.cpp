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
        ll n, k, x; 
        cin >> n >> k >> x;

        vll v(n); 
        
        for(int i = 0; i < n; i++){
            cin>>v[i];
        }

        sorta(v);

        vll prefix(n, 0); 
        prefix[0] = v[0]; 

        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + v[i];
        }

        ll ans = LLONG_MIN;

        for(int remove = 0; remove <= k; remove++){

            if(remove == n){
                ans = max(ans, 0LL);
                break;
            }

            int afterRemoval = prefix[n - 1 - remove];
            int canNegify = min(n - remove, x);
            int lastRemainingIndex = n - 1 - remove; 

            int negefiedTill = max(0, lastRemainingIndex - canNegify + 1); 

            ll gain; 
            ll negifiedWindowSum; 

            if(negefiedTill == 0){
                negifiedWindowSum = prefix[lastRemainingIndex];
                gain = - negifiedWindowSum;
            }
            else{
                negifiedWindowSum = prefix[lastRemainingIndex] - prefix[negefiedTill - 1];
                gain = prefix[negefiedTill - 1] - negifiedWindowSum;
            }

            ans = max(ans, gain);

        }

        cout << ans << endl; 

    }
    return 0; 
}