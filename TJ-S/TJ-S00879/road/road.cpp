#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Edge1{
	int a,b,w;
}edge1[1000001],edge2[110001];
int n,m,k,flag[11],aa[11][10001],fa[11001],c[11],cnt1,cnt2;
bool cmp(Edge1 a,Edge1 b){
	return a.w < b.w;
}
int findfa(int x){
	if (fa[x] == x){
		return x;
	}
	return fa[x] = findfa(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for (int i = 1;i <= m;i++){
		int a,b,w;
		scanf("%lld%lld%lld",&a,&b,&w);
		edge1[++cnt1].a = a;
		edge1[cnt1].b = b;
		edge1[cnt1].w = w;
	}
	for (int i = 1;i <= n;i++){
		fa[i] = i;
	}
	sort(edge1 + 1,edge1 + m + 1,cmp);
	int ans = 0;
	for (int i = 1;i <= m;i++){
		if (cnt2 == n - 1){
			break;
		}
		int a = findfa(edge1[i].a),b = findfa(edge1[i].b);
		if (a != b){
			fa[a] = b;
			edge2[++cnt2] = edge1[i];
			ans += edge1[i].w;
		}
	}
	for (int i = 1;i <= k;i++){
		scanf("%lld",&c[i]);
		for (int j = 1;j <= n;j++){
			scanf("%lld",&aa[i][j]);
		}
	}
	int mt = (1 << k);
	for (int i = 1;i < mt;i++){
		int cnt = 0,mm = 0;
		cnt1 = cnt2;
		for (int j = 1;j <= cnt2;j++){
			edge1[j] = edge2[j];
		}
		for (int j = 1;j <= n + k;j++){
			fa[j] = j;
		}
		for (int j = 1;j <= k;j++){
			if ((i >> (j - 1)) & 1){
				flag[j] = true;
				mm++;
				cnt += c[j];
				for (int kk = 1;kk <= n;kk++){
					edge1[++cnt1] = {kk,j + n,aa[j][kk]};
				}
			}
		}
		sort(edge1 + 1,edge1 + cnt1 + 1,cmp);
		int cc = 0;
		for (int j = 1;j <= cnt1;j++){
			if (cc == n + mm - 1){
				break;
			}
			int a = findfa(edge1[j].a),b = findfa(edge1[j].b);
			if (a != b){
				fa[a] = b;
				cc++;
				cnt += edge1[j].w;
			}
		}
		ans = min(ans,cnt);
	}
	printf("%lld",ans);
	return 0;
}
