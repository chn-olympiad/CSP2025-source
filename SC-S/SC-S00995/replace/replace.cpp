#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,ans=0;
string s[N][2],t1,t2;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	while(m--)
	{
		cin>>t1>>t2;
		ans=0;
		for(int i=0;i<t1.size();i++)
		{
			for(int v=1;v<=n;v++)
			{
				bool flag=true;
				for(int z=0;z<i;z++)
				{
					if(t1[z]!=t2[z])flag=false;
				}
				for(int z=0;z<s[v][0].size();z++)
				{
					if(t1[z+i]!=s[v][0][z]||t2[z+i]!=s[v][1][z])flag=false;
				}
				for(int z=i+s[v][0].size();z<t1.size();z++)
				{
					if(t1[z]!=t2[z])flag=false;
				}
				if(flag)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}