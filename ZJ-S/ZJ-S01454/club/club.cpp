#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
using namespace std;
const int N=1e5+10,M=1e2+10,MOD=1e9+7;
ll n,a[3][N],now[N];
vector<int> P[N];
struct node{
	ll idx,A;
	bool operator<(const node &x)const{return (x.A-a[P[x.idx][now[x.idx]+1]][x.idx])<(A-a[P[idx][now[idx]+1]][idx]);}
};
vector<node> G[3];
void solve(){
	cin>>n;
	for(int i=0;i<3;i++) G[i].clear();
	for(int i=1;i<=n;i++) P[i].clear();
	for(int i=1;i<=n;i++){
		ll maxx=0,op=-1;
		for(int j=0;j<3;j++){
			cin>>a[j][i];
			if(a[j][i]>=maxx){
				maxx=a[j][i];
				op=j;
			}
		}
		G[op].push_back({i,a[op][i]});
		now[i]=0;
		P[i].push_back(op);
		if(a[(op+2)%3][i]>=a[(op+1)%3][i]){
			P[i].push_back((op+2)%3);
			P[i].push_back((op+1)%3);
		}else{
			P[i].push_back((op+1)%3);
			P[i].push_back((op+2)%3);
		}
	}
	for(int i=0;i<3;i++){
		if(G[i].size()>(n/2)){
			sort(G[i].begin(),G[i].end());
			ll R=G[i].size()-1;
			while(R>=(n/2)){
				ll v=G[i][R].idx;
				now[v]++;
				G[P[v][now[v]]].push_back({v,a[P[v][now[v]]][v]});
				G[i].pop_back();
				R--;
			}
		}
	}
	ll ans=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<G[i].size();j++){
			ans+=G[i][j].A;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	IOS;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _=1;
	cin>>_;
	while(_--) solve();
	return 0;
}
