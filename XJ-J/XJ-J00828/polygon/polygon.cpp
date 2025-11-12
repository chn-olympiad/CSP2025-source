#include <bits/stdc++.h>
using namespace std;
const int N = 5005;

int n, A[N];
int vis[N];
long long ans=0;
void dfs(int a, int l, int mx, int s){
	if(s>=3){
		if(l>2*mx)ans++;
	}
	for(int i=a+1; i<=n; i++){
		if(vis[i])continue;
		vis[i]=1;
		dfs(i, l+A[i], max(mx, A[i]), s+1);
		vis[i]=0;
	}
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	for(int i=1; i<=n; i++)cin>>A[i];
	dfs(0, 0, 0, 0);
	cout << ans;
	return 0;
}
