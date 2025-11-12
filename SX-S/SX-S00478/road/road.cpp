#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k;
ll _u,_v,_w;
struct GJX{
	ll w,u,v;
	GJX(int U,int V,ll W){
		u=U,v=V,w=W;
	}
};
operator <(GJX x,GJX y){
	return x.w>y.w;
}
priority_queue<GJX>q;
int num;
int mn[100086];ll s;
int c;ll a[100086];
int MN(int x){
	return MN(mn[x]);
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)mn[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&_u,&_v,&_w);
		q.push(GJX(_u,_v,_w));
	}
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++)scanf("%lld",&a[j]);
		for(int j1=1;j1<=n;j1++)for(int j2=1;j2<=n;j2++)if(j1-j2)q.push(GJX(j1,j2,a[j1]+a[j2]+c));
	}
	while(num!=n-1){
		_u=q.top().u,_v=q.top().v,_w=q.top().w;
		q.pop();
		if(MN[_u]!=MN[_v]){
			s+=_w;int minn=min(mn[_u],mn[_v]);
			mn[_u]=minn;mn[_v]=minn;num++;
		}
	}
	cout<<s<<endl;
	return 0;
}