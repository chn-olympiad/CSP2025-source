#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
using namespace std;
#define ll long long
#define N 10001
#define K 11
inline ll maxll(ll a,ll b){
	return (a>b?a:b);
}
inline ll minll(ll a,ll b){
	return (a<b?a:b);
}
struct node{
	ll v,w;
};
struct vide{
	ll u,v,w;
	friend bool operator<(const vide& a,const vide& b){
		return a.w>b.w;
	}
};
ll n,m,k,x,y,z,d[K][N],ans;
vector<node> v[N+K];
priority_queue<vide> q;
namespace f1{
	ll fa[N+K],f;
	ll rebuildfa(ll x,ll y){
		//cout<<x<<' '<<y<<endl;
		if(x==y){
			return fa[x];
		}
		ll fd=rebuildfa(fa[fa[x]],fa[x]);
		fa[x]=fa[y]=fd;
		return fd;
	}
	void solution(){
		for(ll i=1;i<=m;i++){
			cin>>x>>y>>z;
			v[x].push_back((node){y,z});
			v[y].push_back((node){x,z});
			q.push(vide{x,y,z});
		}
		for(ll i=1;i<=k;i++){
			for(ll j=0;j<=n;j++){
				cin>>d[i][j];
			}
		}
		for(ll i=1;i<=n;i++){
			fa[i]=i;
		}
		f=n-1;
		while(f>0&&!q.empty()){
			vide t=q.top();
			q.pop();
			if(fa[t.u]!=fa[t.v]){
				ans+=t.w;
				//cout<<t.u<<' '<<t.v<<' '<<t.w<<endl;
				rebuildfa(t.u,t.v);
//				for(ll i=1;i<=n;i++){
//					cout<<fa[i]<<' ';
//				}
//				cout<<endl;
				f--;
			}
			else{
//				cout<<"pop"<<t.u<<' '<<t.v<<' '<<t.w<<endl;
			}
		}
		cout<<ans<<endl;
		return;
	}
}
namespace f2{
	ll fa[N+K],anst;
	ll f[K];
	ll rebuildfa(ll x,ll y){
		//cout<<x<<' '<<y<<endl;
		if(x==y){
			return fa[x];
		}
		ll fd=rebuildfa(fa[fa[x]],fa[x]);
		fa[x]=fa[y]=fd;
		return fd;
	}
	void solution(ll ln){
		for(ll i=1;i<=ln;i++){
			fa[i]=i;
		}
		ll f=ln-1;
		while(f>0&&!q.empty()){
			vide t=q.top();
			q.pop();
			if(fa[t.u]!=fa[t.v]){
				anst+=t.w;
				//cout<<t.u<<' '<<t.v<<' '<<t.w<<endl;
				rebuildfa(t.u,t.v);
//				for(ll i=1;i<=n;i++){
//					cout<<fa[i]<<' ';
//				}
//				cout<<endl;
				f--;
			}
			else{
//				cout<<"pop"<<t.u<<' '<<t.v<<' '<<t.w<<endl;
			}
		}
		//cout<<anst<<'|'<<endl;
		ans=minll(ans,anst);
		return;
	}
	void dfs(ll nt,ll nd,ll fin){
		if(nt==fin+1){
			anst=0;
			for(ll j=1;j<=n;j++){
				for(ll x=0;x<v[j].size();x++){
					q.push(vide{j,v[j][x].v,v[j][x].w});
				}
			}
			//cout<<"d||"<<endl;
			for(ll j=1;j<=fin;j++){
				for(ll x=1;x<=n;x++){
					q.push(vide{n+j,x,d[f[j]][x]});
				}
				anst+=d[f[j]][0];
			}
			//cout<<"d||"<<anst<<endl;
			solution(n+fin);
			return;
		}
		else if(nd>fin){
			return;
		}
		else{
			for(ll i=nd;i<=fin;i++){
				f[nt]=i;
				dfs(nt+1,i+1,fin);
			}
			return;
		}
	}
	void solve(){
		for(ll i=1;i<=m;i++){
			cin>>x>>y>>z;
			v[x].push_back((node){y,z});
			//q.push(vide{x,y,z});
		}
		for(ll i=1;i<=k;i++){
			for(ll j=0;j<=n;j++){
				cin>>d[i][j];
			}
		}
		ans=1145141919810;
		//cout<<"0||"<<endl;
		//chose=0
		/*
		for(ll j=1;j<=n;j++){
			for(ll x=0;x<v[j].size();x++){
				q.push(vide{j,v[j][x].v,v[j][x].w});
			}
		}
		solution(n);
		*/
		for(ll i=1;i<=k;i++){
			dfs(1,1,i);
			while(!q.empty()){
				q.pop();
			}
		}
		/*
		//cout<<"1||"<<endl;
		//chose=1;
		for(ll i=1;i<=k;i++){
			anst=d[f[i]][0];
			f[1]=i;
			for(ll j=1;j<=n;j++){
				for(ll x=0;x<v[j].size();x++){
					q.push(vide{j,v[j][x].v,v[j][x].w});
				}
			}
			//cout<<"d||"<<endl;
			for(ll j=1;j<=k;j++){
				for(ll x=1;x<=n;x++){
					q.push(vide{n+j,x,d[f[j]][x]});
				}
			}
			//cout<<"d||"<<anst<<endl;
			solution(n+1);
		}
		*/
		cout<<ans<<endl;
		return;
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		f1::solution();
	}
	else{
		f2::solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
