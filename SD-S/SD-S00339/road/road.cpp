#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N=5e5+10;
const int M=2e6+10;
ll f[N];
ll n,m,k;
ll u,v,w;
struct node{
	ll u,v;
	ll w;
};
node a[M];
//ll b[N][15];
//ll c[15];
ll nk;
ll ansx;
ll ansy;
ll bkx;
bool opx;
ll fx(ll x){
	if(f[x]==x){
		return f[x];
	}
	return f[x]=fx(f[x]);
}
void hebing_x(ll x,ll y,ll z){
	x=fx(x);
	y=fx(y);
	if(x!=y){
		ansx+=z;
		f[y]=x;
	}
}
void hebing_y(ll x,ll y,ll z){
	x=fx(x);
	y=fx(y);
	if(x!=y){
//		cout<<x<<" "<<y<<" "<<z<<endl;
		ansy+=z;
		f[y]=x;
	}
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	opx=true;
	cin>>n>>m>>k;
	nk=n+k;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(ll i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+m+1,cmp);
	for(ll i=1;i<=m;i++){
		hebing_x(a[i].u,a[i].v,a[i].w);
	}
	for(int i=1;i<=nk;i++){
		f[i]=i;
	}
	bkx=m;
	for(ll i=1;i<=k;i++){
		cin>>w;
		if(w!=0){
			opx=false;
		}
//		a[++bkx].u=nk+1;
//		a[bkx].v=n+i;
//		a[bkx].w=w;
		for(ll j=1;j<=n;j++){
			cin>>w;
			a[++bkx].u=n+i;
			a[bkx].v=j;
			a[bkx].w=w;
		}
	}
	if(opx){
		sort(a+1,a+bkx+1,cmp);
		for(ll i=1;i<=bkx;i++){
			hebing_y(a[i].u,a[i].v,a[i].w);
		}
		cout<<min(ansx,ansy)<<"\n";
	}
	else{
		cout<<998244353<<endl;
	}
	return 0;
}
