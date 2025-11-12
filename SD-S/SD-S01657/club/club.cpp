#include <bits/stdc++.h>
using namespace std;
int t,n,a[100100][3],ans,b[100100];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;
		int f=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if((a[i][1]||a[i][2])!=0) 
				f=1;
		}
		if(f==0)
		{
			memset(b,0,sizeof(b));
			for(int i=1;i<=n;i++)
				b[i]=a[i][0];
			sort(b+1,b+n+1,cmp);
			for(int i=1;i<=n/2;i++)
				ans+=b[i];
			cout<<ans<<endl;
			continue;
		}
		else if(n==2)
		{
			int q=0,w=0,e=0,r=0,x=0,y=0;
			for(int i=0;i<3;i++)
			{
				if(a[1][i]>q)
				{
					q=a[1][i];
					w=i;
				}
			}
			for(int i=0;i<3;i++)
			{
				if(a[2][i]>e)
				{
					e=a[2][i];
					r=i;
				}
			}
			for(int i=0;i<3;i++)
			{
				if(a[1][i]>x&&a[1][i]!=q)
					x=a[1][i];
			}
			for(int i=0;i<3;i++)
			{
				if(a[2][i]>y&&a[2][i]!=e)
					y=a[2][i];
			}
			if(w!=r)
			{
				ans=q+e;
				cout<<ans<<endl;
				continue;
			}
			else
			{
				ans=max(q+y,e+x);
				cout<<ans<<endl;
				continue;
			}
		}
		else if(n>=4)
		{
			int x=0,y=0,z=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])
				{
					if(x+1<=n/2)
					{
						x++,ans+=a[i][0];
					}
				}
				else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2])
				{
					if(x+1<=n/2)
					{
						x++,ans+=a[i][1];
					}
				}
				else
				{
					if(x+1<=n/2)
					{
						x++,ans+=a[i][2];
					}
				}
			}
			cout<<ans<<endl;
		}
	} 
	return 0;
}
