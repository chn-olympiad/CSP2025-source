#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,ans;
struct node
{
	int x,y,z;
};
node a[N];
bool cmpa(node n1,node n2)
{
	return n1.x>n2.x;
}
void dfs(int dth,int cntx,int cnty,int cntz,int sum)
{
	if(dth>n)
	{
		ans=max(ans,sum);
		return ;
	}
	if(cntx+1<=n/2) dfs(dth+1,cntx+1,cnty,cntz,sum+a[dth].x);
	if(cnty+1<=n/2) dfs(dth+1,cntx,cnty+1,cntz,sum+a[dth].y);
	if(cntz+1<=n/2) dfs(dth+1,cntx,cnty,cntz+1,sum+a[dth].z);
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		ans=0;
		bool fa=1;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y or a[i].z) fa=0;
		}
		if(fa) 
		{
			sort(a+1,a+n+1,cmpa);
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i].x;
			}
		}
		else dfs(1,0,0,0,0);
		cout<<ans<<'\n';
	}
	
	
	return 0;
}