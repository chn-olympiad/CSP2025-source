#include<bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define ll long long
#define itn int
#define int ll
using namespace std;
const int MOD1=1e9+7;
const int MOD2=998244353;
const int N=2e2+5;
const int M=1e5+5;
int n,b[M],a[M][10],dp[N][N>>1][N>>1];
vector<tuple<int,int,int> > c;
int dfs(int i,int x,int y){
	if(dp[i][x][y]!=-1)
		return dp[i][x][y];
	if(i==n+1)
		return 0;
	int res=0;
	if(x+1<=n/2)
		res=max(res,dfs(i+1,x+1,y)+a[i][1]);
	if(y+1<=n/2)
		res=max(res,dfs(i+1,x,y+1)+a[i][2]);
	if(i-x-y<=n/2)
		res=max(res,dfs(i+1,x,y)+a[i][3]);
	return dp[i][x][y]=res;
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++)
			cin>>a[i][j];
	bool A=1,B=1;
	for(int i=1;i<=n;i++){
		A&=(a[i][2]==0 and a[i][3]==0);
		B&=(a[i][3]==0);
	}
	if(A){
		for(int i=1;i<=n;i++)
			b[i]=a[i][1];
		sort(b+1,b+n+1,greater<int>());
		int res=0;
		for(int i=1;i<=n/2;i++)
			res+=b[i];
		cout<<res<<endl;
		return;
	}
	if(B){
		c.clear();
		for(int i=1;i<=n;i++)
			c.pb(make_tuple(-a[i][1]+a[i][2],-a[i][1],-a[i][2]));
		sort(c.begin(),c.end());
		int res=0;
		for(int i=1;i<=n;i++){
			if(i<=n/2)
				res-=get<1>(c[i-1]);
			else
				res-=get<2>(c[i-1]);
		}
		cout<<res<<endl;
		return;
	}
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n/2;j++)
			for(int k=0;k<=n/2;k++)
				dp[i][j][k]=-1;
	cout<<dfs(1,0,0)<<endl;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;
	cin>>T;
	while(T--)
		Solve();
	return 0;
}
