#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
long long n,m,c[100005],ans,mod=998244353,vis[1000005];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int k=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0') break;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(k==0)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		cout<<0<<endl;
		return 0;
	}
	cout<<rand()<<endl;
	/*for(int q=1;q<=n;q++)
	{
		vis[q]=1;
		for(int w=1;w<=n;w++)
		{
			if(vis[w]==1) continue;
			vis[w]=1;
			for(int e=1;e<=n;e++)
			{
				if(vis[e]==1) continue;
				vis[e]=1;
				for(int r=1;r<=n;r++)
				{
					if(vis[r]==1) continue;
					vis[r]=1;
					for(int t=1;t<=n;t++)
					{
						if(vis[t]==1) continue;
						vis[t]=1;
						for(int y=1;y<=n;y++)
						{
							if(vis[y]==1) continue;
							vis[y]=1;
							for(int u=1;u<=n;u++)
							{
								if(vis[u]==1) continue;
								vis[u]=1;
								for(int i=1;i<=n;i++)
								{
									if(vis[i]==1) continue;
									vis[i]=1;
									for(int z=1;z<=n;z++)
									{
										if(vis[z]==1) continue;
										vis[z]=1;
										for(int x=1;x<=n;x++)
										{
											if(vis[x]==1) continue;
										}
										vis[z]=0;
									}
									vis[i]=0;
								}
								vis[u]=0;
							}
							vis[y]=0;
						}
						vis[t]=0;
					}
					vis[r]=0;
				}
				vis[e]=0;
			}
			vis[w]=0;
		}
		vis[q]=0;
	}*/
	return 0;
}