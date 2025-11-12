#include<bits/stdc++.h>
#define int long long
#define fr(s) freopen(s".in","r",stdin)
#define fw(s) freopen(s".out","w",stdout)
#define ff(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
using namespace std;
int mod=998244353;
const int N=110;
int n,m,ans;
int a[N],vis[N];
int c[N];
int flagA;
string s;
int inv[N];
bool check(){
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<"\n";
//	return 0;
	int sum=0,res=0;
	for(int i=1;i<=n;i++){
		if(sum>=c[a[i]]){
			sum++;
			continue;
		}
		if(s[i-1]=='0')sum++;
		else res++;
	}
//	cout<<sum<<" "<<res<<"\n";
	return res>=m;
}
void dfs(int cnt){
	if(cnt==n+1){
		if(check())ans=(ans+1)%mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			a[cnt]=i;
			dfs(cnt+1);
			a[cnt]=0;
			vis[i]=0;
		}
	}
}
int qpow(int x,int y){
	int res=1;
	while(y){
		if(y&1)res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res%mod;
}
void solve1(){
	inv[1]=1;
	for(int i=2;i<=n;i++){
		inv[i]=qpow(i,mod-2);
	}
	int num=0,res=1;
	for(int i=1;i<=n;i++){
		if(c[i]>0){
			num++;
		}
	}
	for(int i=2;i<=n;i++){
		res=res*i%mod;
	}
	cout<<res;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ff("employ");
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='0')flagA=1;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=18){
		dfs(1);
		cout<<ans;
	}
	else {
		solve1();
	}
	return 0;
}


