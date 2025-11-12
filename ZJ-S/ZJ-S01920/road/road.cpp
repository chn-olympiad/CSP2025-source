#include <bits/stdc++.h>
using namespace std;
struct edg{
	long long u,v,w;
	bool shuru(){
		scanf("%lld%lld%lld",&u,&v,&w);
	}
}ste[1000020];
bool cmp(edg e1,edg e2){
	return e1.w<e2.w;
}
long long c[20];
long long a[20][10020];
edg itr[10020];long long cne=0;
long long fa[10020];
long long findfa(long long u){
	if(fa[u]==u)return u;
	else return fa[u]=findfa(fa[u]);
}
edg nwe[100020];long long cn2=0;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1;i<=n;i++)fa[i]=i;
	for(long long i=1;i<=m;i++){
		ste[i].shuru();
	}
	for(long long i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(long long j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	sort(ste+1,ste+m+1,cmp);
//	int sum=0;
	for(long long i=1;i<=m;i++){
		long long u=ste[i].u,v=ste[i].v;
		long long fu=findfa(u),fv=findfa(v);
		if(fu==fv)continue;
		fa[fu]=fv;cne++;
		itr[cne]=ste[i];
//		sum+=ste[i].w;
//		cout<<u<<" "<<v<<endl;
//		cout<<i<<endl;
	}
//	cout<<sum<<endl;
//	sum=0;
	long long ans=(long long)1e16;
	for(long long i=0;i<(1<<k);i++){
		for(long long i=1;i<=cne;i++){
			nwe[i]=itr[i];
		}
		cn2=cne;
		long long cnn=0,nwa=0;
		for(long long vl=1;vl<=k;vl++){
			if((i>>(vl-1))&1){
//				cout<<vl<<endl;
				nwa+=c[vl];
				cnn++;
				for(long long u=1;u<=n;u++){
					cn2++;
					nwe[cn2].u=u;
					nwe[cn2].v=n+cnn;
					nwe[cn2].w=a[vl][u];
				}
			}
		}
//		cout<<nwa<<endl;
		sort(nwe+1,nwe+cn2,cmp);
		for(long long i=1;i<=n+cnn;i++){
			fa[i]=i;
		}
		for(long long i=1;i<=cn2;i++){
			long long u=nwe[i].u,v=nwe[i].v;
			long long fu=findfa(u),fv=findfa(v);
			if(fu==fv)continue;
			fa[fu]=fv;
//			cout<<nwe[i].w<<endl;
			nwa+=nwe[i].w;
		}
//		cout<<i<<" "<<nwa<<endl;
		ans=min(ans,nwa);
	}
	printf("%lld\n",ans);
	return 0;
}
