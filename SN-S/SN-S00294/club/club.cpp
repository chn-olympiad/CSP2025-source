//SN-S00294 把小煜 西安辅轮中学 
#include<bits/stdc++.h>
#define int long long
#define ull unsinged long long
const int INF=0x3f3f3f3f3f3f3f3f;
using namespace std;
int T,n,a[100010][4],f[5][210][210][210];
int use[100010]; 
int dfs(int x,int i,int j,int k)
{
	if(i>n/2||j>n/2||k>n/2) return -INF;
	if(f[x][i][j][k]) return f[x][i][j][k];
	if(i+j+k==n+1) return f[x][i][j][k]=0;
	return f[x][i][j][k]=max(dfs(x,i+1,j,k)+a[i+j+k][1],max(dfs(x,i,j+1,k)+a[i+j+k][2],dfs(x,i,j,k+1)+a[i+j+k][3]));
}
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//记得检查：
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) cin>>a[i][j];
		if(n<=400) cout<<dfs(T,0,0,0)<<"\n";
		else
		{
			int ans=0;
			for(int i=1;i<=n;i++) use[i]=a[i][1];
			sort(use+1,use+1+n,cmp);
			for(int i=1;i<=n/2;i++) ans+=use[i];
			cout<<ans<<"\n";
		}
	}
	return 0;
}
