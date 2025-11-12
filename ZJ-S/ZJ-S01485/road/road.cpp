#include <algorithm>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <vector>
#ifdef LOCALDEBUG
#define fex(a, b)
#else
#define fex(a, b) freopen(a, "r", stdin);freopen(b, "w", stdout)
#endif
using namespace std;

long long read() {
	long long res=0, f=1;
	char c;
	while(!isdigit(c=getchar()))if(c=='-')f=-f;
	while(isdigit(c)) res=res*10+c-'0', c=getchar();
	return res*f;
}

bitset<10005> b;
long long n, m, k, ans, t;
long long fir[10005], c[15], cnt, l[15];

struct edge {
	long long u;
	long long v;
	long long w;
	long long nxt;
} e[1000005];

long long a[15][10005], d[15];

edge make_edge(long long u, long long v, long long w, long long nxt) {
	edge d;
	d.u=u;
	d.v=v;
	d.w=w;
	d.nxt=nxt;
	return d;
}

vector<edge> s;

void addedge(long long u, long long v, long long w) {
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].nxt=fir[u];
	fir[u]=cnt;
	return ;
}

bool cmp(edge x, edge y) {
	return x.w<y.w;
}

bool cmp3(edge x, edge y) {
	return x.w>y.w;
}

long long fa[10005];

void init() {
	for(int i = 1; i <= n; i++)fa[i]=i;
	return ;
}

long long findfa(long long x) {
	if(fa[x]==x)return x;
	return fa[x]=findfa(fa[x]);
}

void mergefa(long long x, long long y) {
	long long fx=findfa(x), fy=findfa(y);
	if(fx==fy)return ;
	fa[fy]=fx;
	return ;
}

bool branch(long long x, long long y) {
	return findfa(x)==findfa(y);
}
 
void kruskal() {
	sort(e+1, e+cnt+1, cmp);
	for(int i = 1; i <= cnt; i++) {
		if((long long)s.size()>=n-1) {
			sort(s.begin(), s.end(), cmp3);
			return ;
		}
		if(branch(e[i].u, e[i].v))continue;
		mergefa(e[i].u, e[i].v);
		ans+=e[i].w;
//		printf("%lld\n", ans);
		s.emplace_back(e[i]);
	}
	return ;
}

int main(void) {
	fex("road.in", "road.out");
//	freopen("road4.in", "r", stdin);
//	freopen("road4.out", "w", stdout);
	n=read();m=read();k=read();init();
	for(int i = 1; i <= m; i++) {
		long long u=read(), v=read(), w=read();
		addedge(u, v, w);
	}
	kruskal();
//	printf("%lld\n", ans);
	for(int i = 1; i <= k; i++) {
		c[i]=read();
		for(int j = 1; j <= n; j++) {
			a[i][j]=read();
		}
		l[i]=2;
		sort(a[i]+1, a[i]+n+1);
		c[i]+=a[i][1];
//		vector<edge>::iterator it=s.begin();
//		for(int j = 2; j <= n; j++) {
//			if(it==next(s.end()))break;
//			if(a[i][j]+a[i][1]>=it->w)break;
////			printf("%d %lld %lld\n", i, c[i], it->w);
//			c[i]+=a[i][j]-it->w;
//			++it;
//			printf("%d %lld %lld\n", i, c[i], it->w);
//		}
//		t=min(t, c[i]);
	}
	for(int i = 0; i < n-1; i++) {
		long long ch=0;
//		printf("%lld\n", s[i].w);
		for(int j = 1; j <= k; j++) {
			if(l[j]>n)continue;
			if(ch==0||a[j][l[j]]<a[ch][l[ch]]||(a[j][l[j]]<a[ch][l[ch]]&&b[j])) {
				ch=j;
			}
		}
		if(a[ch][l[ch]]+a[ch][1]>s[i].w)break;
		if(!b[ch])b[ch]=1, d[ch]+=c[ch];
		d[ch]+=a[ch][l[ch]]-s[i].w;
		l[ch]++;
//		for(int j = 1; j <= k; j++)printf("%lld ", d[j]);
//		putchar('\n');
	}
	for(int i = 1; i <= k; i++) {
		if(d[i]>=0)continue;
		ans+=d[i];
	}
	printf("%lld", ans);
	
	return 0;
}
