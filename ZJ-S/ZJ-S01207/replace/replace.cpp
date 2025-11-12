#include<bits/stdc++.h>
using namespace std;
struct comd
{
	int l;
	int r;
	int tl;
	int tr;
}c[200005];
int n,q,b1,b2;
string a,b;
bool flag = 1;
map<int,map<int,int>> dp;
void dfs(int p,int lft,int rgt)
{
	if(p==n+1)
		return ;
	dfs(p+1,lft,rgt);
	if(c[p].l<=lft && c[p].r<=rgt)
	{
		dp[c[p].tl+lft-c[p].l][c[p].tr+rgt-c[p].r]+=dp[lft][rgt];
		dfs(p+1,c[p].tl+lft-c[p].l,c[p].tr+rgt-c[p].r);	
	}
	
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int j = 1;j <= n;j++)
	{
		cin>>a>>b;
		for(int i = 1;i <= a.size();i++)
		{
			if(a[i-1]=='b')
			{
				b1 = i;
				break;
			}	
			if(a[i-1]!='a' && a[i-1]!='b')
				flag = 0;
		}
		for(int i = 1;i <= b.size();i++)
		{
			if(b[i-1]=='b')
			{
				b2 = i;
				break;
			}
			if(a[i-1]!='a' && a[i-1]!='b')
				flag = 0;
		}
		c[j] = {b1-1,a.size()-b1,b2-1,b.size()-b2};
	}
	while(q--)
	{
		cin>>a>>b;
		dp.clear();
		for(int i = 1;i <= a.size();i++)
		{
			if(a[i-1]=='b')
			{
				b1 = i;
				break;
			}	
			if(a[i-1]!='a' && a[i-1]!='b')
				flag = 0;
		}
		for(int i = 1;i <= b.size();i++)
		{
			if(b[i-1]=='b')
			{
				b2 = i;
				break;
			}	
			if(b[i-1]!='a' && b[i-1]!='b')
				flag = 0;
		}
		if(flag && a.size()==b.size())
		{
			dp[b1-1][a.size()-b1] = 1;
			dfs(1,b1-1,a.size()-b1);	
			cout<<dp[b2-1][b.size()-b2];
		}
		else
			cout<<0<<'\n';
	}
	return 0;
}
