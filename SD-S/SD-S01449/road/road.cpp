#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1e6 + 5;
struct Tree{
	int pre, to;
	int w;
} tree[maxn];
bool cmp(Tree a, Tree b){
	return a.w < b.w;
}
int f[maxn], answer=-1, n, m, ans=0, num=0, k, nodet=0;
vector<int> kpre[15];
vector<int> kto[15];
vector<int> kval[15];
int find(int x){
	return x == f[x] ? f[x] : f[x] = find(f[x]);
}
void fadd(int x, int y){
	f[find(x)] = find(y);
	return ;
}
void build(int x, int y, int w){
	ans += w;
	num ++;
	fadd(x, y);
	return ;
}
void kruskal(){
	num=0;
	ans=0;
	for (int i = 1;i <= n;i ++) f[i] = i;
	sort(tree + 1, tree + 1 + m, cmp);
	for (int i = 1;i <= m;i ++){
		if (num == n) break;
		if (find(tree[i].pre) == find(tree[i].to))
			continue;
		build(tree[i].pre, tree[i].to, tree[i].w);
	}
	answer = max(answer, ans);
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i ++){
		int u, v, w;
		cin >> tree[i].pre >> tree[i].to >> tree[i].w;
	}
	nodet = n;
	for (int i = 1;i <= k;i ++){
		int u, v, w;
		cin >> w;
		nodet ++;
		u = nodet;
		for (int j = 1;j <= n;j ++){
			cin >> w;
			kpre[j].push_back(u);
			kto[j].push_back(j);
			kval[j].push_back(w);
		}
	} 
	kruskal();
	cout << answer;
	return 0;
}
//cout << 'y' << '\n';
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
/*
4 4 2 
1 4 6 
2 3 7 
4 2 5 
4 3 4 
1 1 8 2 4 
100 1 3 2 4 
*/
