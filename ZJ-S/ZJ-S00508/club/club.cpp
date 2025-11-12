#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int main()
{
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--)
	{
	
		int n;cin>>n;
	    int a[maxn],b[maxn],c[maxn];
		for(int i=1;i<=n;i++)
		{
		   cin>>a[i]>>b[i]>>c[i];
		}		
		if(n==2)
		{	long long ans=0;
			ans=max(a[1]+b[2],max(a[1]+c[2],max(a[2]+b[1],max(a[2]+c[1],max(b[1]+c[2],c[1]+b[2])))));
			cout<<ans<<'\n';
		}
		else
		{
			bool f=0;
			for(long long i=1;i<=n;i++)
			{
				if(b[i]!=0||c[i]!=0) f=1;
			 }
			if(!f)
			{
				long long ans=0;
				sort(a+1,a+n+1);
				for(long long i=n;i>n/2;i--)
				{
					ans+=a[i];
				}
				cout<<ans<<'\n';
			}
		    else
		    {
				bool f1=0;
				for(long long i=1;i<=n;i++)
				{
					if(a[i]!=0||c[i]!=0) f1=1;
				}
			    if(!f1)
				{
					long long ans=0;
					sort(b+1,b+n+1);
					for(long long i=n;i>n/2;i--)
					{
						ans+=b[i];
					}
					cout<<ans<<'\n';
				}
				else
				{
					bool f2=0;
					for(long long i=1;i<=n;i++)
					{
						if(a[i]!=0||b[i]!=0) f2=1;
					}
					if(!f2)
					{
						long long ans=0;
						sort(c+1,c+n+1);
						for(long long i=n;i>n/2;i--)
						{
							ans+=c[i];
						}
						cout<<ans<<'\n';
					}
					 else
					{
						long long ans=0;
						for(long long i=1;i<=n;i++)
						{
						  ans+=max(a[i],max(b[i],c[i]));
						}
						cout<<ans<<'\n';
					}
				}
			
			}
	
		}
	
	}
	return 0;
}

