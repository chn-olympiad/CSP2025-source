#include<bits/stdc++.h>
#define ll long long
#define PII pair<ll,ll>
#define mp make_pair
using namespace std;
const ll N=1e5+10;
const ll INF=1e9;
ll n,m,k,sum,cnt,f[N],c[N];
struct D{
	ll x,y,z;
}e[N];
vector<PII>g[N];
bool cmp(D a,D b){
	return a.z<b.z;
}
ll read(){
	ll ret=0,f=1;
	char ch=getchar();
	if(ch=='-'){
		f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		ret=ret*10+ch-48;
		ch=getchar();
	}
	return ret*f;
}
ll find(ll u){
	if(u!=f[u])f[u]=find(f[u]);
	return f[u];
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(ll i=1;i<=n;i++)f[i]=i;
	for(ll i=1;i<=m;i++){
		e[i].x=read();
		e[i].y=read();
		e[i].z=read();
	}
	for(ll i=1;i<=k;i++){
		c[i]=read();
		for(ll j=1;j<=n;j++){
			g[n+i].push_back(mp(j,read()));
			g[j].push_back(mp(n+i,read()));
		}
	}
	sort(e+1,e+m+1,cmp);
	for(ll i=1;i<=m;i++){
		ll X=find(e[i].x),Y=find(e[i].y);
		if(X==Y)continue;
		f[X]=Y;
		sum+=e[i].z;
		cnt++;
		if(cnt==n-1)break;
	}
	cout<<sum;
	return 0; 
}
