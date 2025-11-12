#include<iostream>
#include<queue>
#include<algorithm> 
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
priority_queue<int> q[4];
const int N=1e5+5;
int T,n,ans;
int cnt[5];
vector<pii> a[N];
bool cmp(pii x,pii y){
	return x.fi>y.fi;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=0,x;j<3;j++) cin>>x,a[i].push_back(mp(x,j));
		sort(a[i].begin(),a[i].end(),cmp);
//		for(int j=0;j<3;j++) cout<<a[i][j].fi<<" "<<a[i][j].se<<'\n';
//		cout<<'\n';
	}
	for(int i=1;i<=n;i++){
		cnt[a[i][0].se]++;
		q[a[i][0].se].push(a[i][1].fi-a[i][0].fi);
		ans+=a[i][0].fi;
		if(cnt[a[i][0].se]>n/2){
			cnt[a[i][0].se]--;
			int x=q[a[i][0].se].top();
			q[a[i][0].se].pop();
			ans+=x;
		}
	}
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++) a[i].clear();
	for(int i=0;i<3;i++){
		cnt[i]=0;
		while(!q[i].empty()) q[i].pop();
	}
	ans=0;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--) solve();
	return 0;
}
/*
2
10 9 8
4 0 0
*/
