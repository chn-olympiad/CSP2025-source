#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long LL;

struct Node {
	int u , v; LL w;
};

const int N = 1e4+10 , M = 1e6+10;

int n , m , k;
Node a[M+N*10];
int p[N+15];
LL co[15];
vector<int> vec[15];

int find(int x) {
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

void bl1();
void bl2();

int main() {
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	
	scanf("%d%d%d" , &n , &m , &k);
	for(int i = 1 ; i <= m ; i ++) {
		scanf("%d%d%lld" , &a[i].u , &a[i].v , &a[i].w);
	}
	for(int i = 1 ; i <= n ; i ++) p[i] = i;
	bool Bbl1 = false;
	for(int i = 1 ; i <= k ; i ++) {
		scanf("%lld" , &co[i]);
		for(int j = 1 ; j <= n ; j ++) {
			LL v; scanf("%lld" , &v);
			vec[i].push_back(v);
			if(v == 0) Bbl1 = true;
		}
	}
	for(int i = 1 ; i <= k ; i ++)
		if(co[i]) {
			Bbl1 = false;
			break;
		}
	
	if(k == 0 || Bbl1) {
		bl1();
		return 0;
	}
	
//	if(k <= 5) {
		bl2();
//		return 0;
//	}
	return 0;
}

void bl1() {
	// 48pts
	int block = n; LL res = 0;
	for(int i = 1 ; i <= k ; i ++) {
		int t = -1;
		for(int j = 0 ; j < n ; j ++) 
			if(vec[i][j] == 0) t = j+1;
		
		for(int j = 0 ; j < n ; j ++)
			a[++m] = {t , j+1 , vec[i][j]};
	}
	
	sort(a+1 , a+m+1 , [](const Node& a , const Node& b) {
		return a.w < b.w;
	});
	for(int i = 1 ; i <= m ; i ++) {
		if(find(a[i].u) == find(a[i].v)) continue;
		res += a[i].w;
		p[find(a[i].u)] = find(a[i].v);
		block --;
		if(block == 1) break;
	}
	printf("%lld\n" , res);
	return;
}

void bl2() {
	// 24pts
	LL ans = 0x3f3f3f3f3f3f3f3f;
	for(int state = 0 ; state < (1<<k) ; state ++) {
		for(int i = 1 ; i <= n+k ; i ++)
			p[i] = i;
		
		LL res = 0;
		int tmpm = m , block = n;
		for(int i = 0 ; i < k ; i ++) {
			if(!(state & (1 << i))) continue;
			res += co[i+1];
//			puts("???");
			for(int j = 0 ; j < n ; j ++) {
				a[++tmpm] = {j+1 , n+i+1 , vec[i+1][j]};
			}
		}
		sort(a+1 , a+tmpm+1 , [](const Node& a , const Node& b) {
			return a.w < b.w;
		});
		for(int i = 1 ; i <= tmpm ; i ++) {
//			printf("? %d %d\n" , a[i].u , a[i].v);
			if(find(a[i].u) == find(a[i].v)) continue;
			res += a[i].w;
			p[find(a[i].u)] = find(a[i].v);
			if(a[i].u <= n && a[i].v <= n) block --;
			if(block == 1) break;
		}
		ans = min(ans , res);
//		printf("! %d %lld\n" , state , res);
	}
	printf("%lld\n" , ans);
	return;
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
