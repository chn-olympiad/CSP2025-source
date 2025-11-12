#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
using namespace std;
const int N=1e5+20;
int n;multiset<pii> st[3];
int ed[N];
struct node{
	int a[4],tp[4];
	void init() {
		FOR(i,0,2)tp[i]=i;
		FOR(i,0,2)FOR(j,0,2) {
			if(a[tp[i]]>a[tp[j]])swap(tp[i],tp[j]);
		}
	}
}s[N];
bool cmp(const node &aa,const node &bb) {
	return aa.a[aa.tp[0]]>bb.a[bb.tp[0]]; 
}
void solve1() {
	int ans=0;
	FOR(i,1,n/2)ans+=s[i].a[s[i].tp[0]];
	printf("%d\n",ans);
}
void solve() {
	scanf("%d",&n);
	bool flag1=1,flag2=1;
	FOR(i,1,n) {
		FOR(j,0,2)scanf("%d",&s[i].a[j]);
		if(s[i].a[1])flag1=0;
		if(s[i].a[2])flag2=0;
		s[i].init();
	}
	sort(s+1,s+1+n,cmp);
	if(flag1&flag2){solve1();return;}
	int ans=0,ct[4];
	FOR(i,0,2)st[i].clear(),ct[i]=0;
	FOR(i,1,n) {
		bool flag=0;
		FOR(j,0,2) {
			node _=s[i];int to=_.tp[j];
			int valj=_.a[to];
			int val=valj-_.a[_.tp[j+1]];
			if(ct[to]<(n/2)) {
				if(j<=1)st[to].insert(mkp(val,i)),ct[to]++;
				ans+=valj;flag=1;
			} else {
				set<pii>::iterator it=st[to].begin();
				for(;it!=st[to].end();it++) {
					if(ed[(*it).se]<2)break;
				}
				pii itt=*it;
				if(itt.fi<valj) {
					ans+=valj-itt.fi;int re=itt.se;
					ed[re]++;
					node __=s[ed[re]];int tr=__.tp[ed[re]];
					while(ct[tr]>=(n/2)&&ed[re]<=2) {
						ed[re]++;__=s[ed[re]];
						tr=__.tp[ed[re]];
					}
					st[to].erase(it);
					if(j<=1)st[to].insert(mkp(val,i));
//					if(tr==2)printf("%d\n",re);
					if(ed[re]<=1)st[tr].insert(mkp(__.a[tr]-__.a[__.tp[ed[re]+1]],re));
					flag=1;ct[tr]++;
				}
			}
			if(flag) {
				ed[i]=j;break;
			}
		}
	}
//	printf("%d %d %d %d ",n,ct[0],ct[1],ct[2]);
//	FOR(i,1,n)printf("%d ",s[i].tp[ed[i]]);
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--)solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

