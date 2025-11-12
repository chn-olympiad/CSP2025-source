//by xt66666
//TYZ
//IGVA
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int n,k,a[500010],b[500010],f[500010];
int pos[(1<<20)+10]; 
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<(1<<20)+9;i++)
	{
		pos[i]=998244353;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]^a[i];
	}
	/*for(int i=1;i<=n;i++)
	{
		cout<<b[i]<<' ';
	}
	cout<<endl;*/
	pos[0]=0;
	for(int i=1;i<=n;i++)
	{
		int nd=b[i]^k;
		if(pos[nd]==998244353)
		{
			f[i]=f[i-1];
		}
		else
		{
			f[i]=max(f[i-1],f[pos[nd]]+1);
		}
		pos[b[i]]=i;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,f[i]);
	}
	/*for(int i=1;i<=n;i++)
	{
		cout<<f[i]<<' ';
	}
	cout<<endl;*/
	cout<<ans;
	return 0;
}

