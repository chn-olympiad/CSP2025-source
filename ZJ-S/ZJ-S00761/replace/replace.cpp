#include <bits/stdc++.h>
#define ED cerr<<'\n';
#define TS cerr<<"I AK IOI\n";
#define cr(x) cerr<<x<<'\n';
#define cr2(x,y) cerr<<x<<" "<<y<<'\n';
#define cr3(x,y,z) cerr<<x<<" "<<y<<" "<<z<<'\n';
#define cr4(x,y,z,w) cerr<<x<<" "<<y<<" "<<z<<" "<<w<<'\n';
#define pr(a,l,r) for(int iii=l;iii<=r;++iii) cerr<<a[iii]<<" ";ED
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=5e6+5,M=5e6+5,mod1=998244353,mod2=1e9+7,B=13331,INF=2e9;
int T,n,m,k,idx=0;
bool Mst;
map<pair<ull,ull>,int> mp[N],rt;
ull g1[N],g2[N];
int tr[N][26],cnt[N],mx[N];pair<ull,ull> val[N];
char s1[M],s2[M];ull v1[M],v2[M];
bool Med;

inline ull f(char x,char y) {
	return (x-'a'+1)*26+(y-'a'+1);
}

void insert(int rt,char s[],int st) {
	int u=rt;
	for(int i=st;s[i];++i) {
		int to=s[i]-'a';
		if(!tr[u][to]) {
			tr[u][to]=++idx;ull qwq=f(s[i],s[i]);
			val[idx].fi=(val[u].fi*B+qwq)%mod1;
			val[idx].se=(val[u].se*B+qwq)%mod2;
			mp[rt][val[idx]]=idx;
		}
		u=tr[u][to];
	}
	++cnt[u];
}

void dfs(int u) {
	for(int i=0;i<26;++i) {
		if(tr[u][i]) {
			cnt[tr[u][i]]+=cnt[u],dfs(tr[u][i]);
		}
	}
}

void init() {
	g1[0]=g2[0]=1;
	for(int i=1;i<N;++i) {
		g1[i]=g1[i-1]*B%mod1;
		g2[i]=g2[i-1]*B%mod2;
	}
}

pair<ull,ull> getval(int l,int r) {
	ull x1=(v1[r]-v1[l-1]*g1[r-l+1]%mod1+mod1)%mod1;
	ull x2=(v2[r]-v2[l-1]*g2[r-l+1]%mod2+mod2)%mod2;
	return {x1,x2};
}

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	init();
	scanf("%d%d",&n,&m);
	vector<int> rts;
	for(int i=1;i<=n;++i) {
		scanf("%s%s",s1+1,s2+1);
		int sz=strlen(s1+1),lst=0;
		for(int j=1;j<=sz;++j) {
			if(s1[j]!=s2[j]) {
				lst=j;
			}
		}
		if(!lst) {
			continue;//ПаµИ 
		}
		for(int j=1;j<=lst;++j) {
			v1[j]=(v1[j-1]*B+f(s1[j],s2[j]))%mod1;
			v2[j]=(v2[j-1]*B+f(s1[j],s2[j]))%mod2;
		}//cr2(v1[lst],v2[lst])
		if(!rt.count({v1[lst],v2[lst]})) {
			rt[{v1[lst],v2[lst]}]=++idx;
			rts.emplace_back(idx),mp[idx][{0,0}]=idx;
		}
		int u=rt[{v1[lst],v2[lst]}];
		mx[u]=max(mx[u],sz-lst),insert(u,s1,lst+1);
	}
	for(auto it:rts) {
		dfs(it);
	}
	for(int t=1;t<=m;++t) {
		scanf("%s%s",s1+1,s2+1);
		int sz=strlen(s1+1),fst=0,lst=0,ans=0;
		for(int j=1;j<=sz;++j) {
			if(s1[j]!=s2[j]) {
				if(!fst) fst=j;
				lst=j;
			}
		}
		for(int j=1;j<=sz;++j) {
			v1[j]=(v1[j-1]*B+f(s1[j],s2[j]))%mod1;
			v2[j]=(v2[j-1]*B+f(s1[j],s2[j]))%mod2;
		}
		for(int j=1;j<=fst;++j) {
			pair<ull,ull> res=getval(j,lst);//cr4(t,j,lst,res.fi)
			if(rt.count(res)) {
				int u=rt[res];//cr2(u,mx[u])
				int l=lst+1,r=min(lst+mx[u],sz),res=lst;
				while(l<=r) {
					int mid=l+r>>1;
					if(mp[u].count(getval(lst+1,mid))) {
						l=mid+1,res=mid;
					}
					else r=mid-1;
				}
				pii res2=getval(lst+1,res);
				ans+=cnt[mp[u][res2]];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

