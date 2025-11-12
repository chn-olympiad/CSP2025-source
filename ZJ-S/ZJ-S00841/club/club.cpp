#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<=k;++i)
#define per(i,j,k) for(int i=j;i>=k;--i)
int const N=1e5+10;
int n,ans,a[N][3],b[N],c[N][3],tot[3];
priority_queue< pair<int,int>,vector< pair<int,int> >,greater< pair<int,int> > >q[3];
inline void work(int id){
	ans-=q[id].top().first;
	int g=q[id].top().second;
	q[id].pop(),--tot[c[g][b[g]]],++b[g],++tot[c[g][b[g]]];
	if (b[g]<2) q[c[g][1]].push({a[g][c[g][2]]-a[g][c[g][1]],g});
}
inline void solve(){
	cin>>n,ans=tot[0]=tot[1]=tot[2]=0,memset(b,0,sizeof(b));
	rep(i,1,n) cin>>a[i][0]>>a[i][1]>>a[i][2];
	rep(i,0,2) while (!q[i].empty()) q[i].pop();
	rep(i,1,n){
		c[i][0]=0,c[i][1]=1,c[i][2]=2;
		if (a[i][c[i][0]]<a[i][c[i][1]]) swap(c[i][0],c[i][1]);
		if (a[i][c[i][0]]<a[i][c[i][2]]) swap(c[i][0],c[i][2]);
		if (a[i][c[i][1]]<a[i][c[i][2]]) swap(c[i][1],c[i][2]);
		ans+=a[i][c[i][0]],b[i]=0,++tot[c[i][0]];
		q[c[i][0]].push({a[i][c[i][0]]-a[i][c[i][1]],i});
	}
	while (1){
		if (tot[0]>n/2) work(0);
		else if (tot[1]>n/2) work(1);
		else if (tot[2]>n/2) work(2);
		else break;
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while (t--) solve();
	return 0;
}