#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=505;
int ksm(int x,int n){
	int sum=1;
	while(n){
		if(n&1) sum=sum*x%mod;
		x=x*x%mod;
		n/=2;
	}
	return sum;
}
int A(int n){
	int sum=1;
	for(int i=2;i<=n;i++){
		sum=sum*i%mod;
	}return sum;
}
char c[N];
int a[N];
int n,m;
int ans;
int b[N];
int vis[N];
void dfs(int x,int sum){
	if(sum>n-m) return ;
	if(x==n+1){
		ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		b[x]=i;
		dfs(x+1,sum+(sum>=a[b[x]]||c[x]=='0'));
		vis[i]=0;
	}
}
signed main(){
//	freopen("employ5.in","r",stdin);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0);
	cout<<ans;
	return 0;
}

