#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
	T s = 0; int st = 1; char c = getchar();
	while(c < '0' || c > '9'){(c == '-') && (st = -1); c = getchar();}
	while(c >= '0' && c <= '9'){s = (s << 3) + (s << 1) + (c ^ 48); c = getchar();}
	x = s * st;
}
template<typename T> inline void write(T x){
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
//#define int long long 
#define LL long long 
#define PII pair<int, int> 
const int N = 1e5 + 5;
bool vis[N];
int cnt[4], n, ans;
LL a[N][4];
int tmp[N];
void dfs(int k, int cntt[4]){
	if(k > n){
		int num = 0;
		for(int i = 1; i <= n; ++i){
			num += a[i][tmp[i]];
		}
		ans = max(ans, num);
		return;
	}
	for(int i = 1; i <= 3; ++i){
		if(cntt[i] + 1 <= n / 2){
			tmp[k] = i;
			++cntt[i];
			dfs(k + 1, cntt);
			--cntt[i];
		}
	}
}
inline void run(){
	ans = 0;
	read(n);
	
	priority_queue<tuple<LL, int, int> > q;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= 3; ++j){
			read(a[i][j]);
		}
		q.push(make_tuple(a[i][1] - a[i][2] - a[i][3], i, 1));
		q.push(make_tuple(a[i][2] - a[i][1] - a[i][3], i, 2));
		q.push(make_tuple(a[i][3] - a[i][1] - a[i][2], i, 3));
		vis[i] = 0;
	}
	if(n <= 10){
		int cnttt[4];
		cnttt[1] = cnttt[2] = cnttt[3] = 0;
		dfs(1, cnttt);
		write(ans);
		putchar('\n');
		return;
	}
	cnt[1] = cnt[2] = cnt[3] = 0;
	while(!q.empty()){
		int val = get<0>(q.top()), id = get<1>(q.top()), bel = get<2>(q.top());
		q.pop();
		while(!q.empty() && (vis[id] || cnt[bel] + 1 > n / 2)){
			val = get<0>(q.top()), id = get<1>(q.top()), bel = get<2>(q.top());
			q.pop();
		}
		if(vis[id] || cnt[bel] + 1 > n / 2) break;
		vis[id] = 1; ++cnt[bel];
		ans += a[id][bel];
//		cerr << val << ' ' << id << ' ' << bel << endl;
	}
	
	write(ans);
	putchar('\n');
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	read(T);
	while(T--) run();
	return 0;
}
/*
10
3 6839 5455 15586
2 11767 12919 2643
1 13775 8904 19938
1 13717 11997 15170
3 13707 2404 17497
3 3471 2462 8073
1 18467 14346 18663
3 13582 4839 15785
1 11875 7476 12308
3 8568 3134 18522
*/