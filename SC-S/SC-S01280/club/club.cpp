#include <bits/stdc++.h>

#define N ((int)1e5 + 10)

using namespace std;

int T, n;

struct stu {
	int id;
	int w[3];
	int mx, nxt;
	
	inline void get_mx() {
		int mx_val = -1, nxt_val = -1;
		for(int i = 0;i < 3;i++) {
			if(w[i] > mx_val) {
				nxt = mx;
				nxt_val = mx_val;
				
				mx = i;
				mx_val = w[i];
			}
			else if(w[i] > nxt_val) {
				nxt = i;
				nxt_val = w[i];
			}
		}
	}
	
	inline void print() {
		cout << id << " ："; 
		cout << w[0] << "," << w[1] << "," << w[2] << " ";
		cout << mx << " " << nxt << endl;
	}
};
vector<stu> a;

queue<stu> q;
int c[N][3], id[N][3];
int siz[3];

inline void clear_all() {
	a.clear();
	a.resize(n + 1);
	for(int i = 0;i < 3;i++) {
		for(int j = 0;j <= siz[i];j++) {
			c[j][i] = id[j][i] = 0;
		}
	}
	siz[0] = siz[1] = siz[2] = 0;
}

inline void solve1();
inline bool check_A();
inline void solve2();
inline bool check_B();
inline void solve3();

int main() {
#ifdef XYX
//	freopen("club2.in", "r", stdin);
//	freopen("club2.out", "w", stdout);
#else 
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
#endif 
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	while(T--) {
		cin >> n;
		clear_all();
		
		for(int i = 1;i <= n;i++) {
			cin >> a[i].w[0] >> a[i].w[1] >> a[i].w[2];
			a[i].id = i;
			a[i].get_mx();
			q.push(a[i]);
		}

#ifdef XYX
		solve3();
		continue;
#else	
		if(n <= 10) {
			solve1();
			continue; 
		}
		else if(check_A()) {
			solve2();
			continue;
		}
		else if(check_B()) {
			solve3();
			continue;
		}
#endif 
#ifdef XYX
//		while(!q.empty()) {
//			stu u = q.front();
//			q.pop();
//			cout << u.id << " ："; 
//			cout << u.w[0] << "," << u.w[1] << "," << u.w[2] << " " << u.mx << " " << u.nxt << endl;
//		}
#endif
		
		while(!q.empty()) {
			stu u = q.front();
			q.pop();
#ifdef XYX
			u.print();
#endif
			
			int t = u.mx;
			int pla = lower_bound(c[t] + 1, c[t] + siz[t] + 1, u.w[t]) - (c[t] + 1);
#ifdef XYX
			cout << pla << endl;
#endif 
			if(siz[t] < n / 2) {
				for(int i = siz[t];i >= pla;i--) {
					c[i + 1][t] = c[i][t];
					id[i + 1][t] = id[i][t]; 
				}
				c[pla][t] = u.w[t];
				id[pla][t] = u.id;
				++siz[t];
			}
			else {
				stu tt = a[id[siz[t] - 1][t]];
				tt.mx = tt.nxt;
				q.push(tt);
				
				for(int i = siz[t] - 1;i >= pla;i--) {
					c[i + 1][t] = c[i][t];
					id[i + 1][t] = id[i][t]; 
				}
				
				c[pla][t] = u.w[t];
				id[pla][t] = u.id;
			}
#ifdef XYX
			for(int i = 0;i < 3;i++) {
				for(int j = 0;j <= n;j++) {
					cout << c[j][i] << "," << id[j][i] << " ";
				}
				cout << "  siz = " << siz[i];
				cout << endl;
			}
#endif
		}
		
		int ans = 0;
		for(int i = 0;i < 3;i++) {
			for(int j = 0;j <= siz[i];j++) {
				ans += c[j][i];
			}
		}
		cout << ans << "\n";
	} 
	
	return 0;
}

int chose[15], t[3], ans;
inline void dfs(int u) {
	if(u == n + 1) {
		int cnt = 0;
		for(int i = 1;i <= n;i++) {
			cnt += a[i].w[chose[i]];
		}
		ans = max(ans, cnt);
		return;
	}
	
	if(t[0] < n / 2) {
		t[0]++;
		chose[u] = 0;
		dfs(u + 1);
		t[0]--;
	}
	if(t[1] < n / 2) {
		t[1]++;
		chose[u] = 1;
		dfs(u + 1);
		t[1]--;
	}
	if(t[2] < n / 2) {
		t[2]++;
		chose[u] = 2;
		dfs(u + 1);
		t[2]--;
	}
}

inline void solve1() {
#ifdef XYX
	cout << "solve1" << endl;
#endif
	memset(chose, 0, sizeof chose);
	memset(t, 0, sizeof t);
	ans = 0;
	dfs(1);
	cout << ans << "\n";
}

inline bool check_A() {
	for(int i = 1;i <= n;i++) {
		if(a[i].w[1] != 0 || a[i].w[2] != 0) return 0;
	}
	return 1;
}
inline void solve2() {
	vector<int> t(n + 5, 0);
	for(int i = 1;i <= n;i++) {
		t[i] = a[i].w[0];
	}
	
	sort(t.begin() + 1, t.begin() + n + 1);
#ifdef XYX
	for(int i = 1;i <= n;i++) {
		cout << t[i] << " ";
	}
#endif
	
	int ans = 0;
	for(int i = n;i > n / 2;i--) {
		ans += t[i];
	}
	cout << ans << "\n";
}

struct dt {
	int a, b;
	
	inline bool operator < (const dt &d2) const {
		return a < d2.a;
	}
};
vector<dt> b;

inline bool check_B() {
	for(int i = 1;i <= n;i++) {
		if(a[i].w[2] != 0) return 0;
	}
	return 1;
}
inline void solve3() {
	b.clear();
	b.resize(n + 5);
	
	int ans = 0;
	for(int i = 1;i <= n;i++) {
		int mi = min(a[i].w[0], a[i].w[1]);
		b[i].a = a[i].w[0] - mi;
		b[i].b = a[i].w[1] - mi;
		ans += mi; 
	}
	
	sort(b.begin() + 1, b.begin() + n + 1);
#ifdef XYX
	for(int i = 1;i <= n;i++) {
		cout << b[i].a << " " << b[i].b << endl;
	}
#endif
	
	for(int i = n;i > n / 2;i--) {
		ans += b[i].a;
	}
	for(int i = n / 2;i > 0;i--) {
		ans += b[i].b;
	}
	cout << ans << "\n";
}

/*
1
4
2 1 0
1 2 0
10 9 0
9 8 0

1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
*/