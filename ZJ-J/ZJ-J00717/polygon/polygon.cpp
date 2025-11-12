#include <bits/stdc++.h>
using namespace std;
long long n,a[5005],ans;
void dfs(int x,long long s,int y,long long maxx)
{
	if(x>n)
	{
		if(y<3)
		return;
		if(s<=maxx*2)
		return;
		ans++;
		return;
	}
	dfs(x+1,s+a[x],y+1,max(maxx,a[x]));
	dfs(x+1,s,y,maxx);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	dfs(1,0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
