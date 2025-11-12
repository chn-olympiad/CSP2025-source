#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define repr(i,a,b) for(int i = a;i <= b;i++)
#define maxn 305 
struct node{
	int f,s,t;
}a[100005];
int dp[maxn][maxn][maxn];
void solve(){
	int n;
	cin>>n;
	repr(i,1,n){
		cin>>a[i].f>>a[i].s>>a[i].t;
	}
	dp[1][1][0] = a[1].f;
	dp[1][0][1] = a[1].s;
	dp[1][0][0] = a[1].t;
	for(int i = 1;i <= n;i++){
	    for(int j = 1;j <= n/2;j++){
			for(int k = 1;k <= n/2;k++){
				if(n-j-k>n/2) break;
				if(n-j-k<=(n/2)) dp[i][j][k] = max(max(dp[i-1][j-1][k]+a[i].f,dp[i-1][j][k-1]+a[i].s),dp[i-1][j][k]+a[i].t);
			}
		}
	}
	cout<<dp[n][n/2][n/2]<<endl;
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= (n/2);j++){
//			for(int k = 1;k <= (n/2);k++){
//				cerr<<dp[j][k]<<" "<<j<<" "<<k<<endl;
//			}
//		}
//	}
}
//先考虑优化空间 
//滚完一维后发现空间还是不够
//继续优化 
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
/*namespace task1{
	int n;
	void read(){
		cin>>n;
		repr(i,1,n){
			cin>>a1[i]>>a2[i]>>a3[i];
		}
	}
	void solve(){
		sort(a1+1,a1+n+1);
		repr(i,1,n/2){
			sum+=a1[i];
		}
	}
	void print(){
		cout<<sum<<endl;
	}
}*/
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
*/
