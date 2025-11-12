#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vel;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plpll;
typedef vector<vel> vevel;
typedef vector<pll> velp;
typedef priority_queue<ll> pql;
typedef priority_queue<pll> pqlp;
void slv(){
	ll n;
	cin>>n;
	vevel v(n+3,vel(4));
	for(int i=1;i<=n;i++){
		cin>>v[i][1]>>v[i][2]>>v[i][3];
	}
	pql q1,q2,q3;
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(v[i][1]>=v[i][2]&&v[i][1]>=v[i][3]){
			ans+=v[i][1];
			q1.push(max(v[i][2],v[i][3])-v[i][1]);
		}else if(v[i][2]>=v[i][1]&&v[i][2]>=v[i][3]){
			ans+=v[i][2];
			q2.push(max(v[i][1],v[i][3])-v[i][2]);
		}else{
			ans+=v[i][3];
			q3.push(max(v[i][1],v[i][2])-v[i][3]);
		}
	}
	while(q1.size()>n/2){
		ll qt=q1.top();
		q1.pop();
		ans+=qt;
	}
	while(q2.size()>n/2){
		ll qt=q2.top();
		q2.pop();
		ans+=qt;
	}
	while(q3.size()>n/2){
		ll qt=q3.top();
		q3.pop();
		ans+=qt;
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll T=1;
	cin>>T;
	while(T--){
		slv();
	}
	return 0;
}