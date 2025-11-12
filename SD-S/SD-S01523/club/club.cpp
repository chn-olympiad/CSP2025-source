#include<bits/stdc++.h>
using namespace std;
int a[100005][5];
int t,n,now;
long long ans;
void dfs(int x,int tot1,int tot2,int tot3,long long tot)
{
	if(x==1+n)
	{
		ans=max(ans,tot);
//		cout << tot << " " << tot1 << " " << tot2 << " " << tot3<< endl; 
		return; 
	}
	if(tot1 != n/2)
	{
		dfs(x+1,tot1+1,tot2,tot3,tot+a[x][1]);
	}
	if(tot2 != n/2)
	{
		dfs(x+1,tot1,tot2+1,tot3,tot+a[x][2]);
	}
	if(tot3 != n/2)
	{
		dfs(x+1,tot1,tot2,tot3+1,tot+a[x][3]);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{	
		cin >> n;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		dfs(1,0,0,0,0);
		cout << ans << endl;
	}
	return 0;	
	//问题：最大会占用后面的空间，所以要看绝对值max？ 
} 

