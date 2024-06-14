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

bool prime[100001];

void SieveofErathosnes(){
    memset(prime, true, sizeof(prime)); 
    for(ll i = 2; i * i <= 1e5; i++){
        if(prime[i] == true){
            for(ll p = i * i; p <= 1e5; p+=i){
                prime[p] = false;
            }
        }
    }
}

bool isPerfectSqure(ll n){
    if(n >= 0){
        ll sq = sqrt(n); 
        return (sq * sq == n);
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 

    SieveofErathosnes();
    
    ll t; 
    cin>>t; 

    while(t--){
        ll n;
        cin>>n; 
        n -= 4;

        if( n < 34){
            cout << "No" << endl;
            continue;
        }

        vll primes;
        for(int i = 3; i < 100001; i++){
            if(prime[i]){
                primes.pub(i);
            }
        }

        int flag = 0;
        for(int i = 0; i < primes.size(); i++){
            ll val = primes[i] * primes[i];
            val = n - val;

            if(val < 0){
                break;
            }

            if(isPerfectSqure(val)){
                ll sq = sqrt(val);
                if(prime[sq]){
                    flag = 1;
                    break;
                }
            }
        }

        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0; 
}