#include<bits/stdc++.h>
using namespace std;
const int N=1e5+4;
int t;
int n;
int a[N][4];
int d[N];
int dfs(int now,int sum,int lim1,int lim2,int lim3){
	if(lim1>n/2 || lim2>n/2 || lim3>n/2) return 0;
	if(now>n) return sum;
	return max(dfs(now+1,sum+a[now][1],lim1+1,lim2,lim3),max(dfs(now+1,sum+a[now][2],lim1,lim2+1,lim3),dfs(now+1,sum+a[now][3],lim1,lim2,lim3+1)));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(n<30) cout<<dfs(1,0,0,0,0)<<"\n";
		else{
			for(int i=1;i<=n;i++) d[i]=a[i][1];
			sort(d+1,d+n+1);
			int ans=0;
			for(int i=n;i>=n/2+1;i--) ans+=d[i];
			cout<<ans<<"\n";
		}
	}
	return 0;
}