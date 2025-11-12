#include<bits/stdc++.h>
using namespace std;
int T,n,maxx,ans;
int a[100010][5];
int b[100010];
inline void dfs(int num,int x,int y,int z,int cnt)
{
	if (x>maxx||y>maxx||z>maxx) return;
	if (num==n){
		ans=max(ans,cnt);
		return;
	}
//	cout<<num<<" "<<x<<" "<<y<<" "<<z<<" "<<cnt<<endl;
	dfs(num+1,x+1,y,z,cnt+a[num+1][1]);
	dfs(num+1,x,y+1,z,cnt+a[num+1][2]);
	dfs(num+1,x,y,z+1,cnt+a[num+1][3]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while (T--)
	{
		cin>>n;
		maxx=n/2;
		ans=0;
		memset(a,sizeof(a),0);
//		memset(num,sizeof(num),0);
//		memset(dp,sizeof(dp),0);
		for (int i=1;i<=n;i++)
		  for (int j=1;j<=3;j++)
		    cin>>a[i][j];
		dfs(0,0,0,0,0);
		cout<<ans<<endl;
	}
}
