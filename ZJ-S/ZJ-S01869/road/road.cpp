#include <bits/stdc++.h>
using namespace std;

const int N=1000011,SN=100011;

int n,m,k,top;
int f[N],c[N];
long long ans;
inline int find(int x){return (x==f[x]?x:f[x]=find(f[x]));}

struct st{
	int x,y,z,id;
}e[N],d[N];
inline bool cmp(st A,st B){return A.z<B.z;}

inline void work(int S,int isRec=0){
	long long now=0;
	for (int i=1;i<=k;++i) if (S>>(i-1)&1) now+=c[i];
	for (int i=0;i<=n+k;++i) f[i]=i;
	for (int i=1;i<=m;++i){
		int x=e[i].x,y=e[i].y,z=e[i].z;
		if (e[i].id && !(S>>(e[i].id-1)&1)) continue;
		if (find(x)!=find(y)){
			now+=z;
			f[find(x)]=find(y);
			if (isRec) d[++top]=e[i],d[top].id=0;
		}
	}
	ans=min(ans,now);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);

	cin>>n>>m>>k;
	ans=1e18,top=0;
	for (int i=1;i<=m;++i) cin>>e[i].x>>e[i].y>>e[i].z;
	sort(e+1,e+m+1,cmp);

	work(0,1);

	for (int i=1;i<=k;++i){
		cin>>c[i];
		for (int j=1;j<=n;++j){
			++top;
			d[top].x=n+i,d[top].y=j;
			cin>>d[top].z;
			d[top].id=i;
		}
	}
	sort(d+1,d+top+1,cmp);
	m=top;
	for (int i=1;i<=m;++i) e[i]=d[i];

	for (int S=0;S<(1<<k);++S) work(S);
	cout<<ans<<'\n';

	return 0;
}