#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int N=1145140;

int f[N/100],c[14],sz[N];
int used[N/100];
int n,m,k,cnt,ans=1145141919810;

struct roads {
	int u,v,w;
	int bl;
} a[N];

bool cmp(const roads &x,const roads &y) {
	return x.w<y.w;
}

void init() {
	for(int i=1; i<=n+20; ++i) {
		f[i]=i;
	}
}

int find(int x) {
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

void merge(int ru,int rv) {
	if(sz[ru]<sz[rv]) {
		f[ru]=rv;
		sz[rv]+=sz[ru];
	} else {
		f[rv]=ru;
		sz[ru]+=sz[rv];
	}
}

void dfs(int d) {
	if(d==k+1) {

		init();
		int tans=0;
		int t=0;

		for(int i=1; i<=k; ++i)
			if(used[i]) {
				tans+=c[i];
				++t;
			}

		if(tans>ans) return ;
		int ct=0;

		for(int i=1; i<=cnt; i++) {

			int fu=find(a[i].u),fv=find(a[i].v);

			if(fu!=fv&&used[a[i].bl]) {
				merge(fu,fv);
				tans+=a[i].w;
				++ct;
				if(tans>ans) return ;
			}

			if(ct==n+t-1) break;
		}

		ans=min(ans,tans);
		return ;
	}

	dfs(d+1);
	used[d]=1;
	dfs(d+1);
	used[d]=0;

}

signed main() {

	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	cin>>n>>m>>k;

	for(int i=1; i<=m; ++i) {
		cin>>a[i].u>>a[i].v>>a[i].w;
		a[i].bl=0;
	}

	cnt=m;

	for(int i=1; i<=k; ++i) {
		cin>>c[i];
		for(int j=1; j<=n; ++j) {
			int t;
			cin>>t;
			a[++cnt]= {n+i,j,t,i};
		}
	}

	sort(a+1,a+1+cnt,cmp);
	used[0]=1;
	dfs(1);
	cout<<ans;
}

//C++ Searching Program - Sunior (CSP-S)

// 16:00 I have eaten all my chocolate!!! [cry][cry][cry][cry][cry]
// wo yao shang mi huo xing wei da shang!!!
//luogu uid = 1300065 ?
//by binary_carrots
//Don't lost hope,maybe you can make it.
//Man!What can I say!
//sdfsdgwotregduxhgdfjowthuesbdfjslkzghiworhaehflkdhzknawkqpoosoasfndkszxdhiwaueyrhralsdjnfklashtwiehrueiasdnklzsk
//100+(>=70)+0+10=(>=180)pts

//I love CCF!!!

//key:Ren5Jie4Di4Ling5%
