#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 20010;
const int MAXM = 2000010;
const int MAXK = 20;
const int INF = 1e18;
int n,m,k,ans = INF,c[MAXK],a[MAXK][MAXN],vis[MAXN],fa[MAXN];
struct node{
	int u,v,w;
}edge[MAXM];

bool cmp(node x,node y) {
	return x.w < y.w;
}

int fd(int x) {
	return fa[x] == x ? x : fa[x] = fd(fa[x]);
}

int solve(int cnt,int idx) {
	memset(vis,0,sizeof(vis));
	sort(edge + 1,edge + idx + 1,cmp);
	int res = 0,num = cnt;
	for (int i = 1,u,v,w,fu,fv;i <= idx;i++) {
		u = edge[i].u,v = edge[i].v,w = edge[i].w;
		fu = fd(u),fv = fd(v);
		if (fu != fv) {
			fa[fu] = fv;
			num -= 1;
			res += w;
		}
		if (num <= 1) break;
	}
	return res;
}

signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for (int i = 1;i <= m;i++) cin>>edge[i].u>>edge[i].v>>edge[i].w;
	for (int i = 1;i <= k;i++) {
		cin>>c[i];
		for (int j = 1;j <= n;j++) cin>>a[i][j];
	}
	for (int i = 0,idx,cnt,tmp;i < (1 << k);i++) {
		idx = m,cnt = n,tmp = 0;
		for (int j = 0;j < k;j++) {
			if ((i >> j) & 1) {
				cnt += 1;
				tmp += c[j + 1];
				for (int l = 1;l <= n;l++) edge[++idx] = {l,cnt,a[j + 1][l]};
			}
		}
		for (int j = 1;j <= cnt;j++) fa[j] = j;
		ans = min(ans,solve(cnt,idx) + tmp);
	}
	cout<<ans<<endl;
	return 0;
}