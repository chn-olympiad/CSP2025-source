#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,k,a[N],maxn,ans,arr[N];
string s;
void dfs(int x,int y,int z)
{
	int zz=z^a[x];
	if(x>n)
	{
		maxn=max(maxn,y);
		return ;
	}
	if(zz==k)
		dfs(x+1,y+1,0);
	else
		dfs(x+1,y,zz);
	dfs(x+1,y,z);
	return ;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
