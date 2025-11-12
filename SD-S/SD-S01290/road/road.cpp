#include<bits/stdc++.h>
#define int long long
using namespace std;
struct q{
	int x,y,k;
}a[1000006];
int b[1000005];
int fa[1000005];
int cha(int x) {
	if(fa[x]==x) return x;
	else {
		fa[x]=cha(fa[x]);
		return fa[x];
	}
}
void bing(int x,int y) {
	fa[cha(y)]=cha(x);
	return;
}
int pan(int x,int y) {
	if(cha(x)==cha(y)) return 1;
	else return 0;
}
int cmp(q a,q b) {
	return a.k<b.k;
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=n+q+1;i++) fa[i]=i;
	for(int i=1;i<=m;i++) {
		int x,y,k;
		cin>>x>>y>>k;
		a[i].x=x,a[i].y=y,a[i].k=k;
	}
	int cnt=m;
	for(int i=1;i<=q;i++) {
		int l;
		cin>>l;
		for(int z=1;z<=n;z++) {
		int x;
		cin>>x;
		cnt++;
		a[cnt].x=i+n,a[cnt].y=z,a[cnt].k=x;
		}
	}
	n+=q;
	sort(a+1,a+cnt+1,cmp);
	int u=0,ans=0;
	int o=0;
	for(int i=1;i<=cnt;i++) {
		int x,y,z;
		x=a[i].x;
		y=a[i].y;
		z=a[i].k;
		if(pan(x,y)==0) {
			bing(x,y);
			ans+=z;
			u++;
		} 
		if(u==n-1) break;
	}
	cout<<ans;
	return 0;
} 
