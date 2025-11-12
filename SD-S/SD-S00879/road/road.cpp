#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-'){
			f = -1;
		}
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
void print(int x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9){
		print(x / 10);
	}
	putchar(x % 10 + '0');
}
int id[100005], idx;
int finds(int x){
	return (id[x] == x ? x : finds(id[x]));
}
void merge1(int x, int y){
	int p = finds(x);
	int q = finds(y);
	id[p] = q;
}
struct node{
	int fir,sec,thi;
}e[10005];
int c[10005], n, m, k, a[15][10005], res;
int work(){
	int ans = 0;
	priority_queue <pair <int, int>> q;
	for(int i = 1; i <= n + k; i ++){
		id[i] = i;
	}
	int cnt = n;
	for(int i = 1; i <= idx; i ++){
		q.push({-e[i].fir, i});
	}
	while(!q.empty()){
		int t = q.top().second;
		int w = -q.top().first;
		q.pop();
		int u = e[t].sec;
		int v = e[t].thi;
		if(finds(u) != finds(v)){
			merge1(u, v);
			ans += w;
			cnt --;
		}
		if(cnt == 1){
			return ans;
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read(), m = read(), k = read();
	for(int i = 1; i <= m; i ++){
		int u, v, w;
		u = read(), v = read(), w = read();
		e[i] = {w, u, v};
	}
	idx = m + 1;
	for(int i = 1; i <= k; i ++){
		c[i] = read();
		for(int j = 1; j <= n; j ++){
			a[i][j] = read();
			e[idx ++] = {a[i][j], n + i, j};
		}
	}
	res = work();
	print(res);
	return 0;
}


