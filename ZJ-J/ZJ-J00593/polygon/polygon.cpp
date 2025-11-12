#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
const int N=5001;
int n,a[N];
int ans=0;
void dfs(int cur,int tol,int step) {
	if (tol>a[cur] && step>=3) ans++;
	for (int i=cur+1; i<=n; i++) {
		dfs(i,tol+a[cur],step+1);
	}
	return;
}
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;

	//神秘分类讨论
	//if(n<500)

	for (int i=1; i<=n; i++) {
		cin>>a[i];
	}

	sort(a+1,a+1+n);
	for (int i=1; i<=n; i++) {
		dfs(i,0,1);
	}
	cout<<ans%MOD;

	return 0;
}
