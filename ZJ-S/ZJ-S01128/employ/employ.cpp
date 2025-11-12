#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,c[N],ch,fac[N],Sum[N],falure;
char s[N],vis[N];
inline int read(){
	int c=getchar(),now=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))now=now*10-'0'+c,c=getchar();
	return now;
}
inline int dfs(int k,int ok){
	if(ok>=m)return fac[n-k+1];
	if(ok+(Sum[n]-Sum[k-1])<m)return 0;
	int rp=0;
	for(int i=1;i<=n;i++)
		if(vis[i]==0){
			vis[i]=1;
			if(s[k]==0||c[i]<=k-1-ok)rp=(rp+dfs(k+1,ok))%mod;
			else rp=(rp+dfs(k+1,ok+1))%mod;
			vis[i]=0;
		}
	return rp;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();fac[0]=1;
	for(int i=1;i<=n;i++){
		ch=getchar();
		while(ch!='0'&&ch!='1')ch=getchar();
		s[i]=ch-'0';fac[i]=1ll*fac[i-1]*i%mod;
		Sum[i]+=Sum[i-1]+s[i];
	}for(int i=1;i<=n;i++)c[i]=read(),falure+=c[i]==0;
	sort(c+1,c+1+n);
	if(m>Sum[n]||n-falure<m)puts("0");
	if(n==Sum[n]&&falure==0)printf("%d",fac[n]);
	else printf("%d",dfs(1,0));
	return 0;
}
