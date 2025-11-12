#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1e4+1,maxb=1e6+1;
LL n,m,k,i,x,tot,fx,fy,y,w,cnt,j,ans,mi,cd,d,h;
LL f[maxn],l[12][maxn],c[12];
struct no{
	LL x,y,w;
};
no b[maxn],a[maxb];
LL find(LL x){
	if(x!=f[x]){
		f[x]=find(f[x]);
		return f[x];
	}
	return x;
}
bool cmp(no q,no h){
	return q.w<h.w;
}
LL solve(no a[],LL m,LL n){
	LL ans=0,tot=0,i;
	for(i=1;i<=n;i++) f[i]=i;
	sort(a+1,a+1+m,cmp);
	for(i=1;i<=m;i++){
		x=a[i].x;y=a[i].y;
		fx=find(x);fy=find(y);
		if(fx!=fy){
			f[fx]=fy;
			b[++tot].x=x;b[tot].y=y;
			b[tot].w=a[i].w;
			ans+=a[i].w;
		}
		if(tot==n-1) break;
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=m;i++) cin>>x>>y>>w,a[++cnt].x=x,a[cnt].y=y,a[cnt].w=w;
	for(i=1;i<=k;i++){
		cin>>c[i];
		for(j=1;j<=n;j++)
			cin>>l[i][j];
	}
	mi=solve(a,m,n);
	for(i=1;i<=n-1;i++) a[i].x=b[i].x,a[i].y=b[i].y,a[i].w=b[i].w;
	for(i=1;i<(1<<k);i++){
		d=n;ans=0;cd=n-1;
		for(j=1;j<=k;j++)
			if(i&(1<<(j-1))){
				d++;ans+=c[j];
				for(h=1;h<=n;h++)
					a[++cd].x=d,a[cd].y=h,a[cd].w=l[j][h];
			}
		mi=min(mi,ans+solve(a,cd,d));
	}
	cout<<mi;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4*/
