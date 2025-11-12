#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define int long long

const int N=1e5+5;

//int dp[N][N];

int a[N][4];

int n;

int dp[405][405][405];


void solve(){
//	int jisuan=0;
	cin>>n;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	int ans=0;
	for(int x=0;x<=n/2;x++){
		for(int y=0;y<=n/2;y++){
			for(int z=0;z<=n-x-y&&z<=n/2;z++){
				
				if(x!=0) dp[x%300][y%300][z%300]=max(dp[x%300][y%300][z%300],dp[(x-1)%300][y%300][z%300]+a[x+y+z][1]);
				if(y!=0) dp[x%300][y%300][z%300]=max(dp[x%300][y%300][z%300],dp[x%300][(y-1)%300][z%300]+a[x+y+z][2]);
				if(z!=0) dp[x%300][y%300][z%300]=max(dp[x%300][y%300][z%300],dp[x%300][y%300][(z-1)%300]+a[x+y+z][3]);
				ans=max(ans,dp[x%300][y%300][z%300]);
//				cout<<x<<" "<<y<<" "<<z<<" "<<ans<<" "<<dp[x&1][(y-1)&1][z&1]<<" "<<(x&1)<<" "<<(y&1)<<" "<<(z&1)<<endl;
//				jisuan++;
			}
		}
		cout<<x<<endl;
	}
	cout<<ans<<endl;
//	cout<<jisuan<<endl;
} 

signed main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	
	cin>>t;
	
	while(t--) solve();
}

/*
T1就这么难？

考虑DP

那我们所关心的状态是一号部门，二号部门，三号部门的人数，总满意程度

但是由于N过大

所以不可以定义DP[i][j][k]

注意到我们是枚举i

所以可以压缩成DP[i][j]

但是依旧开不了

有了，考虑贪心

先取所有人的最大值并加入桶中统计

写完后发现不能保证正确性

又回到dp

此时是15:34

dp写了个dp[x][y][z]

代表当三个部门人数为x,y,z时最大的满意度

时间复杂度O(N3)

期望得分50pts 

观察N的取值范围可以发现

这个dp肯定只有1维

那该怎么压缩状态啊

已经16:05

后面一道题也不会

而且连暴力也不会

16:42 发现可以用滚动数组

但时间复杂度依旧很高 

17:44了 刚打完T3暴力

期望总分75分

能拿几等奖啊

 
 
in:
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
out:
18
4
13
 
*/
