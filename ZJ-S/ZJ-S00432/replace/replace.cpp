#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
int n,q,ans;
string s[204800][2],a,b;
void dfs(string c)
{
	if(mp[c]==1)
		return;
	mp[c]=1;
	if(c==b)
	{
		ans++;
		mp[c]=0;
		return;
	}
	for(int i=1;i<=n;i++)
		if(c.find(s[i][0])!=string::npos)
		{
			int tmp=c.find(s[i][0]);
			string d=c;
			for(int j=tmp;j<tmp+s[i][0].size();j++)
				d[j]=s[i][1][j-tmp];
			dfs(d);
		}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	while(q--)
	{
		mp.clear();
		for(int i=1;i<=n;i++)
			cin>>s[i][0]>>s[i][1];
		cin>>a>>b;
		if(a.size()!=b.size())
		{
			cout<<0<<endl;
			continue;
		}
		dfs(a);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
