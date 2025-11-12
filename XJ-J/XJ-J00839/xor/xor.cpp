#include<bits/stdc++.h>
using namespace std;
long long int a[1000005],b[1000005],v,f,i,c,d,j,n,t,k,maxn=-100;
struct node
{
	int l,r;
}s[1000005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==1)
		{
			b[1]=a[1];
		}
		else
		b[i]=a[i]^b[i-1];
		if(a[i]==1)
		{
			v++;
		}
	}
	if(k<=1)
	{
		cout<<v;
		return 0;
	}
	for(i=1;i<=n;i++)
	for(j=i;j<=n;j++)
	{
		if((b[j]-b[i-1])==k)
		{
			s[++t]={i,j};
			f=1;
		}
	}
	if(f==1)
	{
		c=s[1].l;d=s[1].r;maxn=t;
	for(i=2;i<=t;i++)
	{	
			if(s[i].l<c&&s[i].r<c||s[i].l>d&&s[i].r>d)
			{
				c=s[i].l;d=s[i].r;
				maxn--;
			}	
	}
	}
	
	cout<<maxn;
	return 0;
}
