#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][4];
int ans;
void dfs(int k,int sum1,int sum2,int cnt) {
	if(sum1==n/2) {
		for(int i=k; i<=n; ++i) {
			cnt+=a[i][2];
		}
		ans=max(ans,cnt);
		return;
	} else if(sum2==n/2) {
		for(int i=k; i<=n; ++i) {
			cnt+=a[i][1];
		}
		ans=max(ans,cnt);
		return;
	} else {
		dfs(k+1,sum1+1,sum2,cnt+a[k][1]);
		dfs(k+1,sum1,sum2+1,cnt+a[k][2]);
	}
}
void bfs(int k,int sum1,int sum2,int sum3,int cnt) {
	if(k>n) {
		ans=max(ans,cnt);
		return;
	} else if(sum1==n/2&&sum2==n/2) {
		for(int i=k; i<=n; ++i) {
			cnt+=a[i][3];
		}
		ans=max(ans,cnt);
		return;
	} else if(sum1==n/2&&sum3==n/2) {
		for(int i=k; i<=n; ++i) {
			cnt+=a[i][2];
		}
		ans=max(ans,cnt);
		return;
	} else if(sum3==n/2&&sum2==n/2) {
		for(int i=k; i<=n; ++i) {
			cnt+=a[i][1];
		}
		ans=max(ans,cnt);
		return;
	} else {
		if(sum1<n/2)bfs(k+1,sum1+1,sum2,sum3,cnt+a[k][1]);
		if(sum2<n/2)bfs(k+1,sum1,sum2+1,sum3,cnt+a[k][2]);
		if(sum3<n/2)bfs(k+1,sum1,sum2,sum3+1,cnt+a[k][3]);
	}
}
void solve() {
	ans=0;
	bool f2=1,f3=1;
	cin>>n;
	for(int i=1; i<=n; ++i) {
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][2]!=0) f2=0;
		if(a[i][3]!=0) f3=0;
	}
	if(n==2) {
		for(int i=1; i<=3; ++i) {
			for(int j=1; j<=3; ++j) {
				if(i==j) continue;
				ans=max(ans,a[1][i]+a[2][j]);
			}
		}
		cout<<ans<<'\n';
		return;
	} else if(f2&&f3) {
		int b[100005];
		for(int i=1; i<=n; ++i) b[i]=a[i][1];
		sort(b+1,b+n+1,greater<int>());
		for(int i=1; i<=n/2; ++i) ans+=b[i];
		cout<<ans<<'\n';
		return;
	} else if(f3) {
		dfs(1,0,0,0);
		cout<<ans<<'\n';
		return;
	} else {
		bfs(1,0,0,0,0);
		cout<<ans<<'\n';
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		solve();
	}
	return 0;
}
