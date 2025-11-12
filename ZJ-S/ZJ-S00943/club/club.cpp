#include<bits/stdc++.h>
#define int long long
const int N=200+10;
using namespace std;
int T;
int n;
//每一列都选最大
int a[5][N];
int dp[N][N/2][N/2];//前i个人 每个部门人数为 x，y,i-x-y不能超过一半
void solve1() {
	memset(dp,-0x3f,sizeof dp);//bro还真得写啊
	dp[0][0][0]=0;
	for(int i=0; i<n; i++) {
		for(int x=0; x<=n/2; x++) {
			for(int y=0; y<=n/2; y++) {
				if(x+1<=n/2) dp[i+1][x+1][y]=max(dp[i+1][x+1][y],dp[i][x][y]+a[1][i+1]);
				if(y+1<=n/2) dp[i+1][x][y+1]=max(dp[i+1][x][y+1],dp[i][x][y]+a[2][i+1]);
				if(i+1-x-y<=n/2) dp[i+1][x][y]=max(dp[i+1][x][y],dp[i][x][y]+a[3][i+1]);
			}
		}
	}
	int ans=0;
	for(int i=0; i<=n/2; i++)
		for(int j=0; j<=n/2; j++) {
			int z=n-i-j;
			if(z<=n/2) {
				ans=max(ans,dp[n][i][j]);
			}
		}
	cout<<ans<<"\n";
}
struct Node {
	int x,id;
	bool operator>(const Node &y)const {
		return x>y.x;
	}
};
void solve2() {
	priority_queue<Node,vector<Node>,greater<Node> > q;//小根堆
	int cnt=0;
	long long ans=0;
	for(int i=1; i<=n; i++) {
		ans=ans+a[1][i];
		cnt++;
		q.push({a[1][i],i});
		Node t=q.top();
//		cout<<t.x<<"测试中"; 
		if(cnt>n/2) {
			ans-=t.x;
			cnt--;
			q.pop();
		}
//		cout<<ans<<"测试中";
	}
	cout<<ans<<"\n";
}
void solve() {
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[1][i]>>a[2][i]>>a[3][i];
	if(n<=200) {
		solve1();
	}
	if(n>200) solve2();
}

signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		solve();
	}
	return 0;
}
