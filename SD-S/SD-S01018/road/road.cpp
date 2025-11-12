#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using i128=__int128;
using ull=unsigned long long;
//bool f1;
inline void read(int &a){
	a=0;register char c=getchar();bool ff=0;
	while(c<'0'||'9'<c){if(c=='-') ff=1;c=getchar();}
	while('0'<=c&&c<='9'){a=(a<<3)+(a<<1)+(c^48);c=getchar();}
	if(ff) a=-a;
}
namespace SOLVE{
	const int N=1e4+100,M=1e6+5,K=15;
	int n,m,k,f[N];
	int c[K],t[K][N];
	int find(int x){
		if(f[x]==x) return x;
		return f[x]=find(f[x]);
	}
	struct edge{
		int u,v,w;
		friend bool operator < (edge a,edge b){
			return a.w<b.w;
		}
	}e[M],te[K][N];
	vector<edge> now,pnow;
	vector<pair<ll,vector<edge> > > eans;
	mt19937_64 rd(time(NULL));
	void main(){
		read(n);read(m);read(k);
		for(int i=1;i<=m;i++){read(e[i].u);read(e[i].v);read(e[i].w);}
		sort(e+1,e+m+1);eans.clear();now.clear();pnow.clear();
		for(int i=1;i<=n+k;i++) f[i]=i;
		int uu,vv;
		for(int i=1;i<=m;i++){
			uu=find(e[i].u),vv=find(e[i].v);
			if(uu==vv) continue;
			pnow.emplace_back(e[i]);
			f[uu]=vv;
		}
		eans.emplace_back(0ll,pnow);
		for(int i=1;i<=k;i++){
			read(c[i]);
			for(int j=1;j<=n;j++) read(t[i][j]);
			for(int j=1;j<=n;j++) te[i][j].u=n+i,te[i][j].v=j,te[i][j].w=t[i][j];
			sort(te[i]+1,te[i]+n+1);
		}
		for(int i=1;i<=k;i++){
			int nn=eans.size();
			for(int I=0;I<nn;I++){
				for(int j=1;j<=n+k;j++) f[j]=j;
				now=eans[I].se;pnow.clear();
				int i1=0,i2=1,sz1=now.size()-1,sz2=n;
				while(i1<=sz1&&i2<=sz2){
					if(now[i1].w<te[i][i2].w){
						uu=find(now[i1].u),vv=find(now[i1].v);
						if(uu==vv){i1++;continue;}
						f[uu]=vv;pnow.emplace_back(now[i1]);
						i1++;
					}
					else{
						uu=find(te[i][i2].u),vv=find(te[i][i2].v);
						if(uu==vv){i2++;continue;}
						f[uu]=vv;pnow.emplace_back(te[i][i2]);
						i2++;
					}
				}
				while(i1<=sz1){
					uu=find(now[i1].u),vv=find(now[i1].v);
					if(uu==vv){i1++;continue;}
					f[uu]=vv;pnow.emplace_back(now[i1]);
					i1++;
				}
				while(i2<=sz2){
					uu=find(te[i][i2].u),vv=find(te[i][i2].v);
					if(uu==vv){i2++;continue;}
					f[uu]=vv;pnow.emplace_back(te[i][i2]);
					i2++;
				}
				eans.emplace_back(eans[I].fi+c[i],pnow);
			}
		}
		ll anss=0,pans=0x3f3f3f3f3f3f3f3f;
		for(auto i:eans){
			anss=i.fi;
			for(auto j:i.se) anss+=j.w;
			pans=min(pans,anss);
		}
		printf("%lld\n",pans);
	}
}
//bool f2;
int main(){
//	int _=clock();
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T=1;
//	read(T);
	while(T--) SOLVE::main();
//	cerr<<((&f2)-(&f1))/1024.0/1024.0<<endl;
//	cerr<<clock()-_<<endl;
	return 0;
}
