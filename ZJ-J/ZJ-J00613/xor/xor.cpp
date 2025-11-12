#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010];
int f[500010];
int yihuo(int a,int b)
{
	int ans=0,p=0,q=0;
	int x[1010],y[1010],z[1010];
	while(a)
	{
		p++;
		x[p]=a%2;
		a/=2;
	}
	while(b)
	{
		q++;
		y[q]=b%2;
		b/=2;
	}
	int l=max(p,q);
	for(int i=1;i<=l;i++)
	{
		if(x[i]==y[i])	z[i]=0;
		else	z[i]=1;
	}
	int f=1;
	for(int i=l;i>=1;i--)
	{
		ans+=z[i]*f;
		f*=2;
	}
	return ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=yihuo(f[i-1],a[i]);
	}
	int ans=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(yihuo(f[j],f[i-1])==k)
			{
				ans=max(ans,j-i);
			}
		}
	}
	cout<<ans;
	return 0;
}
