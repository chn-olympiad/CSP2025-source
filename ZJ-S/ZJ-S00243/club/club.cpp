#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int n;
int a[100005][4];
int dp[105][105][105];
priority_queue<int> pq;
void func() {
	memset(dp,0,sizeof(dp));
	n=read();
	int flag=0,flag2=0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=3; j++) {
			a[i][j]=read();
			if(j!=1&&a[i][j]!=0)flag=1;
			if(j==3&&a[i][j]!=0)flag2=1;
			if(!flag&&a[i][j])pq.push(a[i][j]);
		}
	if(!flag) {
		int sum=0,cnt=0;
		while(cnt<n/2) {
			sum+=pq.top();
			pq.pop();
			cnt++;
		}
		cout<<sum<<'\n';
		return;
	}
	if(!flag2) {
		int ans=0;
		for(int i=1; i<=n; i++) {
			for(int k1=n/2; k1>=0; k1--) {
				for(int k2=n/2; k2>=0; k2--) {
					if(k1!=0)dp[k1][k2][1]=max(dp[k1-1][k2][1]+a[i][1],dp[k1][k2][1]);
					if(k2!=0)dp[k1][k2][1]=max(dp[k1][k2-1][1]+a[i][2],dp[k1][k2][1]);
					ans=max(ans,dp[k1][k2][1]);
				}
			}
		}
		cout<<ans<<'\n';
		return;
	}
	int ans=0;
	for(int i=1; i<=n; i++) {
		for(int k1=n/2; k1>=0; k1--) {
			for(int k2=n/2; k2>=0; k2--) {
				for(int k3=n/2; k3>=0; k3--) {
					if(k1!=0)dp[k1][k2][k3]=max(dp[k1-1][k2][k3]+a[i][1],dp[k1][k2][k3]);
					if(k2!=0)dp[k1][k2][k3]=max(dp[k1][k2-1][k3]+a[i][2],dp[k1][k2][k3]);
					if(k3!=0)dp[k1][k2][k3]=max(dp[k1][k2][k3-1]+a[i][3],dp[k1][k2][k3]);
					ans=max(ans,dp[k1][k2][k3]);
				}
			}
		}
	}
	cout<<ans<<'\n';
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--)func();
	return 0;
}

