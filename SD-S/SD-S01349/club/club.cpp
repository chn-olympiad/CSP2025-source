#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans=-1;
int a[100005],b[100005],c[100005];
int cnt[4];
void dfs(int x,int sum){
	if(x==n+1){
		ans=max(ans,sum);
		return ;
	}
	cnt[1]++;
	if(cnt[1]<=n/2){
		dfs(x+1,sum+a[x]);
	}
	cnt[1]--;
	cnt[2]++;
	if(cnt[2]<=n/2){
		dfs(x+1,sum+b[x]);
	}
	cnt[2]--;
	cnt[3]++;
	if(cnt[3]<=n/2){
		dfs(x+1,sum+c[x]);
	}
	cnt[3]--;
}
int cmp(int a,int b){
	return a>b;
}
void solve() {
	cin>>n;
	ans=-1;
	int flag=0,flag2=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>b[i]>>c[i];
		if(b[i]>=1){
			flag=1;
		}
		if(c[i]>=1){
			flag2=1;
		}
	}
	if(flag==1){
		sort(a+1,a+n+1,cmp);
		int sum=0;
		for(int i=1;i<=n/2;i++){
			sum+=a[i];
		}
		cout<<sum<<"\n";
		return ;
	}
	
	dfs(1,0);
	cout<<ans<<"\n";
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
