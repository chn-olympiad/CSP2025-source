#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=2e5+10,M=5e6+10;
int n,m;
string s[M][2];
string t[M][2];
bool check(int id1,int pos,int id2)
{
	for(int i=pos,j=0;j<(signed)s[id2][0].size();j++,i++)
		if(t[id1][0][i]!=s[id2][0][j])
			return 0;
	return 1;
}
string calc(int id1,int pos,int id2)
{
	string s1=t[id1][0];
	for(int i=pos,j=0;j<(signed)s[id2][1].size();j++,i++)
		s1[i]=s[id2][1][j];
	return s1;
}
bool check()
{
	for(int i=1;i<=n;i++)
	{
		for(auto c:s[i][0])
			if(c!='a'&&c!='b')
				return 0;
		for(auto c:s[i][1])
			if(c!='a'&&c!='b')
				return 0;
	}
	for(int i=1;i<=m;i++)
	{
		for(auto c:t[i][0])
			if(c!='a'&&c!='b')
				return 0;
		for(auto c:t[i][1])
			if(c!='a'&&c!='b')
				return 0;
	}
	return 1;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=m;i++)
		cin>>t[i][0]>>t[i][1];
	if(!check())
	{
		for(int i=1;i<=m;i++)
		{
			int ans=0;
			for(int j=1;j<=n;j++)
			{
				for(int k=0;k+(signed)s[j][0].size()-1<(signed)t[i][0].size();k++)
				{
					if(check(i,k,j))
					{
						string s1=calc(i,k,j);
						if(s1==t[i][1])
							ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k+(signed)s[j][0].size()-1<(signed)t[i][0].size();k++)
			{
				if(check(i,k,j))
				{
					string s1=calc(i,k,j);
					if(s1==t[i][1])
						ans++;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}