#include<bits/stdc++.h>
using namespace std;
string a[200010],b[200010];string s1,s2;
int n,q,ans;
bool check(int l,int r)
{
	
	string sub="",g="";
	for(int i=l;i<=r;i++)
	{	
		sub+=s1[i];
		g+=s2[i];
	}
	//cout<<sub<<" "<<g<<endl;
	for(int i=1;i<=n;i++)
	{
		if(sub==a[i]&&g==b[i])return 1;
	}
	return 0;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	while(q--)
	{
		cin>>s1>>s2;ans=0;
		int u,v,sz=s1.size();
		for(int i=0;i<=sz;i++)
		{
			if(s1[i]!=s2[i])u=i;
			if(s1[sz-i-1]!=s2[sz-i-1])v=sz-i-1;
		}
		swap(u,v);
		for(int i=0;i<sz;i++)
		{
			for(int j=i;j<sz;j++)
			{
				if(i<=u&&j>=v)
				{
					if(check(i,j))ans++;
					
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
