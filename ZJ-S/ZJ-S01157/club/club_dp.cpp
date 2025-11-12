#include<bits/stdc++.h>
#define maxn (int)(201)
using namespace std;
int a[maxn],b[maxn],c[maxn];
int dp[2][maxn][maxn];

int n;
struct Node{
	int Delta_1;
	int id;
}nd[100005];
bool cmp(Node x,Node y){
	return x.Delta_1<y.Delta_1;
}
int main()
{
	freopen("club4.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;
	cin >> T;
	while(T--) {
		memset(dp,0,sizeof(dp));
		cin >> n;
		if(n<=200) {
			for(int i=1; i<=n; i++) {
				cin >> a[i] >> b[i] >> c[i];
			}
			int now = 0;
			for(int i=1; i<=n; i++) {
				now = 1^now;
				for(int j=0; j<=i; j++) {
					for(int k=0; k<=i; k++) {
						if((j+k)>i)continue;
						if(j>n/2||k>n/2)continue;
						if((i-j-k)>n/2)continue;
						if(j>0)dp[now][j][k]=max(dp[now][j][k],dp[now^1][j-1][k]+a[i]);
						if(k>0)dp[now][j][k]=max(dp[now][j][k],dp[now^1][j][k-1]+b[i]);
						dp[now][j][k]=max(dp[now][j][k],dp[now^1][j][k]+c[i]);
						//cout<< i << "-" << j << " " << k << " " << (i-j-k) << ":" << dp[i][j][k] << endl;
					}
				}
			}
			int ans=0;
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=n; j++) {
					ans = max(ans,dp[now][i][j]);
				}
			}
			cout  << ans << endl;
		}
		else {
			for(int i=1; i<=n; i++) {
				cin >> a[i] >> b[i] >> c[i];
				nd[i].Delta_1= a[i]-b[i];
				nd[i].id=i;
			}
			sort(nd+1,nd+n+1,cmp);
			
		}
	}
}