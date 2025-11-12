#include<bits/stdc++.h>
using namespace std;
const int M = 1e6+5;
const int N = 1e4+15;
struct node{
	long long x, y, w;
};
node l[M];
vector<node> l1;
int n, m, k;
long long c[15];
long long a[15][N];
long long ans = 0;
int fa[N];
void init(){
	for(int i = 1; i <= n+k; i++){
		fa[i] = i;
	}
}
int findroot(int x){
	if(fa[x] == x){
		return x;
	}
	return fa[x] = findroot(fa[x]);
}
void Union(int x, int y){
	int rootx = findroot(x);
	int rooty = findroot(y);
	fa[rooty] = rootx;
}
bool cmp(node x, node y){
	return x.w < y.w;
}
void solved(int x){
	int num = 1;
	long long sum = 0;
	vector<node> l2;
	init();
	for(int i = 0; i < l1.size(); i++){
		l2.push_back(l1[i]);
	}
	while(x){
		if(x&1){
			sum += c[num];
			for(int i = 1; i <= n; i++){
				l2.push_back({n+num, i, a[num][i]});
			}
		}
		num++;
		x >>= 1;
	}
	sort(l2.begin(), l2.end(), cmp);
	for(int i = 0; i < l2.size(); i++){
		if(findroot(l2[i].x) == findroot(l2[i].y)){
			continue;
		}
		else{
			sum += l2[i].w;
			Union(l2[i].x, l2[i].y);
		}
	}
	ans = min(ans, sum);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	init();
	for(int i = 1; i <= m; i++){
		cin >> l[i].x >> l[i].y >> l[i].w;
	}
	sort(l+1, l+(m+1), cmp);
	for(int i = 1; i <= m; i++){
		if(findroot(l[i].x) == findroot(l[i].y)){
			continue;
		}
		else{
			ans += l[i].w;
			Union(l[i].x, l[i].y);
			l1.push_back(l[i]);
		}
	}
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		} 
	}
	int num = 1;
	for(int i = 1; i <= k; i++){
		num *= 2;
	}
	for(int i = 1; i < num; i++){
		solved(i);
	}
	cout << ans;
	return 0;
}
