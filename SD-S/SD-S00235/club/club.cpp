#include <bits/stdc++.h>
#define endl '\n'
#define debug(x) std::cerr << #x << " = " << x << ", LINE " << __LINE__ << endl;
#define split(x) std::cerr << "------------------------------------ SPLIT LINE ------------------------------------" << endl;
typedef long long ll;

const int MOD = 1e9 + 7, N = 1e5 + 10;
int arr[N][5], cnt[5], sum[5], tmp[N], sec[N];

struct node {
	int id;
	friend bool operator <(const node a, const node b) {
//		debug(a.id); debug(b.id);
//		debug(tmp[a.id]); debug(tmp[b.id])
		return tmp[a.id] < tmp[b.id];
	}
};

void calc(const node a, const node b) {
	int a_maxid = 0, b_maxid = 0, a_max = -1, b_max = -1;
	for (int i = 1; i <= 3; i++) {
		if (arr[a.id][i] > a_max) {
			a_maxid = i;
			a_max = arr[a.id][i];
		}
		if (arr[b.id][i] > b_max) {
			b_maxid = i;
			b_max = arr[b.id][i];
		}
	}

	int a_maxid2 = 0, b_maxid2 = 0, a_max2 = -1, b_max2 = -1;		
	for (int i = 1; i <= 3; i++) {
		if (arr[a.id][i] > a_max2 && i != a_maxid) {
			a_maxid2 = i;
			a_max2 = arr[a.id][i];
		}
		if (arr[b.id][i] > b_max2 && i != b_maxid) {
			b_maxid2 = i;
			b_max2 = arr[b.id][i];
		}
	}
	tmp[a.id] = (a_max - a_max2); tmp[b.id] = (b_max - b_max2);
	sec[a.id] = a_maxid2; sec[b.id] = b_maxid2;
}

std::vector<node> vec[5];

ll qpow(ll a, ll b) { ll ans = 1; while (b) { if (b & 1) ans = ans * a % MOD; a = a * a % MOD; b >>= 1; } return ans; }

ll read() {
	ll res = 0; short f = 1; char ch = getchar();
	while (!('0' <= ch && ch <= '9')) { if (ch == '-') f = -f; ch = getchar(); }
	while ('0' <= ch && ch <= '9') { res = res * 10 + ch - 48; ch = getchar(); }
	return res * f;
}

std::string readstr() {
	std::string ret; char ch = getchar();
	while (ch <= 32) ch = getchar();
	while (ch > 32) { ret += ch; ch = getchar(); }
	return ret;
}

char readch() {
	char ch = getchar();
	while (ch < 32) ch = getchar();
	return ch;
} 

void write(ll x) {
	if (x < 0) { putchar('-'); write(-x); }
	else if (x <= 9) { putchar(x + 48); }
	else { write(x / 10); putchar(x % 10 + 48); }
}

void write(std::string x) {
	for (char ch : x) putchar(ch);
}

void writeln(ll x) { write(x); putchar('\n'); }

void writeln(std::string x) { write(x); putchar('\n'); }

void writes(ll x) { write(x); putchar(' '); }

void writes(std::string x) { write(x); putchar(' '); }

void solve() {
	for (int i = 1; i <= 3; i++) {
		vec[i].clear(); cnt[i] = 0;
		sum[i] = 0;
	}
	int n = read();
	for (int i = 1; i <= n; i++) {
		arr[i][1] = read(); arr[i][2] = read(); arr[i][3] = read();
		int max = -114514, maxid;
		for (int j = 1; j <= 3; j++) {
			if (max < arr[i][j]) { max = arr[i][j]; maxid = j; }
		}
//		debug(maxid);
		cnt[maxid]++; sum[maxid] += max; vec[maxid].push_back((node){i});
	}
	
//	for (int i = 1; i <= n; i++) {
//		debug(cnt[i]);
//	}
	
	for (int i = 1; i <= n; i++) {
		calc((node){i}, (node){i + 1});
//		debug(sec[i]); debug(tmp[i]);
	}
//	debug(max); 

	for (int i = 1; i <= 3; i++) { std::sort(vec[i].begin(), vec[i].end()); }
//	for (int i = 1; i <= 3; i++) {
//		for (node j : vec[i]) debug(j.id);
//		if (vec[i].empty()) std::cerr << "EMPTY" << endl;
//		split();
//	}
	
	int max = -1, maxid;
	for (int i = 1; i <= 3; i++) {
		if (max < cnt[i]) {
			max = cnt[i];
			maxid = i;
		}
	}
	
	if (max <= n / 2) {
		writeln(sum[1] + sum[2] + sum[3]);
//		std::cerr << "Success Exit\n";
		return;
	}
	
	int ans = sum[1] + sum[2] + sum[3];
//	std::cerr << "Initially, "; debug(ans);
	int other1 = (maxid + 1) % 3 + 1, other2 = maxid % 3 + 1, cha = max - n / 2;
//	debug(cha);
	for (int i = 1; i <= cha; i++) {
		cnt[sec[vec[maxid][i - 1].id]]++;
		ans -= tmp[vec[maxid][i - 1].id];
	}
//	debug(ans); split(); split(); split();
	writeln(ans);
}

int main() {
	clock();
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t = 1;
	t = read();
	while (t--) {
		solve();
	}
	std::cerr << clock() << "ms" << endl;
	return 0;
}

// 15:39 第 3 次打铃 间隔 45 分钟 
// 15:59 第 4 次打铃 间隔 20 分钟 

/*

吓哭了

编译结果...
--------
- 错误: 16
- 警告: 18
- 编译时间: 1.36s 

7MB Big Sample Test 

机器：Intel(R) Core(TM) i5-4590 CPU @ 3.30GHZ
运行内存：8 GB

5 Average(O2):
0.249
0.249
0.249
0.249
0.249 

5 Average(No optimize):
0.390
0.390
0.390
0.390
0.390

ok（这么稳吗 

最   终   M   V   P   结   算   画   面

编译结果...
--------
- 错误: 0
- 警告: 18

*/
