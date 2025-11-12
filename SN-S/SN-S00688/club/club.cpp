#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll t;
ll a[100005][5];
ll b[100005][5];
struct P{
	ll first;
	ll second;
	ll third;
	bool operator > (const P& p)const{
		return this->first>p.first;
	}
};
priority_queue<P,vector<P>,greater<P>> pq[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		cin>>n;
		for(ll i=1;i<=n;++i){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			a[i][4]=-0x3f3f3f3f3f3f3f3f;
			ll i1=0,i2=0,i3=0;
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				i1=1;
				if(a[i][2]>=a[i][3]){
					i2=2;
					i3=3;
				} 
				else{
					i2=3;
					i3=2;
				} 
			}
			else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){
				i1=2;
				if(a[i][1]>=a[i][3]){
					i2=1;
					i3=3;
				} 
				else{
					i2=3;
					i3=1;
				} 
			}
			else{
				i1=3;
				if(a[i][1]>=a[i][2]){
					i2=1;
					i3=2;
				} 
				else{
					i2=2;
					i3=1;
				} 
			}
			b[i][1]=i1;
			b[i][2]=i2;
			b[i][3]=i3;
		}
		for(ll i=1;i<=n;++i){
			if(pq[b[i][1]].size()<n/2){
				pq[b[i][1]].push({a[i][b[i][1]]-a[i][b[i][2]],i,1});
			}	
			else{
				P p1=pq[b[i][1]].top();
				if(a[p1.second][b[p1.second][p1.third]]+a[i][b[i][2]]<a[i][b[i][1]]+a[p1.second][b[p1.second][p1.third+1]]){
					P p1=pq[b[i][1]].top();
					pq[b[i][1]].pop();
					pq[b[i][1]].push({a[i][b[i][1]]-a[i][b[i][2]],i,1});
					pq[b[p1.second][p1.third+1]].push({a[p1.second][b[p1.second][p1.third+1]]-a[p1.second][b[p1.second][p1.third+2]],p1.second,p1.third+1});
				}	
				else{
					pq[b[i][2]].push({b[i][2]-b[i][3],i,2});
				}
			}	
		}
		ll sum=0;
		while(!pq[1].empty()){
			sum+=a[pq[1].top().second][b[pq[1].top().second][pq[1].top().third]];
			pq[1].pop();
		}
		while(!pq[2].empty()){
			sum+=a[pq[2].top().second][b[pq[2].top().second][pq[2].top().third]];
			pq[2].pop();
		}
		while(!pq[3].empty()){
			sum+=a[pq[3].top().second][b[pq[3].top().second][pq[3].top().third]];
			pq[3].pop();
		}
		cout<<sum<<endl;
	}
	return 0;
}
