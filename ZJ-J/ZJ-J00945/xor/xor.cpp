#include<bits/stdc++.h>
using namespace std;
int a[1000000],n,k,l;
struct st{
	int l,r;
}f[1000000];
bool b[1000000];
int maxn;
void fun(int x,int tot)
{
	maxn=max(maxn,tot);
	if(x>=l)return;
	fun(x+1,tot);
	for(int i=f[x].l;i<=f[x].r;i++)
	{
		if(b[i])
		{
			for(int j=f[x].l;j<i;j++)
			b[i]=0;
			return;
		}
		b[i]=1;
	}
	fun(x+1,tot+1);
	for(int i=f[x].l;i<=f[x].r;i++)
	{
		b[i]=0;
	}
	return;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	cin>>a[i];
	for(int i=0;i<n;i++)
	{
		int t=0;
		for(int j=i;j<n;j++)
		{
			t^=a[j];
			if(t==k)
			{
				f[l].l=i;
				f[l].r=j;
				l++;
			}
		}
	}
	fun(0,0);
	cout<<maxn;
	return 0;
}
