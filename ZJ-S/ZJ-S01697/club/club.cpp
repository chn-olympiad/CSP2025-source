#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const ll N=1e5+5;
struct Stu{
	ll x;
	ll y;
	ll z;
}a[N];
struct Node{
	ll id;
	ll x;
	ll gr;
	bool operator < (const Node &h) const{
		return h.x>x;
	}
};
bool cmp(Stu p,Stu q){
	return p.x-p.y>q.x-q.y;
}
priority_queue<Node> q;
priority_queue<ll> t[2];
int vis[N];
void solve(){
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
		vis[i]=0;
	}
	ll tmp=n/2;
	ll ans=0;
	ll u=0;
	while(!q.empty()) q.pop();
	while(!t[0].empty()) t[0].pop();
	while(!t[1].empty()) t[1].pop();
	for(ll i=1;i<=n;i++){
		ans+=a[i].x;
		u++;
		q.push({i,a[i].y-a[i].x,0});
		q.push({i,a[i].z-a[i].x,1});
	}
	vector<Stu> tr;
	while(!q.empty()){
		Node kkk=q.top();
		q.pop();
		if(kkk.x<0&&u<=tmp) break;
		if(vis[kkk.id]==0){	
			if(t[kkk.gr].size()<tmp){
				vis[kkk.id]=1;
				u--;
				ans-=a[kkk.id].x;
				if(kkk.gr==0){
					ans+=a[kkk.id].y;
					t[kkk.gr].push(a[kkk.id].z-a[kkk.id].y);
				}	
				else{
					ans+=a[kkk.id].z;
					t[kkk.gr].push(a[kkk.id].y-a[kkk.id].z);
				}	
			}
			else{
				if(t[kkk.gr].top()+kkk.x>0){
					if(kkk.gr==0){
						u--;
						vis[kkk.id]=1;
						ans-=a[kkk.id].x;
						ans+=t[kkk.gr].top();
						t[kkk.gr].pop();
						ans+=a[kkk.id].y;
						t[kkk.gr].push(a[kkk.id].y-a[kkk.id].z);
						t[kkk.gr^1].push(a[kkk.id].z-a[kkk.id].y);
					} 
					else{
						u--;
						vis[kkk.id]=1;
						ans-=a[kkk.id].x;
						ans+=t[kkk.gr].top();
						t[kkk.gr].pop();
						ans+=a[kkk.id].z;
						t[kkk.gr].push(a[kkk.id].y-a[kkk.id].z);
						t[kkk.gr^1].push(a[kkk.id].y-a[kkk.id].z);
					} 
				}
			}	
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll _;
	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}
