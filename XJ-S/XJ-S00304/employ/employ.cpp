#include<bits/stdc++.h>
using namespace std;
int a[505],v[505],maxn;
int n,m;
string s;
void dfs(int l,int lu)
{
	if(l>n)
	{
		if(lu>=m)
		maxn++;
		maxn%=998244353;
		return ;
	}
	for(int i=1;i<=n;i++)
	if(v[i]==0)
	{
		v[i]=1;
		if(l-lu-1<a[i])
		{
			if(s[l-1]=='0')
			{
				dfs(l+1,lu);
			}
			else
			dfs(l+1,lu+1);
		}
		else
		dfs(l+1,lu);
		v[i]=0;
	}
	return ;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	dfs(1,0);
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
