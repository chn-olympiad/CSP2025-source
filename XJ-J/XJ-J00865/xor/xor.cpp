#include<bits/stdc++.h> 
using namespace std;
long long int i,k,maxn,a[100005],n,l,r,s,j,b[100005],c[100005],d[100005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<=n;i++)
	for(l=1;l<=n-i;l++)
	{
		r=l+i;
		s=a[l];
		for(j=l+1;j<=r;j++)
		{
			s=s^a[j];
		}
		if(s==k)
		if(l>d[s]||r<c[s]||b[s]==0)
		{
			b[s]++;
			if(c[s]==0)
			c[s]=l;
			else
			c[s]=min(l,c[s]);
			d[s]=max(r,d[s]);
		}
	}
	for(i=0;i<=100000;i++)
	if(b[i]>maxn)
	maxn=b[i];
	cout<<maxn;
	return 0;
}
