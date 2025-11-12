//SN-S00566 程宇寒 西安市高新第二高级中学 
#include<bits/stdc++.h>
using namespace std;
long long n,t;
struct su
{
	long long yi,er,san;	
}a[100005];
int main()
{
	freopen("club1.in","r",stdin);
	freopen("club1.out","w",stdout);
	cin>>n;
	for(int k=1;k<=n;k++)
	{
		bool x=true,y=true,z=true;
		long long sum=0ll,b=0ll,c=0ll,d=0ll;
		cin>>t;
		for(int i=1;i<=t;i++)
		cin>>a[i].yi>>a[i].er>>a[i].san;
		for(int i=1;i<=t;i++)
		{
			long long maxx=0ll;
			if(x&&y&&z)
			{
				if(a[i].yi>=a[i].er&&a[i].yi>=a[i].san)
				{
					sum+=a[i].yi;
					b++;
					if(b==t/2) x=false;
				}
				else
				{
					if(a[i].er>=a[i].yi&&a[i].er>=a[i].san)
					{
						sum+=a[i].er;
						c++;
						if(c==t/2) y=false;
					}
					else
					{
						sum+=a[i].san;
						d++;
						if(d==t/2) z=false;
					}
				}
			} 
			else
			{
				if(!x)
				{
					if(a[i].er>=a[i].san)
					{
						sum+=a[i].er;
						c++;
						if(c==t/2) y=false;
					}
					else
					{
						sum+=a[i].san;
						d++;
						if(d==t/2) z=false;
					}
				}
				else
				{
					if(!y)
					{
						if(a[i].yi>=a[i].san)
						{
							sum+=a[i].yi;
							b++;
							if(b==t/2) x=false;
						}
						else
						{
							sum+=a[i].san;
							d++;
							if(d==t/2) z=false;
						}
					}
					else
					{
						if(a[i].yi>=a[i].er)
						{
							sum+=a[i].yi;
							b++;
							if(b==t/2) x=false;
						}
						else
						{
							sum+=a[i].er;
							c++;
							if(c==t/2) y=false;
						}
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
