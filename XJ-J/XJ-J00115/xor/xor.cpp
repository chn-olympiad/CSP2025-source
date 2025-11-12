#include<bits/stdc++.h>
using namespace std;
long long  int n,k,a[500005],sum,s=0,r,l,v[500005],len;
int main()
{
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(k==0)
	{
		cout<<1;
		return 0;
	}
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		if(a[i]==1)
		{
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	
	for(l=1;l<=n;l++)
	for(r=1;r<=n;r++)
	{
		if(r-l==0)
		sum=a[l];
		if(r-l==1)
		sum=a[l]^a[r];
		else
	    {
	    	sum=a[l]^a[r];
	    	for(int i=l+2;i<=r;i++)
		    {
		    	
			    sum=sum^a[i];
		    }
		}
		int flag=0;
		if(sum==k)
		{
			if(r-l>len)
			len=r-l;
			for(int i=l;i<=r;i++)
			{
				if(v[i]==1)
				{
					flag=1;
					break ;
				}
			}
			if(flag==0)
			s++;
		}
	}
	cout<<s/2;
	return 0;
}
