#include<bits/stdc++.h>
using namespace std;
int n,a[5010],cnt;
void dfs(int top,int mx,int sum,int l)
{
	if(top == n + 1)
	{
		if(l >= 3 && 2 * mx < sum)cnt++;
		return;
	}
	dfs(top+1,max(mx,a[top]),sum+a[top],l+1);
	dfs(top+1,mx,sum,l);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1 ; i <= n ; i++)cin>>a[i];
	dfs(1,0,0,0);
	cout<<cnt;
	return 0;
}

