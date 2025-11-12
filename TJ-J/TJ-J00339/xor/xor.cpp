#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005];
bool is_1_2()
{
	for(int i=1;i<=n;i++) if(a[i]>1) return false;
	return true;
}
struct Node
{
	int f,s,l;
}v[5000005];
bool cmp(Node x,Node y)
{
	if(x.l==y.l) 
	{
		if(x.f==x.f) return x.s<x.s;
		return x.f<x.f;
	}
	return x.l<y.l;
}
bool f[2000006];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	if(is_1_2()&&(k==0||k==1))
	{
		int jsq=0;
		if(k==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0) jsq++;
				if(a[i]==1&&a[i+1]==1)
				{
					i++;
					jsq++;
				}
			}
		}
		else 
		{
			for(int i=1;i<=n;i++)
			    if(a[i]==1) jsq++;
		}
		cout<<jsq;
	}
	else
	{
		for(int i=1;i<=n;i++) sum[i]=sum[i-1]^a[i];
		
		int ans,lcq,x,y;
		int jsq=0,jsq1=0;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<=n;j++)
			{
				ans=0;
				lcq=1;
				x=sum[j];
				y=sum[i];
             	while(x||y)
            	{
	            	int a=x&1,b=y&1;
	             	if(a==0&&b==1) ans+=lcq;
	              	if(a==1&&b==0) ans+=lcq;
            		x>>=1;
             		y>>=1;
             		lcq*=2; 
            	}
            	if(ans==k)
            	{
            		++jsq;
            	    v[jsq].f=i+1;
                	v[jsq].s=j;
                	v[jsq].l=j-i;
				}
				
			}
        sort(v+1,v+1+jsq,cmp);
        bool z=1;
        for(int i=1;i<=jsq;i++)
        {
        	
        	for(int j=v[i].f;j<=v[i].s;j++)
        	    if(f[j]==1) 
        	    {
        	    	z=0;
        	    	break;
				}
			if(z)
			{
				jsq1++;
				for(int j=v[i].f;j<=v[i].s;j++) 
				{
					f[j]=1;
				}
			}
		}
		cout<<jsq1;
	}
	return 0;
}
