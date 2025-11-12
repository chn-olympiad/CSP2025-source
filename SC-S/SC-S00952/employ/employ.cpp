#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=520,inf=1e18,mod=998244353;
int read(){
	int x;
	scanf("%lld",&x);
	return x;
}
void write(int x){
	printf("%lld",x);
}
void writeh(int x){
	printf("%lld",x);
	putchar('\n');
}
void writek(int x){
	printf("%lld",x);
	putchar(' ');
}
int n,m,c[N],ans; bool flag1;
string str;
void dfs(int pos,int st,int cnt){
	if(pos==n+1){
		if(n-cnt>=m) ans++,ans%=mod;
		return ;
	}
	if(n-cnt<m) return ;
	for(int i=1;i<=n;i++){
		if(st&(1<<i)) continue;
		dfs(pos+1,st|(1<<i),cnt+(cnt>=c[i] || str[pos-1]=='0'));
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(); m=read();
	cin>>str;
	for(int i=1;i<=n;i++) c[i]=read();
	for(int i=0;i<n;i++){
		if(str[i]=='0') flag1=1;
	}
	if(!flag1){
		int res=1;
		for(int i=1;i<=n;i++) res=res*i%mod;
		write(res);
		return 0;
	}
	dfs(1,0,0);
	write(ans);
	return 0;
}