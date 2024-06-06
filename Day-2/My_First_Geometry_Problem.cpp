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
        string s; 
        cin>>s; 

        ll left_right = 0;
        ll up_down = 0;

        if(s[0] == '1' and s[1] == '1'){
            left_right +=21;
        }
        else if(s[0] == '1' or s[1] == '1'){
            left_right +=11;
        }

        if(s[2] == '1' and s[3] == '1'){
            up_down +=21;
        }
        else if(s[2] == '1' or s[3] == '1'){
            up_down +=11;
        }

        if(left_right == 0 || up_down == 0){
            cout << max(left_right, up_down) << endl;
        }
        else{
            cout << left_right * up_down << endl; 
        }
        
    }
    return 0; 
}