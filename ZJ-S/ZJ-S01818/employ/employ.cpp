#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
const int MOD=998244353;
ll n,m,a[N],t,f[N],x[N],vis[N],ans;
string s;
void DFS(ll k,ll pl)
{
	if(pl==m)
	{
		ans=(ans+f[n-k+1])%MOD;
		return;
	}
//	cout<<pl<<endl;
	if(k>n)return;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			if(s[k]=='1')
			{
				if(k-pl-1<a[i])DFS(k+1,pl+1);
				else DFS(k+1,pl);
			}
			else DFS(k+1,pl);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	f[1]=1;
	f[0]=1;
	for(int i=2;i<=n;i++)
	{
		f[i]=f[i-1]*i%MOD;
		//cout<<f[i]<<endl;
	}
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(s[i]=='0')t++;
	}
	/*if(t==0)
	{
		printf("%lld",f[n]);
	}*/
	for(int i=1;i<=n;i++)
	{
		x[i]=x[i-1]+(s[i]-'0');
	}
	if(m==1)
	{
		printf("%lld",f[n]);
		return 0;
	}
	DFS(1,0);
	cout<<ans;
}