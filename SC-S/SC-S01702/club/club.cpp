#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(a);i<=(b);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using LL=long long;
using VI=vector<int>;
void solve(){
	int n;cin>>n;
	vector<array<array<int,2>,3>> a(n);
	vector<VI> cnt(3);
	FOR(i,0,n){
		cin>>a[i][0][0]>>a[i][1][0]>>a[i][2][0];
		a[i][0][1]=0,a[i][1][1]=1,a[i][2][1]=2;
		sort(begin(a[i]),end(a[i]));
		cnt[a[i][2][1]].push_back(i);
	}
	int ans=0;
	FOR(i,0,3){
		if((int)cnt[i].size()<=n/2){
			FOR(j,0,(int)cnt[i].size())ans+=a[cnt[i][j]][2][0];
			continue;
		}
		auto cmp=[&](int x,int y){
			return a[x][2][0]-a[x][1][0]>a[y][2][0]-a[y][1][0];
		};
		sort(begin(cnt[i]),end(cnt[i]),cmp);
		FOR(j,0,n/2)ans+=a[cnt[i][j]][2][0];
		FOR(j,n/2,(int)cnt[i].size())ans+=a[cnt[i][j]][1][0];
	}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--)solve();
	return 0;
}
