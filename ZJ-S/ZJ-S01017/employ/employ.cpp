#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,m,s[505],c[505],ans;
string s1;
bool vis[505];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<48||ch>57){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>=48&&ch<=57){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void dfs(int dep,int tot,int sum){
	if(ans>mod)ans%=mod;
//	cout<<"dep: "<<dep<<" tot: "<<tot<<" sum: "<<sum<<'\n';
	if(dep>n){
		if(tot>=m)ans++;
		return;
	}
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		vis[i]=true;
		if(s[dep]==1){
			dfs(dep+1,tot+1,sum);
		}
		else{
			dfs(dep+1,tot,sum+1);
		}
		if(c[i]<=sum){
			dfs(dep+1,tot,sum+1);
		}
		vis[i]=false;
	}
	
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();;
	cin>>s1;
	for(int i=1;i<=n;++i)s[i]=s1[i-1]-'0';
	for(int i=1;i<=n;++i)c[i]=read();
	dfs(1,0,0);
	cout<<ans<<'\n';
	return 0;
}
/*
3 2
101
1 1 2
*/
