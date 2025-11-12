#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e4 + 1000;
const int maxm = 1e6 + 1000;
struct node{int u,v,w;}e[maxm],e1[maxm],e2[maxm * 2];
int n,m,k,ans = INT_MAX,cnt,tot,x;
int f[maxn],c[maxn];
int gai[20];
bool cmp(node a,node b){
	return a.w < b.w;
}
int find(int x){
	if(f[x] == x) return x;
	else return f[x] = find(f[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++) cin >> e[i].u >> e[i].v >> e[i].w;
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		for(int j = 1;j <= n;j++){
			e1[++cnt].u = i;
			e1[cnt].v = j;
			cin >> e1[cnt].w;
		}	
		gai[i] = cnt;
		//cout << gai[k] << endl;
	}
	for(int i = (1 << k) - 1;i;i--){
		//cout << i << endl;
		memset(e2,0,sizeof(e2));
		for(int j = 1;j <= n;j++) f[j] = j;
		int now = 0,mask = i,tot = 0,mi = INT_MAX;
		for(int i = 1;i <= m;i++) e2[++tot].u = e[tot].u,e2[tot].v = e[tot].v,e2[tot].w = e[tot].w;
		for(int j = 1;j <= k;j++){
			if(mask & 1){
				//cout << i << "===" << j << endl;
				now += c[j];
				for(int m = gai[j - 1] + 1;m <= gai[j];m++){
					e2[++tot].u = e1[m].u;
					e2[tot].v = e1[m].v;
					e2[tot].w = e1[m].w;
					mi = min(e2[tot].w,mi);
					//cout << i << "---"<< tot << endl;
				}
			}
			mask = mask >> 1;
		}
		//cout << now << endl;

		//for(int j = 1;j <= tot;j++) cout << e2[j].u << " " << e2[j].v << " "<<e2[j].w <<endl;
		sort(e2 + 1,e2 + 1 + tot,cmp);
		
		int num = 0;
		for(int j = 1;j <= tot;j++){
			int u = e2[j].u,v = e2[j].v;
			int fu = find(u),fv = find(v);
			if(fu == fv) continue;
			//cout << j << "[[[]]]"<< endl;
			num++;
			f[fu] = fv;
			now += e2[j].w;
			if(num == n - 1) break;
		}
		ans = min(ans,now + mi);
	}
	cout << ans;
	return 0;
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4
