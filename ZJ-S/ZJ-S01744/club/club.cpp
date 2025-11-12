#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int maxn=2e6+5;
const int maxm=5e3+5;
const ll INF=1e18;
ll T,n,a[maxn][5],vis[maxn];
void solve() {
	cin >> n;
	priority_queue<pll> q1,q2,q3;
	for(int i=1;i<=n;i++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		vis[i]=0;
		q1.push({a[i][1]-max(a[i][2],a[i][3]),(ll)i});
	}
	ll res1=0;
	while(!q1.empty()) {
		pll now=q1.top();
//		cout << now.first << "\n";
		q1.pop();
		if(now.first<0) {
			break;
		}
		if(res1==n/2) break;
		vis[now.second]=1;
		res1++;
	}
	for(int i=1;i<=n;i++) {
		if(!vis[i]) q2.push({a[i][2]-max(a[i][3],a[i][1]),(ll)i});
	}
	ll res2=0;
	while(!q2.empty()) {
		pll now=q2.top();
//		cout << now.first << "\n";
		q2.pop();
		if(now.first<0) {
			break;
		}
		if(res2==n/2) break;
		if(vis[now.second]) continue;
		vis[now.second]=2;
		res2++;
	}
	if(res1+res2<n/2) {
		for(int i=1;i<=n;i++) {
			if(!vis[i]) q3.push({a[i][3]-max(a[i][1],a[i][2]),i});  
		}//去1最大化 
		ll need=n/2;
		while(!q3.empty()) {
			pll now=q3.top();
//		cout << now.first << "\n";
			q3.pop();
			if(need==0) break;
			if(now.first<0) {
				break;
			}
			vis[now.second]=3;
			need--;
		}
		for(int i=1;i<=n;i++) {
			if(!vis[i])  {
				if(a[i][1]>a[i][2]) vis[i]=1;
				else vis[i]=2;
			}
		} 
	}
	if(res2==n/2) {
		for(int i=1;i<=n;i++) {
			if(!vis[i])  {
				if(a[i][1]>a[i][3]) vis[i]=1;
				else vis[i]=3;
			}
		} 
	}
	if(res1==n/2) {
		for(int i=1;i<=n;i++) {
			if(!vis[i])  {
				if(a[i][2]>a[i][3]) vis[i]=2;
				else vis[i]=3;
			}
		} 
	}
	for(int i=1;i<=n;i++) {
		if(!vis[i]) vis[i]=3;
	}
	ll ans=0;
	for(int i=1;i<=n;i++) {
//		if(a[i])
//		cout << vis[i] << " ";
		ans+=a[i][vis[i]];
	}
	cout << ans << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--) {
		solve();
	}
}
