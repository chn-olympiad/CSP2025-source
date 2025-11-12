#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int a[N][5];
//bool cmp1(node a,node b){
//	return a.a>b.a;
//}
//bool cmp2(node a,node b){
//	return a.b>b.b;
//}
//bool cmp3(node a,node b){
//	return a.c>b.c;
//}
int ans=0,n,cnt[5],sum[5];
void dfs(int now,int j){
	if(cnt[j]>=n/2) {
		//cout<<now<<"\n";
		return;
	}
	if(now>n) {
		ans=max(ans,sum[1]+sum[2]+sum[3]);
		//cout<<sum[1]<<' '<<sum[2]<<' '<<sum[3]<<"\n";
		return;
	}
	
	sum[j]+=a[now][j];cnt[j]++;
	for(int i=1;i<=3;i++){
		dfs(now+1,i);
	}
	sum[j]-=a[now][j];cnt[j]--;
}

void solve(){
	for(int i=1;i<=3;i++) sum[i]=0,cnt[i]=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	if(n>=100000){
		int sum=0;
		for(int i=1;i<=n/2;i++) sum+=a[i][1];
		cout<<sum<<"\n";
		return;
	}
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=3;j++)
			dfs(i,j);

	cout<<ans<<"\n";
	ans=0;
//	for(int i=1;i<=n;i++){
//		for(int k=1;k<=3;k++)
//		for(int j=n/2;j>=0;j--){
//			dp[k][j]=dp[j],dp[j-1]+a[i];
//		}
//	}
	
}

//(dp[1][j-1]+a[i][1]+dp[2][l]+dp[3][n/2-j-l])



signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
}

