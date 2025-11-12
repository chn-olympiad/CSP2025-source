#include<bits/stdc++.h>
#define int long long
#define Mod 998244353
using namespace std;
int n,m,ans,jc[505],b[505],c[505],fl[505];
char x;
int read()
{
	int s=0; bool f=0; char c=getchar();
	for(;!isdigit(c);c=getchar()) f|=!(c^45);
	for(;isdigit(c);c=getchar()) s=(s<<1)+(s<<3)+(c^48);
	if(f) s=-s; return s;
}
void dfs(int x,int num)
{
	if(num==m) { ans=(ans+jc[n-x+1])%Mod; return; }
//	if(num>=m && x==n+1) ans=(ans+1)%Mod;
	if(n-x+1+num<m || x==n+1) return;
	for(int i=1;i<=n;i++)
		if(!fl[i]) fl[i]=1,dfs(x+1,num+c[x]*(num<b[i])),fl[i]=0;
	return;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m); jc[0]=1;
	for(int i=1;i<=n;i++) jc[i]=jc[i-1]*i%Mod;
	for(int i=1;i<=n;i++) cin>>x,c[i]=x-'0';
	for(int i=1;i<=n;i++) b[i]=read();
	dfs(1,0); cout<<ans;
	return 0;
}