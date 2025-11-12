#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int xxyy = 0;
	int p = false;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') p = true;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		xxyy = (xxyy << 1) + (xxyy << 3) + (ch & 15);
		ch = getchar();
	}
	return p ? -xxyy : xxyy;
}
int n, T = read();
struct cmp {
	int a[2] = {0, 0}, b[2] = {0, 1}, c[2] = {0, 2};
} s[100010];
int tong[3];
bool cm(cmp x, cmp y) {
	return x.a[0] > y.a[0];
}
long long sum;
int biao, times;
int d[3] = {1, 2, 3};
long long maxx = -1;
void dfs(int i, long long j){
	if(i == n) {
		maxx = max(maxx, j);
		return ;
	}
	if(tong[0] * 2 < n)	{
		tong[0]++;
		dfs(i + 1, j + s[i + 1].a[0]);
		tong[0]--;
	}
	if(tong[1] * 2 < n){
		tong[1]++;
		dfs(i + 1, j + s[i + 1].b[0]);
		tong[1]--;
	} 
	if(tong[2] * 2 < n){
		tong[2]++;
		dfs(i + 1, j + s[i + 1].c[0]);
		tong[2]--;
	} 
}
int main() {
	freopen("club.in", "r", stdin);
    freoepn("club.out", "w", stdout);
	while(T--){
		n = read();
		memset(s, 0, sizeof(s));
		memset(tong, 0, sizeof(tong));
		biao = -1;
		sum = 0;
		times = 0;
		for(int i = 1; i <= n; i++) {
			s[i].a[0] = read();
			s[i].b[0] = read();
			s[i].c[0] = read();
			s[i].a[1] = 0;
			s[i].b[1] = 1;
			s[i].c[1] = 2;
			if(s[i].a[0] < s[i].b[0]) {
				swap(s[i].a[0], s[i].b[0]);
				swap(s[i].a[1], s[i].b[1]);
			}
			if(s[i].a[0] < s[i].c[0]) {
				swap(s[i].a[0], s[i].c[0]);
				swap(s[i].a[1], s[i].c[1]);
			}
			if(s[i].b[0] < s[i].c[0]) {
				swap(s[i].b[0], s[i].c[0]);
				swap(s[i].b[1], s[i].c[1]);
			}
		}
		if(n <= 10){
			dfs(0, 0);
			cout << maxx << endl;
			continue;
		}
		sort(s + 1, s + 1 + n, cm);
		for(int i = 1; i <= n; i++) {
			if(biao != s[i].a[1]){
				sum += s[i].a[0];
				tong[s[i].a[1]]++;
			}else sum += s[i].b[0];
			if(tong[s[i].a[1]] * 2 >= n){
				biao = s[i].a[1];
				times++;
			} 
			if(times == 2) break;
		}
		cout << sum << endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
