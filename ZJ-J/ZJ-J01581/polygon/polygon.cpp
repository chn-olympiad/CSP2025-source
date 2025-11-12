#include <bits/stdc++.h>
using namespace std;
const int maxn=5010;
const int mod=998244353;
int n,a[maxn],ans;
void dfs(int x,int mx,int lst,int sum){
	if(x>n) return;
//	cout << x << ' ' << mx << ' ' << lst << ' ' << sum << '\n';
	if(x>=3&&(sum>2*mx)){
		ans=(ans+1)%mod;
	}
	for(int i=lst+1;i<=n;i++){
		dfs(x+1,max(mx,a[i]),i,sum+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	dfs(0,0,0,0);
	cout << ans%mod;
	return 0;
}
