#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,i,fx,fy,j,c[1001],f[1001],w[11][10001];
int b[100001],l,fa[100001],mi,ma;
struct no{
	int x,y,z;
};
no a[1000001],d[1000001];
int read(){
	int fl=1,s=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') fl=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') s=s*10+c-48,c=getchar();
	return s*fl;
}
bool cmp(no t,no w){
	return t.z<w.z;
}
int fi(int t){
	if(fa[t]==t) return t;
	else return fa[t]=fi(fa[t]);
}
void pd(){
	int i,ll=l,s=n,fx,fy,tt=0,v=0,ss=0,j;
	for(i=1;i<=l;++i) d[i]=a[b[i]];
	for(i=1;i<=k;++i)
		if(f[i]==1){
			s++;ss+=c[i];
			for(j=1;j<=n;++j)
				if(w[i][j]<=ma)
					ll++,d[ll].x=j,d[ll].y=s,
					d[ll].z=w[i][j];
		}
	if(ss>=mi) return ;
	for(i=1;i<=s;++i) fa[i]=i;
	sort(d+1,d+ll+1,cmp);
	for(i=1;i<=ll;++i){
		fx=fi(d[i].x),fy=fi(d[i].y);
		if(fx!=fy){
			if(fx>fy) swap(fx,fy);
			if(fx<=n&&fy<=n) ++tt;
			fa[fy]=fx;
			v+=d[i].z;
		}
		if(ss+v>=mi) return ;
		if(tt==n-1) break;
	}
	mi=min(mi,ss+v);
}
void sc(int t){
	if(t>k){
		pd();
		return ;
	}
	f[t]=1,sc(t+1);
	f[t]=0,sc(t+1);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	cin>>n>>m>>k;
	n=read(),m=read(),k=read();
	for(i=1;i<=n;++i) fa[i]=i;
	for(i=1;i<=m;++i)
//		cin>>a[i].x>>a[i].y>>a[i].z;
		a[i].x=read(),a[i].y=read(),a[i].z=read();
	sort(a+1,a+m+1,cmp);
	for(i=1;i<=m;++i){
		fx=fi(a[i].x),fy=fi(a[i].y);
		if(fx!=fy){
			fa[fy]=fx;mi+=a[i].z;
			++l,b[l]=i;ma=max(ma,a[i].z);
		}
		if(l==n-1) break;
	}
	for(i=1;i<=k;++i){
//		cin>>c[i];
		c[i]=read();
		for(j=1;j<=n;++j)
//			cin>>w[i][j];
			w[i][j]=read();
	}
	sc(1);
	cout<<mi;
	return 0;
}
