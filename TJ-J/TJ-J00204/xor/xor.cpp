#include<bits/stdc++.h>
using namespace std;
long long a[500010];
bool b[500010];
long long yi(long long x,long long y)
{
	if(x==y)
	{
		return 0;
	}
	int a[22]={},b[22]={};
	int k=1,h=1;
	while(x>0)
	{
		a[k]=x%2;
		x/=2;
		k++;
	}
	while(y>0)
	{
		b[h]=y%2;
		y/=2;
		h++;
	}
	int c[22]={};
	for(int i=1;i<max(k,h);i++)
		{
			if(a[i]==b[i])
			{
				c[i]=0;
			}
			else
			{
				c[i]=1;
			}
		}
	long long z;
	int p;
	for(int i=max(k,h)-1;i>=1;i--)
	{
		if(c[i]==1)
		{
			p=i;
			break;
		}
	}
	int j=0;
	for(int i=1;i<=p;i++)
	{
		z+=(c[i]*pow(2,j));
		j++;
	}
	return z;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,cnt=0;
	long long k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		b[i]=false;
		cin>>a[i];
		if(a[i]==k)
		{
			cnt++;
			b[i]=true;
		}
	}
	if(k==0)
	{
		cout <<0;
		return 0;
	}
	int l,r;
	for(int i=1;i<=n;i++)
	{
		if(b[i]==false)
		{
			l=i;
			r=l+1;
			break;
		}
	}
	for(int i=r;i<=n;i++)
	{
		if(b[i]==true)
		{
			r=i-1;
			break;
		}
	}
	while(r<=n)
	{
		for(int i=l+1;i<r;i++)
	    {
		    int ab=yi(a[i],a[i-1]);
		    if(ab==k)
		    {
			    cnt++;
			    l=r+2;
			    for(int j=l+1;j<=n;j++)
			    {
			    	if(b[j]==true)
			    	{
			    		r=j-1;
			    		j=n+1;
					}
				}
			    i=r;
		    }
		    else
		    {
			    a[i]=ab;
		    }
	    }
	}
	cout <<cnt;
	return 0;
}
