#include<bits/stdc++.h>
using ll = long long;
using db = double;
#define For(i,j,k) for(ll i = j;i <= k;i++)
#define Rep(i,j,k) for(ll i = j;i >= k;i--)
#define fi first
#define se second
#define pll pair<ll,ll>
#define tll tuple<ll,ll,ll>
#define pb push_back
#define eb emplace_back
using namespace std;
const ll N = 1e6 + 10,p = 998244353,inf = 1e18;
void sol(){ll n;cin >> n;ll o = 1;For(i,1,n) o = o * i % p;cout << o << '\n';
}int main(){
	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll T = 1;while(T--) sol();return 0;
}
