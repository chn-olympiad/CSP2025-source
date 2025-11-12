#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10,MOD=998244353;
int n,ans;
int a[N];
void dfs(int i,int x,int xuan){
	if(i>n) return;
	if(xuan+(n-i+1)<3) return;
	if(a[i]<x) ans++,ans%=MOD;
	dfs(i+1,x+a[i],xuan+1);
	dfs(i+1,x,xuan);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
