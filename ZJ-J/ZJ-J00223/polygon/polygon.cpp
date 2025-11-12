#include<bits/stdc++.h>//I LOVE CCF
#define int long long
using namespace std;
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
const int Mod=998244353;
int n,ans;
int a[5005],vis[5005];
void dfs(int idx,int sum) {
	if(idx>n)return;
	if(a[idx]<sum)ans++;
	dfs(idx+1,sum+a[idx]);
	dfs(idx+1,sum);
}
int CCF(int x,int y) {
	int sum=1;
	for(int i=y+1; i<=x; i++)sum=sum*i%Mod;
	return sum;
}

signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1; i<=n; i++)a[i]=read();
	sort(a+1,a+n+1);
	if(a[n]==1) {
		int ans=0;
		for(int i=3; i<=n; i++)
			ans=(ans+CCF(n,i))%Mod;
		cout<<ans<<'\n';
	} else {
		dfs(0,0);
		cout<<ans/2<<'\n';
	}
	return 0;
}//I LOVE CCF
//
