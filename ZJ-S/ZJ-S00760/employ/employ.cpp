#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,i,j,fl,s,ans,p,b[510],f[510],c[510];char x,a[510];
void dfs(ll t){
	ll i;
	if(t>n){
		ll s=0,s1=0;
		for(i=1;i<=n;i++)
			if(a[i]=='0'||s>=b[c[i]])s++;
			else s1++;
		if(s1>=m)ans=(ans+1)%998244353;
		return;
	}
	for(i=1;i<=n;i++)
		if(!f[i])
			f[i]=1,c[t]=i,dfs(t+1),f[i]=0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);fl=0;getchar();
	for(i=1;i<=n;i++)scanf("%c",&x),a[i]=x;
	for(i=1;i<=n;i++)scanf("%d",&b[i]);
	dfs(1),printf("%d",ans);
	return 0;
}
