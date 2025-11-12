#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node{
	string s1,s2;
}s[200005];
bool vis[200005];
string t1,t2;
int ans=0;
int cnt=0;
void dfs(int step)
{
	if(step>30)
	{
		return;
	}
	if(t1==t2)
	{
		ans++;
		return;
	}
	for(int i=1;i<=t1.size()-1;i++)
	{
		for(int j=i+1;j<=t1.size()-1;j++)
		{
			for(int k=1;k<=n;k++)
			{
				string t3=t1;
				string t4=t1.substr(i,j-i+1);
				if(!vis[k] && t4==s[k].s1)
				{
					vis[k]=true;
					t1.erase(i,j-i+1);
					t1.insert(i,s[k].s2);
					dfs(step+1);
					t1=t3;
					vis[k]=false;
				}
			}
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].s1;
		cin>>s[i].s2;
	}
	if(q<=100)
	{
		while(q--)
		{
			ans=0;
			cin>>t1>>t2;
			t1=" "+t1;
			t2=" "+t2;
			dfs(1);
			cout<<ans<<endl;
		}
	}
	else
	{
		while(q--)
		{
			cout<<0<<endl;
		}
	}
}

