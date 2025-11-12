#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(auto i=(a);i<=(b);i++)
#define REP(i,a,b) for(auto i=(a);i>=(b);i--)
#define FORK(i,a,b,k) for(auto i=(a);i<=(b);i+=(k))
#define REPK(i,a,b,k) for(auto i=(a);i>=(b);i-=(k))
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
#define mkpr make_pair
#define fi first
#define se second
#define gc getchar()
#define pc putchar
#define pln pc(10);
#define eb emplace_back
template<class T>
void ckmx(T& a,T b) {
	a=max(a,b);
}
template<class T>
void ckmn(T& a,T b) {
	a=min(a,b);
}
template<class T>
T gcd(T a,T b) {
	return !b?a:gcd(b,a%b);
}
template<class T>
T lcm(T a,T b) {
	return a/gcd(a,b)*b;
}
template<class T>
void read(T& x) {
	x=0;
	int f=1;
	char ch=gc;
	while(!isdigit(ch)) {
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(isdigit(ch)) {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=gc;
	}
	x*=f;
}
template<class T>
void write(T x) {
	if(x<0) {
		pc('-');
		x=-x;
	}
	if(x>=10)write(x/10);
	pc(x%10^48);
}
template<class T>
void writeln(T x) {
	write(x);
	pln
}
void io() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
}
const int maxn=1e4+5;
const int maxm=1e6+5;
int n,m,k;
struct EDGE {
	int u,v;
	ll w;
} edge[maxm];
int basecost[11];
int c[11][maxn];
struct UNIONFINDBASE {
	int fa[maxn];
	void init() {
		FOR(i,1,n)fa[i]=i;
	}
	int get(int x) {
		return x==fa[x]?x:fa[x]=get(fa[x]);
	}
	void ms(int a,int b) {
		if(get(a)!=get(b)) {
			fa[get(a)]=get(b);
		}
	}
} ufbase;
set<pii> rem[11];
bool del[11];
int fir[11];
struct UNIONFIND {
	int fa[maxn],dis[maxn][11];
	void init() {
		FOR(i,1,n)fa[i]=i;
		FOR(j,1,k) {
			rem[j].clear();
			del[j]=0;
			fir[j]=0;
		}
		FOR(i,1,n) {
			FOR(j,1,k) {
				rem[j].insert(mkpr(c[j][i],i));
				dis[i][j]=c[j][i];
			}
		}
	}
	int get(int x) {
		return x==fa[x]?x:fa[x]=get(fa[x]);
	}
	void ms(int a,int b,int newid) {
		int ida=get(a),idb=get(b);
		if(ida!=idb) {
			fa[ida]=idb;
			if(newid!=-1){
				if(rem[newid].find(mkpr(dis[ida][newid],ida))!=rem[newid].end()) {
					rem[newid].erase(mkpr(dis[ida][newid],ida));
			//		printf("erase %d -> %d\n",ida,newid);
				}
				if(rem[newid].find(mkpr(dis[idb][newid],idb))!=rem[newid].end()) {
					rem[newid].erase(mkpr(dis[idb][newid],idb));
				//	printf("erase %d -> %d\n",idb,newid);
				}
			}
			
			FOR(i,1,k){
				auto fd1=rem[i].find(mkpr(dis[ida][i],ida)),fd2=rem[i].find(mkpr(dis[idb][i],idb));
				if(fd1!=rem[i].end()&&fd2!=rem[i].end()){
					rem[i].erase(fd1);
					rem[i].erase(mkpr(dis[idb][i],idb));
					ckmn(dis[idb][i],dis[ida][i]);
					rem[i].insert(mkpr(dis[idb][i],idb));
				}else{
			//		printf("i = %d\n",i);
					if(fd1!=rem[i].end())rem[i].erase(fd1);
					if(fd2!=rem[i].end())rem[i].erase(fd2);
				}
				
			}
		}
	}
} uf;
void solve(int id_of_testcases) {
	read(n);
	read(m);
	read(k);
	FOR(i,1,m) {
		read(edge[i].u);
		read(edge[i].v);
		read(edge[i].w);
	}
	sort(edge+1,edge+m+1,[&](EDGE& a,EDGE& b) {
		return a.w<b.w;
	});
	ufbase.init();
	vector<EDGE> edges;
	FOR(i,1,m) {
		if(ufbase.get(edge[i].u)!=ufbase.get(edge[i].v)) {
			ufbase.ms(edge[i].u,edge[i].v);
			edges.eb(edge[i]);
		}
	}
	FOR(i,1,k) {
		read(basecost[i]);
		FOR(j,1,n) {
			read(c[i][j]);
		}
	}
	ll ans=1e18;
	int all=(1<<k)-1;
//	puts("Wtf");
	{
		FOR(msk,0,all) {
		//	printf("msk %d\n",msk);
			int eid=0;
			uf.init();
			ll res=0;
			FOR(i,1,k) {
				if(msk&(1<<i-1))res+=basecost[i];
			}
			int cnt=n;
			while(cnt>1) {
				int id1,id2;
				int w=1e9;
				int delid=-1;
				FOR(i,1,k) {
					if(!(msk&(1<<i-1)))continue;
					if(!del[i]) {
						auto ptr=rem[i].begin();
						auto ptr2=ptr;
						ptr2++;
						ll curcost=ptr->fi+ptr2->fi;
						if(curcost<=w) {
							w=curcost;
							id1=ptr->se,id2=ptr2->se;
							delid=i;
					//		puts("Wtf1");
						}
					}else {
						auto tmp=*rem[i].begin();
						if(tmp.fi<=w) {
							w=tmp.fi;
							id1=fir[i],id2=tmp.se;
							delid=i;
						}
					}
				}
				if(edges[eid].w<=w&&uf.get(edges[eid].u)!=uf.get(edges[eid].v)) {
					w=edges[eid].w;
					id1=edges[eid].u,id2=edges[eid].v;
					eid++;
					delid=-1;
				}
				res+=w;
			//	printf("id1 %d id2 %d w %lld\n",id1,id2,w);
				uf.ms(id1,id2,delid);
				if(delid!=-1)del[delid]=1,fir[delid]=id1;
				cnt--;
			}
			ckmn(ans,res);
		//	printf("res = %lld\n",res);
		}
	}
	printf("%lld\n",ans);
}
int main() {
	io();
	int T;
	T=1;
	FOR(_,1,T) {
		solve(_);
	}
	return 0;
}

