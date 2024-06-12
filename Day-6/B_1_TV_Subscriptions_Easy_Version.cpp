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
        int h, k, d; 
        cin>>h>>k>>d; 

        vi v(h);
        
        for(int i = 0; i < h; i++){
            cin>>v[i];
        }

        int count = 0; 
        int left = 0, right = 0;
        int ans = INT_MAX;
        map<int, int> mp;
        
        while(right <= h){
            mp[v[right]]++;
            count++;
            if(count == d){
                ans = min((int)mp.size(), ans);
            }
            else if(count > d){
                mp[v[left]]--;
                if(mp[v[left]] == 0){
                    mp.erase(v[left]);
                }
                ans = min((int)mp.size(), ans);
                left++;
                count--;
            }
            right++;
        }           

        cout << ans << endl;   
    }
    return 0; 
}