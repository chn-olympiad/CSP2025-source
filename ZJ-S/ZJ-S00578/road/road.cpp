#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int x,y,l;
}a[2000050];
int n,m,k,fa[10010],c[11],ans,an;
bool vis[2000050];
int f(int x){
	return fa[x]==x?x:f(fa[x]);
}
bool cmp(node x,node y){
	return x.l<y.l;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	for(int i=1,l;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].l;
	}
	int res=0;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++){
		int x=a[i].x,y=a[i].y;
		int rx=f(x),ry=f(y);
		if(rx!=ry){
			fa[rx]=ry;
			an+=a[i].l;
			res++;
			if(res==n)
				break;
		}
	}
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	int cnt=m;
	for(int i=1;i<=k;i++){
		cin>>c[i+n];
		for(int j=1;j<=n;j++){
			cnt++;
			a[cnt].x=n+i;
			a[cnt].y=j;
			cin>>a[cnt].l;
			a[cnt].l+=c[i+n];
		}
	}
	res=0;
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		int x=a[i].x,y=a[i].y;
		int rx=f(x),ry=f(y);
		if(rx!=ry){
			fa[rx]=ry;
			if(x>n&&!vis[x])
				vis[x]=1;
			else if(x>n&&vis[x])
				a[i].l-=c[x];
			ans+=a[i].l;
			res++;
			if(res==n)
				break;
		}
	}
	cout<<min(ans,an);
	return 0;
}
