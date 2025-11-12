#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb push_back
using namespace std;
const ll N=1e5+10;
ll a1[N],b1[N],c1[N];
ll ret,cnta,cntb,cntc,n,T;
struct node{
	ll val,id,op;
}a[N*3],b[N*3];
bool vis[3*N];
inline bool cmp(node a,node b){
	return a.val>b.val;
}
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>> >qa;
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>> >qb;
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>> >qc;
void init(){
	while(!qa.empty()) qa.pop();
	while(!qb.empty()) qb.pop();
	while(!qc.empty()) qc.pop();
}
inline bool check(node u){
	if(u.op==1&&cnta>=n/2) return false;
	if(u.op==2&&cntb>=n/2) return false;
	if(u.op==3&&cntc>=n/2) return false;
	return true;
}
void roota(node p){
	node u=b[p.id+n],v=b[p.id+2*n];
	ll rt;
	if(!check(u)&&check(v)) rt=p.val-v.val;
	else if(!check(v)&&check(u)) rt=p.val-u.val;
	else if(check(u)&&check(v))rt=p.val-max(u.val,v.val);
	else return;
	if(rt>qa.top().first){
		ret+=(rt-qa.top().first);
		ll x=qa.top().second;
		if(p.op==2) ++cntb;
		if(p.op==3) ++cntc;
		vis[p.id]=true;
	}
}
void rootb(node p){
	node u=b[p.id],v=b[p.id+2*n];
	ll rt;
	if(!check(u)&&check(v)) rt=p.val-v.val;
	else if(!check(v)&&check(u)) rt=p.val-u.val;
	else if(check(u)&&check(v))rt=p.val-max(u.val,v.val);
	else return;
	if(rt>qb.top().first){
		ret+=(rt-qb.top().first);
		ll x=qb.top().second;
		if(p.op==3) ++cntc;
		if(p.op==1) ++cnta;
		vis[p.id]=true;
	}
}
void rootc(node p){
	node u=b[p.id],v=b[p.id+n];
	ll rt;
	if(!check(u)&&check(v)) rt=p.val-v.val;
	else if(!check(v)&&check(u)) rt=p.val-u.val;
	else if(check(u)&&check(v))rt=p.val-max(u.val,v.val);
	else return;
	if(rt>qc.top().first){
		ret+=(rt-qc.top().first);
		ll x=qc.top().second;
		if(p.op==2) ++cntb;
		if(p.op==1) ++cnta;
		vis[p.id]=true;
	}
}
void dfs(ll x,ll ds,ll ca,ll cb,ll cc){
	if(x>n){
		ret=max(ret,ds);
		return;
	} 
	if(ca<n/2) dfs(x+1,ds+a1[x],ca+1,cb,cc);
	if(cb<n/2) dfs(x+1,ds+b1[x],ca,cb+1,cc);
	if(cc<n/2) dfs(x+1,ds+c1[x],ca,cb,cc+1);
}
bool f=true,fl=true;
void solve(){
	ret=cnta=cntb=cntc=0;
	//memset(vis,false,sizeof vis);
	cin>>n;
	if(n>20){
		init();
		ret=cnta=cntb=cntc=0;
		memset(vis,false,sizeof vis);
		cin>>n;
		for(ll i=1;i<=n;++i){
			cin>>a[i].val>>a[i+n].val>>a[i+2*n].val;
			a[i].id=a[i+n].id=a[i+2*n].id=i;
			a[i].op=1;a[i+n].op=2;a[i+2*n].op=3;
			b[i]=a[i],b[i+n]=a[i+n],b[i+2*n]=a[i+2*n];
			if((!a[i+n].val)&&(!a[i+2*n].val))f=true;
			else f=false;
			if((!a[i+2*n].val)) fl=true;
			else fl=false;
		}
		if(f){
			sort(a+1,a+n+1,cmp);
			for(ll i=1;i<=n/2;++i) ret+=a[i].val;
			cout<<ret<<endl;
			return ;
		}
		sort(a+1,a+3*n+1,cmp);
		for(ll i=1;i<=3*n;++i){
			if(a[i].op==1){
				if(!vis[a[i].id]&&cnta<(n/2)){
					vis[a[i].id]=true;
					ret+=a[i].val;
					++cnta;
					node u=b[a[i].id+n],v=b[a[i].id+2*n];
					ll rt;
					if(!check(u)&&check(v)) rt=a[i].val-v.val;
					else if(!check(v)&&check(u)) rt=a[i].val-u.val;
					else if(check(u)&&check(v))rt=a[i].val-max(u.val,v.val);
					else continue;
					qa.push({rt,i});
				}
				if(!vis[a[i].id]){
					roota(a[i]); 
				}
			}
			else if(a[i].op==2){
				if(!vis[a[i].id]&&cntb<(n/2)){
					vis[a[i].id]=true;
					ret+=a[i].val;
					++cntb;
					node u=b[a[i].id],v=b[a[i].id+2*n];
					ll rt;
					if(!check(u)&&check(v)) rt=a[i].val-v.val;
					else if(!check(v)&&check(u)) rt=a[i].val-u.val;
					else if(check(u)&&check(v))rt=a[i].val-max(u.val,v.val);
					else continue;
					qb.push({rt,i});
				}
				if(!vis[a[i].id]){
					rootb(a[i]);
				}
			}
			else if(a[i].op==3){
				if(!vis[a[i].id]&&cntc<(n/2)){
					vis[a[i].id]=true;
					ret+=a[i].val;
					++cntc;
					node u=b[a[i].id],v=b[a[i].id+n];
					ll rt;
					if(!check(u)&&check(v)) rt=a[i].val-v.val;
					else if(!check(v)&&check(u)) rt=a[i].val-u.val;
					else if(check(u)&&check(v))rt=a[i].val-max(u.val,v.val);
					else continue;
					qc.push({rt,i});
				}
				if(!vis[a[i].id]){
					rootc(a[i]);
				}
			}
		}
	}
	else{
		for(ll i=1;i<=n;++i){
			cin>>a1[i]>>b1[i]>>c1[i];
		}dfs(1,0,0,0,0);
	}
	cout<<ret<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) solve();
	return 0;
}
