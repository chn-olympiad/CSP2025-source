#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
/*
by qqqaaazzz

复杂度 2^k * n * 并查集。

Good！！ 

新建的乡村肯定也被连进去了。 

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

50612625331
*/
int n,m,k,idx;
struct Edge{
	int x,y,z,tp;//tp 是类型。 
};
Edge e[2000010];
int p[10050];
int c[20];
int need[1024][10050];//状态是 i 的时候用了哪些边 
long long res[1024];
int my[20][10050];//我是哪些边？ 

bool cmp(Edge x,Edge y){
	return x.z<y.z;
}
int find(int x){
	if(p[x]==x) return p[x];
	p[x] = find(p[x]);
	return p[x];
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	FAST;
	cin >> n >> m >> k;
	for (int i=1;i<=m;i++){
		cin >> e[i].x >> e[i].y >> e[i].z;
		e[i].tp = -1;//一开始就有 
	}
	idx = m;
	for (int i=0;i<k;i++){
		cin >> c[i];
		for (int j=1;j<=n;j++){
			++idx;
			e[idx].x = j,e[idx].y = n+i+1,e[idx].tp = i;
			cin >> e[idx].z;
		}
	}
	sort(e+1,e+idx+1,cmp);
	for (int i=1;i<=idx;i++){
		if(e[i].tp>=0){
			my[e[i].tp][++my[e[i].tp][0]] = i;//这条边 
		}
	}
	//先把 0 的答案求了
	for (int i=1;i<=n+k;i++) p[i] = i;
	for (int i=1;i<=idx;i++){
		if(e[i].tp==-1){
			if(find(e[i].x)!=find(e[i].y)){
				p[find(e[i].x)] = find(e[i].y);
				res[0] += e[i].z;
				need[0][++need[0][0]] = i;
			}
		}
	}
	long long ans = res[0];
	for (int st=1;st<(1<<k);st++){
		//st 状态下的答案？
		int want = st-(st&-st);//want 状态下的边和 (st&-st) 的边进行合并
		int qaq = 0;
		for (int j=0;j<k;j++) if((1<<j)==(st&-st)) qaq = j;
		int U = 0;
		for (int j=0;j<k;j++){
			if((st>>j)&1){
				res[st] += c[j];
				++U;
			}
		}
		//qaq 的边和 want 的边合并
		for (int i=1;i<=n+k;i++) p[i] = i;
		int x = 1,y = 1;
		while(x<=need[want][0]||y<=n){
			int ID;
			if(x>need[want][0]){
				ID = my[qaq][y];
				++y;
			}
			else if(y>n){
				ID = need[want][x];
				++x;
			}
			else if(e[my[qaq][y]].z<e[need[want][x]].z){
				ID = my[qaq][y];
				++y;
			}
			else{
				ID = need[want][x];
				++x;
			}
			if(find(e[ID].x)!=find(e[ID].y)){
				p[find(e[ID].x)] = find(e[ID].y);
				res[st] += e[ID].z;
				need[st][++need[st][0]] = ID;
				if(need[st][0]==n-1+U) break;
			}
		}
		ans = min(ans,res[st]);
	}
	cout << ans << "\n";
	return 0;
}


