#include<bits/stdc++.h>
using namespace std;
int n,m,b[1000];
string a;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++)
	{
		if(a[i]=='0')
		{
			cout<<0;
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	if(m==n)
	{
		bool flag=true;
		for(int i=1;i<=n;i++)
		{
			if(b[i]==0&&!flag)
			{
				cout<<0;
				return 0;
			}
			else if(b[i]==0) flag=false;
		}
		sort(b+1,b+n+1);
		int ans=1;
		for(int i=2;i<=n;i++)
		{
			if(b[i]==b[i-1])
			{
				int shu=1;
				for(int j=i;j<=n;j++)
				{
					if(b[j]!=b[j-1])
					{
						break;		
					}
					shu++;
				}
				ans*=shu;
			}
		}
		cout<<ans;
	}
	return 0;
} 
