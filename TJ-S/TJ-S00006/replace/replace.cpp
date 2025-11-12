#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;//kmp
int n,q;
string s1[200010];
int ch[1010];
int ssum;
string s2[200010];
int vis[10010];
void dfs(int sum,int dif,int cnt)
{
	if(sum==dif)
	{
		ssum++;
	}
	for(int i=1;i<=cnt;i++)
	{
		if(!vis[ch[i]])
		{
			vis[ch[i]]=1;
			dfs(sum+s1[ch[i]].size(),dif,cnt);
			vis[ch[i]]=0;
		}
	}
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int k=1;k<=n;k++){
		cin>>s1[k]>>s2[k];
	}
	while(q--)
	{
		memset(vis,0,sizeof(vis));
		ssum=0;
		int cnt=0;
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			bool flag=1;
			for(int j=0;j<t1.size();j++)
			{
				for(int k=j;k+j<s1[i].size();k++)
				{
					if(t1[k]!=s1[i][k])
					{
						flag=0;
						break;
					}
				}
			}
			if(flag)
			{
				int f=1;
				for(int j=0;j<t2.size();j++)
				{
					for(int k=j;k+j<s2[i].size();k++)
					{
						if(t2[k]!=s2[i][k])
						{
							f=0;
							break;
						}
					}
				}
				if(f)
				{
					ch[++cnt]=i;
				}
			}
		}
		int dif=0;
		for(int i=1;i<=t1.size();i++)
		{
			if(t1[i]!=t2[i])dif++;
		}
		dfs(0,dif,cnt);
		cout<<ssum;
	}
	return 0;
 }
