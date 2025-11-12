#include<bits/stdc++.h>
#define int long long
using namespace std;
int f[100005],c[15],a[15][100005];
bool flag = 1;
int find(int x){return x == f[x] ? x : f[x] = find(f[x]);}
void merge(int x,int y){f[find(x)] = find(y);}
struct cxf{int u,v,w;}edge[1000005];
vector<cxf> g[15];
bool csb(cxf a,cxf b){return a.w < b.w;}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	int n,m,k,ans = 4e18;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		scanf("%lld %lld %lld",&edge[i].u,&edge[i].v,&edge[i].w);
	}
	sort(edge + 1,edge + m + 1,csb);
	for(int i = 1; i <= k; i++){
		scanf("%lld",&c[i]);
		if(c[i]) flag = 0;
		int minn = 4e18,minp;
		for(int j = 1; j <= n; j++){
			scanf("%lld",&a[i][j]);
			if(minn > a[i][j]){
				minn = a[i][j];
				minp = j;
			}
		}
		for(int j = 1; j <= n; j++){
			if(j == minp) continue;
			g[i].push_back({minp,j,a[i][minp] + a[i][j]});
		}
//		cout << g[i].size() << endl;
	}
	for(int s = 0; s < (1 << k); s++){
		int sta = s,cnnt = 1,res = 0,cnt = 0;
		if(flag) sta = (1 << k) - 1;
		vector<cxf> edg;
		while(sta){
			if(sta % 2){
//				cout << cnnt << " ";
				res += c[cnnt];
				for(int i = 0; i < n - 1; i++) edg.push_back(g[cnnt][i]);
			}
			cnnt++;
			sta /= 2;
		}
		sort(edg.begin(),edg.end(),csb);
		int key = 0,leng = edg.size();
		for(int i = 1; i <= n; i++) f[i] = i;
		for(int i = 1; i <= m; i++){
			if(cnt >= n - 1) break;
			while(key < leng && edg[key].w <= edge[i].w){
				if(find(edg[key].u) != find(edg[key].v)){
					merge(edg[key].u,edg[key].v);
					cnt++;
					res += edg[key].w;
				}
				key++;
			}
			if(find(edge[i].u) != find(edge[i].v)){
				merge(edge[i].u,edge[i].v);
				cnt++;
				res += edge[i].w;
			}
		}
		ans = min(ans,res);
		if(flag) break;
	}
	printf("%lld",ans);
	//O(k * n log n + 2 ^ k * m)
	return 0;
}

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
