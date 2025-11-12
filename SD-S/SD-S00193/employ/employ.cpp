#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 550;

int n , m;
char s[N];
int c[N];

void bl1();

int main() {
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);

	scanf("%d%d%s" , &n , &m , s+1);
	for(int i = 1 ; i <= n ; i ++)
		scanf("%d" , &c[i]);
	
	if(n <= 10) {
		bl1();
		return 0;
	}
	
	bool Bbl2 = true;
	for(int i = 1 ; i <= n ; i ++)
		if(s[i] == '0') {
			Bbl2 = false;
			break;
		}
	
	int cnt = 0;
	for(int i = 1 ; i <= n ; i ++)
		if(c[i] == 0) cnt ++;
	if(n - cnt < m) puts("0");
	return 0;
}

void dfsbl1(int u , int& res , int p[15] , bool st[15]) {
	if(u > n) {
		int now = 0 , tmp = 0;
		for(int i = 1 ; i <= n ; i ++) {
			if(now < c[p[i]] && s[i] == '1') tmp ++;
			else now ++;
		}
		if(tmp >= m) res ++;
		return;
	}
	
	for(int i = 1 ; i <= n ; i ++) {
		if(st[i]) continue;
		
		st[i] = true; p[u] = i;
		dfsbl1(u+1 , res , p , st);
		st[i] = false;
	}
}

void bl1() {
	// 20pts
	int p[15] = {}; bool st[15] = {};
	int res = 0;
	dfsbl1(1 , res , p , st);
	printf("%d\n" , res);
}
