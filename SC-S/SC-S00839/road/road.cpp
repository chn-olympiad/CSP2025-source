#include<bits/stdc++.h>
using namespace std;

const int M = 2e6 + 10;
const int N = 1e4 + 100;
//开long long 
struct node{
	long long a, b, c;
}e[M], ee[M];


int et;
long long n, m, k;

long long t[15][N];

long long cc[15];

long long b[15];

long long ans = 1e18;

int tt, cnt;

bool cmp(node a, node b){
	return a.c < b.c;
}


int f[N];

int find(int x){
	if(x == f[x])return x;
	return f[x] = find(f[x]);
}



long long kl(){
	for(int i = 1;i <= tt;i ++){
		f[i] = i;
	}
	sort(ee + 1, ee + cnt + 1, cmp);
	long long sum = 0;
	for(int i = 1;i <= cnt;i ++){
		int a = ee[i].a, b = ee[i].b, c = ee[i].c;
		a = find(a), b = find(b);
		if(a != b){
			f[a] = b;
			sum += c;
		}
		et ++;
		if(et >= 1e8)return 0;
	}
	return sum;
}

void work(){
	long long sum = 0;
	cnt = 0;
	for(int i = 1;i <= m;i ++){
		ee[++cnt] = e[i];
	}
	tt = n;
	for(int i = 1;i <= k;i ++){
//		cout << b[i] << " ";
		if(b[i]){
			tt ++;
			sum += cc[i];
			for(int j = 1;j <= n;j ++){
				ee[++cnt] = {tt, j, t[i][j]};
			}
		}
	} 
	sum += kl(); 
//	cout << sum << " " << tt << " " << cnt << endl;
	ans = min(ans, sum);
	return ;
}

void dfs(int u){
	if(et >= 1e8)return ;
	if(u > k){
//		cout << "?????" << endl;
		work();
		return ;
	}
	b[u] = 1;
	dfs(u + 1);
	b[u] = 0;
	dfs(u + 1);
	return ;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	for(int i = 1;i <= m;i ++){
		long long a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		e[i] = {a, b, c};
	}
	for(int i = 1;i <= k;i ++){
		scanf("%lld", &cc[i]);
		for(int j = 1;j <= n;j ++){
			scanf("%lld", &t[i][j]);
		}
	}
	dfs(1);
	if(et >= 1e8){
		printf("0\n");
		return 0;
	}
	printf("%lld\n", ans);
	
	return 0;
}