#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=10005,M=1e6+5,K=15;
struct Road{
	int x,y,z;
}r[1030][N],r1[M],r2[N*10];
bool cmp(Road i,Road j){
	return i.z<j.z;
}
int n,m1,m2,k,c[K],a[K][N],fa[N+K],lr[1030];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
LL kruscal(int pre,int now){
	LL ret=0;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	if(pre>=0){
		m1=lr[pre];	
		for(int i=1;i<=m1;i++) r1[i]=r[pre][i];
	}
	int p=1,q=1;
	while(p<=m1 || q<=m2){
		int x,y,z;
		if(p<=m1 && (q>m2 || r1[p].z<=r2[q].z)) x=r1[p].x,y=r1[p].y,z=r1[p].z,p++;
		else x=r2[q].x,y=r2[q].y,z=r2[q].z,q++;
		int fx=find(x),fy=find(y);
		if(fx!=fy){
			fa[fy]=fx,ret+=z;
			auto &it=r[now][++lr[now]];
			it.x=x,it.y=y,it.z=z;
		}
	}
	return ret;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m1>>k;
	for(int i=1;i<=m1;i++){
		cin>>r1[i].x>>r1[i].y>>r1[i].z;
	}
	sort(r1+1,r1+m1+1,cmp);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	LL ans=kruscal(-1,0);
	for(int sta=1;sta<(1<<k);sta++){
		LL sum=0;
		int p;
		for(int i=1;i<=k;i++){
			if(sta&(1<<(i-1))) sum+=c[i],p=i;
		}
		m2=0;
		for(int i=1;i<=n;i++){
			m2++;
			r2[m2].x=n+p,r2[m2].y=i,r2[m2].z=a[p][i];
		}
		sort(r2+1,r2+m2+1,cmp);
		ans=min(ans,sum+kruscal(sta-(1<<(p-1)),sta));
	}
	cout<<ans<<endl;
	return 0;
}
