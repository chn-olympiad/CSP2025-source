#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m,k,cnt,tot,fa[10005],dis[15][10005];
struct HLC{
	int x,y,z;
	bool operator <(const HLC b)const{return z<b.z;}
}a[1050005];
ll ans;
int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;cnt=n;tot=m;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)cin>>a[i].x>>a[i].y>>a[i].z;
	for(int i=1;i<=k;i++){
		int x;cin>>x;x=0;
		for(int j=1;j<=n;j++){
			cin>>dis[i][j];
			if(!dis[i][j])x=j;
		}
		for(int j=1;j<=n;j++)
		if(j!=x)a[++tot]=(HLC){j,x,dis[i][j]};
	}
	sort(a+1,a+1+tot);
	for(int i=1;i<=tot&&cnt>1;i++){
		int fx=getfa(a[i].x),fy=getfa(a[i].y);
		if(fx==fy)continue;
		fa[fx]=fy;cnt--;ans+=a[i].z;
	}
	cout<<ans;
	return 0;
}
