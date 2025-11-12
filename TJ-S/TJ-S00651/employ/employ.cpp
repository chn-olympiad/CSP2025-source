#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int id,ans;
};
int a[100009],used[10009];
int n,m;
string s;
bool cmp(Node a,Node b)
{
	return a.id<b.id;
}
int ans;
void check()
{
	Node sz[1009];
	for(int i=1;i<=n;i++)
		sz[i].id=used[i],sz[i].ans=i;
	sort(sz+1,sz+n+1,cmp);
	int lost=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i-1]=='0'||lost>=a[sz[i].ans])
			lost++;
	}
	if(n-lost>=m)
		ans++;
}
void dfs(int a)
{
	if(a==n+1)
	{
		check();
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(used[i]==0)
		{
			used[i]=a;
			dfs(a+1);
			used[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}
