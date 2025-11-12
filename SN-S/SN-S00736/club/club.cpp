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
void sol(){ll n;cin >> n;vector<vector<ll>> a(n + 1,vector<ll>(4));
	For(i,1,n) cin >> a[i][1] >> a[i][2] >> a[i][3];ll o = 0;vector<ll> b(n + 1);
	For(i,1,n){if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) b[i] = 1;
		else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) b[i] = 2;else b[i] = 3;
	}ll c1 = 0,c2 = 0,c3 = 0;For(i,1,n) c1 += b[i] == 1,c2 += b[i] == 2,c3 += b[i] == 3;
	if(c1 <= n / 2 && c2 <= n / 2 && c3 <= n / 2){
		For(i,1,n) o += a[i][b[i]];cout << o << '\n';return;
	}if(c1 > n / 2){vector<ll> v;For(i,1,n) if(b[i] == 1) v.eb(max(a[i][2],a[i][3]) - a[i][1]);
		sort(v.begin(),v.end(),greater<ll>());For(i,1,n) o += a[i][b[i]];For(i,1,c1 - n / 2) o += v[i - 1]; 
	}if(c2 > n / 2){vector<ll> v;For(i,1,n) if(b[i] == 2) v.eb(max(a[i][1],a[i][3]) - a[i][2]);
		sort(v.begin(),v.end(),greater<ll>());For(i,1,n) o += a[i][b[i]];For(i,1,c2 - n / 2) o += v[i - 1]; 
	}if(c3 > n / 2){vector<ll> v;For(i,1,n) if(b[i] == 3) v.eb(max(a[i][2],a[i][1]) - a[i][3]);
		sort(v.begin(),v.end(),greater<ll>());For(i,1,n) o += a[i][b[i]];For(i,1,c3 - n / 2) o += v[i - 1]; 
	}cout << o << '\n';
}int main(){
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll T;cin >> T;while(T--) sol();return 0;
}
