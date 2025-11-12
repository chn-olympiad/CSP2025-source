#include<bits/stdc++.h>
#define ll long long
#define N (int)1e5+5
using namespace std;
ll m,n;
struct node{
	ll x[4];
	int fstv(){
		int ret=1;
		for(int i=1;i<=3;i++){
			if(x[i]>x[ret]){
				ret=i;
			}
		}
		return ret;
	}
	int scdv(){
		int mx=1,mn=1;
		for(int i=1;i<=3;i++){
			if(x[i]>x[mx]){
				mx=i;
			}
			if(x[i]<x[mn]){
				mn=i;
			}
		}
		if(mx==mn)return 1;
		return 6-mx-mn;
	}
	int cost(){
		return x[fstv()]-x[scdv()];
	}
};
node a[N];
struct pers{
	int x;
	pers(int _x):x(_x){};
	bool operator <(const pers &_t)const{
		return a[x].cost()>a[_t.x].cost();
	}
};

void solve(){
	priority_queue<pers>q[3];
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i].x[j];
		}
		q[a[i].fstv()].push(pers(i));
	}
	for(int i=1;i<=3;i++){
		while(q[i].size()>n/2){
			int x=q[i].top().x;
			q[i].pop();
			q[a[x].scdv()].push(pers(x));
		}
	}
	ll ans=0;
	for(int i=1;i<=3;i++){
		while(!q[i].empty()){
			int x=q[i].top().x;
			ans+=a[x].x[i];
			q[i].pop();
		}
	}
	cout<<ans<<'\n';
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>m;
	while(m--){
		solve();
	}
	return 0;
}
