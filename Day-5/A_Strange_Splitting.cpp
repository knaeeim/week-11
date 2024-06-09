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

        vi v(n);

        for(int i = 0; i < n; i++) cin>>v[i]; 

        string answer = ""; 

        vi calcu; 

        bool ok = false;

        if(v[0] != v[1]){
            ok = true;
            for(int i = 0; i < n - 1; i++){
                answer +='B'; 
                calcu.pub(v[i]);
            }
            answer+='R';
        }
        else{
            answer += 'R'; 
            for(int i = 1; i < n; i++){
                answer +='B'; 
                calcu.pub(v[i]);
            }
        }

        sorta(calcu); 

        int diff1;
        if(ok){
            diff1  = v[n-1] - v[n-1];
        }
        else{
            diff1 = v[0] - v[0];
        }
        
        if(calcu[calcu.size()-1] - calcu[0] != diff1){
            yes;
            cout << answer << endl;
        }
        else{
            no;
        }
    }
    return 0; 
}