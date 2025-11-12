#include<bits/stdc++.h>
#define ll long long
#define rep(i,x,y) for(int (i)=(x);(i)<=(y);++(i))
using namespace std;
const int N=1e5+10;

ll n,cnt[4],ans,vs[N];
struct node{
	ll a[4];
}t[N];
priority_queue<pair<ll,pair<ll,ll> > > q;
priority_queue<ll> dq[4];

void solve(){
    cin>>n;
    for(int i=1;i<=n;++i) vs[i]=0;
    for(int i=1;i<=3;++i) while(dq[i].size()) dq[i].pop();
    cnt[1]=cnt[2]=cnt[3]=ans=0;
    rep(i,1,n){
    	ll maxn=0;
    	rep(j,1,3){
    		
    		cin>>t[i].a[j];
    		maxn=max(maxn,t[i].a[j]);
//    		cout<<t[i].a[j]<<'\n';
		}
		rep(j,1,3){
			if(maxn==t[i].a[j]){
				q.push({t[i].a[j],{(ll)i,(ll)j}});
			}
		}
	}
	while(q.size()){
		auto [data,pos]=q.top();
		ll x=pos.first,y=pos.second;
		q.pop();
//		cout<<data<<' '<<x<<' '<<y<<'\n';
		if(vs[x]) continue;
		if(cnt[y]==n/2){
			ll xx=dq[y].top();
			ll maxn=0;
			for(int i=1;i<=3;++i){
				if(i==y) continue;
				maxn=max(maxn,t[x].a[i]);
			}
			if(xx+data>maxn){
				dq[y].pop();
				ans+=xx+data;
				dq[y].push(maxn-data);
				vs[x]=1;
			}
			else{
				ans+=maxn;
			}
		}
		else{
			ll maxn=0;
			for(int i=1;i<=3;++i){
				if(i==y) continue;
				maxn=max(maxn,t[x].a[i]);
			}
			cnt[y]++;
			vs[x]=1;
			ans+=data;
			dq[y].push(maxn-data);
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}