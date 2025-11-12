#include<bits/stdc++.h>
#define int long long
namespace FastIO
{
	inline int read()
	{
		int x=0,f=1;
		char c=getchar();
		while(c<'0'||c>'9'){
			if(c=='-') f^=1;
			c=getchar();
		} 
		while(c>='0'&&c<='9'){
			x=(x<<3)+(x<<1)+(c^48);
			c=getchar();
		}
		return f?x:~x+1; 
	}
	inline void write(int x)
	{
		if(x<0) putchar('-'),x=~x+1;
		if(x>9) write(x/10);
		putchar(x%10^48);
	}
	inline void spaceput(int x)
	{
		write(x);putchar(' ');
	}
	inline void output(int x)
	{
		write(x);putchar('\n');
	}
} 
using namespace std;
using namespace FastIO;
constexpr int N=1e5+5;
constexpr int M=2e2+5;
constexpr int inf=1e14;
int t,n;
int dp[2][M][M],a[N][4],p[N];
void solve111()
{
	for(int i=0;i<2;i++){
		for(int j=0;j<M;j++){
			for(int k=0;k<M;k++){
				dp[i][j][k]=-inf;
			}
		}
	}
	int u=0,ans=0;dp[0][0][0]=0;
	for(int i=1;i<=n;i++){
		u^=1;
		for(int j=0;j<=i;j++){
			for(int k=0;j+k<=i;k++){
				dp[u][j][k]=max(dp[u][j][k],dp[u^1][j][k]+a[i][3]);
				if(j>0) dp[u][j][k]=max(dp[u][j][k],dp[u^1][j-1][k]+a[i][1]);
				if(k>0) dp[u][j][k]=max(dp[u][j][k],dp[u^1][j][k-1]+a[i][2]);
			}
		}
	}
	for(int i=0;i<=n/2;i++){
		for(int j=0;j<=n/2;j++){
			if(i<=n/2&&j<=n/2&&n-i-j<=n/2) ans=max(ans,dp[u][i][j]);
		}
	}
//	for(int i=0;i<M;i++){
//		for(int j=0;j<M;j++){
//			for(int k=0;k<M;k++){
//				dp[i][j][k]=-inf;
//			}
//		}
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(i<=n/2&&j<=n/2&&n-i-j<=n/2) cout<<i<<" "<<j<<" "<<n-i-j<<":"<<dp[n][i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	output(ans);
}
bool cmp(int x,int y)
{
	return x>y;
}
void solveA()
{
	for(int i=1;i<=n;i++) p[i]=a[i][1];
	sort(p+1,p+n+1,cmp);int ans=0;
	for(int i=1;i<=n/2;i++) ans+=p[i];
	output(ans);
}
struct node{
	int id,delta,c,unc;
	inline friend bool operator < (node A,node B){
		return A.delta>B.delta;
	}
};
void fanh()
{
	#define v1 v_1
	#define v2 v_2
	#define q1 q_1
	#define q2 q_2
	int ans=0;int ct[4]={};
	priority_queue<node> q1;
	priority_queue<node> q2;
	bitset<N> v1;//分别表示反悔1次与反悔2次
	v1.reset();
	while(!q1.empty()) q1.pop();
	while(!q2.empty()) q2.pop();
	for(int i=1;i<=n;i++){
		int mx=-inf,mn=inf,ix=0,in=0;
		for(int j=1;j<=3;j++){
			if(a[i][j]>mx) mx=a[i][j],ix=j;
			if(mn<a[i][j]) mn=a[i][j],in=j;
		}
		ans+=mx;ct[ix]++;
		q1.push({i,mx-a[i][6-ix-in],ix,6-ix-in});
		q2.push({i,a[i][6-ix-in],6-ix-in,in});
		for(int j=1;j<=3;){
			if(ct[j]>n/2){
				node now1=q1.top(),now2=q2.top();
				if(q1.size()&&(now1.delta<now2.delta||!v1[now2.id])){
					q1.pop();ans-=now1.delta;
					ct[now1.c]--,ct[now1.unc]++;
					v1[now1.id]=1;
				}
				else{
					if(q2.size()){
						q2.pop();ans-=now2.delta;
						ct[now2.c]--,ct[now2.unc]++;
					}
				}
				j=1;
			}
			else j++;
		}
	} 
	output(ans);
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		int flaga=1,flagb=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i][j]=read();
				if(j==2&&a[i][j]!=0) flaga=0;
				if(j==3&&a[i][j]!=0) flaga=flagb=0;
			}
		}
		if(n<=200) solve111();
		else{
			if(flaga) solveA();
			else fanh();
//			else if(flagB) solveB();
		}
	}
	return 0;
}
/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
ans:
147325

1
10
1 0 0 
2 0 0 
3 0 0
4 0 0
5 0 0
6 0 0
7 0 0
8 0 0
9 0 0 
10 0 0
*/
