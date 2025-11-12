#include<bits/stdc++.h>
#define N 100005
using namespace std;
#define int long long
typedef pair<int,int> pii;
int a[N][4];
int n,ans;
priority_queue<pii> q[4];
void solve(){
	for(int i=1;i<=3;++i){
		while(!q[i].empty()) q[i].pop();
	}
	cin>>n;
	ans=0;
	for(int i=1;i<=n;++i){
		int p=0;
		for(int j=1;j<=3;++j){
			cin>>a[i][j];
			if(a[i][j]>a[i][p]) p=j;
		}
		ans+=a[i][p];
		int d;
		if(p==1){
			d=max(a[i][2]-a[i][1],a[i][3]-a[i][1]);
		}else if(p==2){
			d=max(a[i][1]-a[i][2],a[i][3]-a[i][2]);
		}else{
			d=max(a[i][1]-a[i][3],a[i][2]-a[i][3]);
		}
		q[p].emplace(d,i);
	}
	int p=0;
	for(int i=1;i<=3;++i){
		if(q[i].size()>n/2) p=i;
	}
	if(p){
		while(q[p].size()>n/2) ans+=q[p].top().first,q[p].pop();
	}
	cout<<ans<<'\n';
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}
