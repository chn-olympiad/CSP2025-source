#include <bits/stdc++.h>
using namespace std;
string a[200020][2];
string q,w;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;

	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>q>>w;
		int ans=0;
		if(q.size()!=w.size())
		{
			cout<<"0"<<endl;
			continue;
		}
		else
		{
			int e=q.size(),r=0,t=0;
			string h,j,s,d;
			for(int i=0;i<=e-1;i++)
			{
				if(q[i]!=w[i])
				{
					r=i;
					break;
				}
			}
			for(int i=e-1;i>=0;i--)
			{	
				if(q[i]!=w[i])
				{
					t=i;
					break;
				}
			}
			for(int i=r;i<=t;i++)
			{
				h+=q[i];j+=w[i];
			}
			for(int i=1;i<=n;i++)
			{
				if(h==a[i][1]&&j==a[i][2])
				{
					ans++;
				}
			}
			s=h;d=j;
			for(int k=1;k<r;k++)
			{	
				h=q[r-k]+h;j=w[r-k]+j;
				for(int i=1;i<=n;i++)
					{
						if(h==a[i][1]&&j==a[i][2])
						{
							ans++;
						}
					}
			}
			h=s;j=d;
			for(int p=1;p<=e-t;p++)
			{	
				h=h+q[t+p];j=j+q[t+p];
				for(int i=1;i<=n;i++)
					{
						if(h==a[i][1]&&j==a[i][2])
						{
							ans++;
						}
					}
			}
			h=s;j=d;
			for(int k=1;k<=r;k++)
			{	
				h=q[r-k]+h;j=w[r-k]+j;
				s=h;d=j;
				for(int p=1;p<=e-t;p++)
				{
					h=h+q[t+p];j=j+q[t+p];
					for(int i=1;i<=n;i++)
					{
						if(h==a[i][1]&&j==a[i][2])
						{
							ans++;
						}
					}
					h=s;j=d;
				}
				
			}
			cout<<ans<<endl;
		}
	}
	
	return 0;
}
