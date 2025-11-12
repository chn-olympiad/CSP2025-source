#include<bits/stdc++.h>
using namespace std;
long long n,q,ans,num,x1[5000001],x2[5000001];
string s[200001][3],t1,t2;
map<string,string> qq;
bool pd(long long s1,long long s2)
{
	string r=t1.substr(s1,t1.size()-s1-s2),r2=t2.substr(s1,t1.size()-s1-s2);
	if(qq[r]==r2) 
		return true;
	return false;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
		num+=s[i][1].size()+s[i][2].size();
	}
	if(num>2000)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<s[i][1].size();j++)
				if(s[i][1][j]=='b')
				{
					x1[i]=j;
					break;
				}
			for(int j=0;j<s[i][2].size();j++)
				if(s[i][2][j]=='b')
				{
					x2[i]=j;
					break;
				}
		}
		while(q--)
		{
			ans=0;
			cin>>t1>>t2;
			if(t1.size()!=t2.size())
			{
				cout<<0<<endl;
				continue;
			}
			long long u=0,v=0;
			for(int j=0;j<t1.size();j++)
				if(t1[j]=='b')
				{
					u=j;
					break;
				}
			for(int j=0;j<t2.size();j++)
				if(t2[j]=='b')
				{
					v=j;
					break;
				}
			for(int i=1;i<=n;i++)
				if(x1[i]<=u&&s[i][1].size()-x1[i]<=t1.size()-u&&x2[i]<=v&&s[i][2].size()-x2[i]<=t2.size()-v&&u-x1[i]==v-x2[i])
					ans++;
			cout<<ans<<endl;
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		qq[s[i][1]]=s[i][2];
		qq[s[i][2]]=s[i][1];
	}
	while(q--)
	{
		ans=0;
		long long u=0,v=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<t1.size();i++)
			if(t1[i]!=t2[i])
			{
				u=i;
				break;
			}
		for(int i=t1.size()-1;i>=0;i--)
			if(t1[i]!=t2[i])
			{
				v=t1.size()-i-1;
				break;
			}
		for(int i=0;i<=u;i++)
			for(int j=0;j<=v;j++)
				if(pd(i,j))
					ans++;
		cout<<ans<<endl;
	}
	return 0;
}