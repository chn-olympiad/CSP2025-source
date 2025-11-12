#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>

using namespace std;
constexpr int mxn = 1e5 + 1;

struct Input_date {
	long long a, b, c;
	
	long long &operator [](const unsigned long long &pos) {
		if(pos == 0)
			return a;
		if(pos == 1)
			return b;
		if(pos == 2)
			return c;
		return a;
	}
	
	long long operator [](const unsigned long long &pos) const {
		if(pos == 0)
			return a;
		if(pos == 1)
			return b;
		if(pos == 2)
			return c;
		return a;
	}
};

struct Delta_date {
	int id;
	long long delta;
	long long a, b;
	int delta_id;
	
	Delta_date(const int id, const int a, const int b, const int delta_id) : id(id), delta(a - b), a(a), b(b), delta_id(delta_id) {}
	
	bool operator <(const Delta_date &other) const noexcept {
		return abs(delta) < abs(other.delta);
	}
	
	bool operator >(const Delta_date &other) const noexcept {
		return abs(delta) > abs(other.delta);
	}
};

bool vis[mxn];
long long save(const vector<Input_date> &in) {
	cerr << "function start." << endl;
	vector<Delta_date> date, each[mxn];
	for(unsigned i = 0; i < in.size(); i++) {
		date.push_back(Delta_date(i, in[i].a, in[i].b, 1));
		each[i].push_back(Delta_date(i, in[i].a, in[i].b, 1));
		date.push_back(Delta_date(i, in[i].b, in[i].c, 2));
		each[i].push_back(Delta_date(i, in[i].b, in[i].c, 2));
		date.push_back(Delta_date(i, in[i].a, in[i].c, 3));
		each[i].push_back(Delta_date(i, in[i].a, in[i].c, 3));
		sort(each[i].begin(), each[i].end());
	}
	cerr << "build end." << endl;
	sort(date.begin(), date.end(), greater<>());
	for(auto &i: vis)
		i = false;
	long long ans = 0;
	const long long mxid = in.size() >> 1;
	long long cnt[3] = {};
	for(Delta_date &i: date) {
		if(vis[i.id])
			continue;
		if(i.delta_id == 1) {
			if(i.delta <= 0) {
				if(cnt[1] < mxid) {
					cnt[1]++;
					vis[i.id] = true;
					ans += i.b;
					continue;
				} else
					continue;
			}
			if(i.delta >= 0) {
				if(cnt[0] < mxid) {
					cnt[0]++;
					vis[i.id] = true;
					ans += i.a;
					continue;
				} else
					continue;
			}
		} else if(i.delta_id == 2) {
			if(i.delta <= 0) {
				if(cnt[2] < mxid) {
					cnt[2]++;
					vis[i.id] = true;
					ans += i.b;
					continue;
				} else
					continue;
			}
			if(i.delta >= 0) {
				if(cnt[1] < mxid) {
					cnt[1]++;
					vis[i.id] = true;
					ans += i.a;
					continue;
				} else
					continue;
			}
		} else if(i.delta_id == 3) {
			if(i.delta <= 0) {
				if(cnt[2] < mxid) {
					cnt[2]++;
					vis[i.id] = true;
					ans += i.b;
					continue;
				} else
					continue;
			}
			if(i.delta >= 0) {
				if(cnt[0] < mxid) {
					cnt[0]++;
					vis[i.id] = true;
					ans += i.a;
					continue;
				} else
					continue;
			}
		}
	}
	cerr << "function end." << endl; 
	return ans;
}

inline long long save_subA(const vector<Input_date> &in) {
	vector<int> date;
	for(auto &i: in)
		date.push_back(i.a);
	sort(date.begin(), date.end(), greater<>());
	const int mxid = (in.size() - 1) >> 1;
	long long ans = 0;
	for(int i = 0; i <= mxid; i++)
		ans += date[i];
	return ans;
}

inline long long save_subB(const vector<Input_date> &in) {
	vector<pair<long long, long long>> date;
	for(int i = 0; i < in.size(); i++)
		date.push_back({i, in[i].a - in[i].b});
	sort(date.begin(), date.end(), [&](const pair<long long, long long> &a, const pair<long long, long long> &b) { return a.second > b.second; });
	int cnt[2] = {};
	long long ans = 0;
	const int mxid = in.size() >> 1;
	for(auto &i: date) {
		if(i.second < 0) {
			if(cnt[1] < mxid) {
				cnt[1]++;
				ans += in[i.first].b;
			} else {
				cnt[0]++;
				ans += in[i.first].a;
			}
		} else {
			if(cnt[0] < mxid) {
				cnt[0]++;
				ans += in[i.first].a;
			} else {
				cnt[1]++;
				ans += in[i.first].b;
			}
		}
	}
	return ans;
}

long long small_ans = 0;
long long small_cnt[3] = {};
inline void small_save(const vector<Input_date> &in, unsigned id = 0, long long sum = 0) {
	if(id == in.size()) {
		small_ans = max(small_ans, sum);
		return;
	}
	const int mxid = in.size() >> 1;
	for(unsigned i = 0; i <= 2; i++) {
		if(small_cnt[i] < mxid) {
			small_cnt[i]++;
			small_save(in, id + 1, sum + in[id][i]);
			small_cnt[i]--;
		}
	}
}

int t, n;
vector<Input_date> in; 
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--) {
		bool is_subA = true, is_subB = true, is_subC = true;
		cin >> n;
		in.clear();
		in.resize(n);
		cerr << "this1" << endl;
		for(Input_date &i: in) {
			cin >> i.a >> i.b >> i.c;
			is_subA = is_subA & (i.b == 0 && i.c == 0);
			is_subB = is_subB & (i.c == 0);
		}
		cerr << "this2" << endl;
		if(is_subA) {
			cout << save_subA(in) << endl;
		} else if(is_subB) {
			cout << save_subB(in) << endl;
		} else if(n <= 30) {
			small_save(in);
			cout << small_ans << endl;
			small_ans = 0;
		} else
			cout << save(in) << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
