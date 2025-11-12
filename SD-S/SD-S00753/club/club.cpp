#include<bits/stdc++.h>
using namespace std;
const int maxn=2e4+10;
int t,n,a[maxn],b[maxn],c[maxn],ans,r,m,s;
int d,e,f;
int main()
{
   freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		cin>>n;
	    for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		d=max(a[i],a[i-1]);
	    e=max(b[i],b[i-1]);
		f=max(c[i],c[i-1]);
		if(n==2) ans=max(d,max(e,f));
		else
		{
			if(a[i]!=b[i] && b[i]!=c[i])
		    {
			if(a[i]>b[i] && a[i]>c[i])
		    {
			r++;
			if(r<=n/2)  ans+=a[i];
			else
			{
				
				if(b[i]>c[i]) 
				{
					s++;
					ans+=b[i];
				}
				else 
				{
					m++;
					ans+=c[i];
				}
			} 
		    }
		
		else if(b[i]>a[i] && b[i]>c[i])
		{
			s++;
			if(s<=n/2) ans+=b[i];
			else
			{
				if(a[i]>c[i]) 
				{
					r++;
					ans+=a[i];
				}
				else 
				{
					m++;
					ans+=c[i];
				}
			} 
		}
	
		else if(c[i]>b[i] && c[i]>a[i])
		{
			m++;
			if(m<=n/2) ans+=c[i];
			else
			{
				if(b[i]>a[i]) 
				{
					s++;
					ans+=b[i];
				}
				else 
				{
					r++;
					ans+=c[i];
				}
			} 
		}		
		}
		}
	}
	
	cout<<ans<<endl;
	r=0;m=0;s=0;ans=0;
	}
	
	
	return 0;
}
