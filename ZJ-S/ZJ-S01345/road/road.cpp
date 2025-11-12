#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define fi first
#define se second
using namespace std;
const int mx=2e6+15,N=2e5+15;
ll t,n,m,k,a[15][N],c[N],vis[mx],fa[mx],tot;
struct node{
	ll a,b,c;
}d[mx],b[mx],e[mx];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool cmp(node x,node y){
	return x.c<y.c;
}
ll kr1(){
	ll ret=0;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int _1=find(b[i].a),_2=find(b[i].b);
		if(_1!=_2){
			vis[i]=1;
			fa[_1]=_2;
			ret+=b[i].c;	
		}
	}
	return ret;
}
ll kr2(){
	ll ret=0;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=tot;i++){
		int _1=find(d[i].a),_2=find(d[i].b);
		if(_1!=_2){
			fa[_1]=_2;
			ret+=d[i].c;	
		}
	}
	return ret;
}
void colse(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>b[i].a>>b[i].b>>b[i].c;
	}
	int bj=1;
	sort(b+1,b+m+1,cmp);
	for(int i=1;i<=k;i++){
		cin>>c[i];	
		if(c[i]) bj=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		
		}
	}
	ll _=kr1();
	for(int i=1;i<=m;i++){
		if(vis[i]){
			d[++tot].a=b[i].a;d[tot].b=b[i].b;d[tot].c=b[i].c;
			e[tot]=d[tot];
		}
	}
	ll t1=tot,ans=1e18;
	for(int i=0;i<(1<<k);i++){
		tot=t1;
		ll cnt=0;
		if(bj&&i<(1<<k)-1){
			continue;
		}
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1))){
				cnt+=c[j];
				for(int ij=1;ij<=n;ij++){
					d[++tot].a=ij,d[tot].b=n+j,d[tot].c=a[j][ij];
				}
			}
		}
		sort(d+1,d+tot+1,cmp);
		ans=min(ans,kr2()+cnt);
		for(int j=1;j<=t1;j++) d[j]=e[j];
	}
	cout<<ans<<endl;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	colse();
	t=1;
	while(t--) solve();
	return 0;
}