#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Worker {
	int a;
	int b;
	int c;
	int max_w, max_i;
	int mid_w, mid_i;
	int low_w, low_i;

	Worker() {
		max_w = -1;
		max_i = -1;
		mid_w = -1;
		mid_i = -1;
		low_w = -1;
		low_i = -1;
	}
};

void enter(int& job, int& a, int &b, int &c) {
	switch (job) {
		case 1:
			a++;
			break;
		case 2:
			b++;
			break;
		case 3:
			c++;
			break;
		default:
			break;
	}
}

int get_job_entered(int& job, int& a, int& b, int& c) {
	switch (job) {
		case 1:
			return a;
			break;
		case 2:
			return b;
			break;
		case 3:
			return c;
			break;
		default:
			return 0;
			break;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	int t;
	cin >> t;
	while (t -- > 0) {
		int n;
		cin >> n;
		vector<Worker> workers;
		for (int i = 0; i < n; i++) {
			int a1, a2, a3;
			cin >> a1 >> a2 >> a3;
			Worker w;
			w.a = a1;
			w.b = a2;
			w.c = a3;
			workers.push_back(w);
			if (a1 > a2) {
				if (a1 > a3) {
					workers[workers.size() - 1].max_w = a1;
					workers[workers.size() - 1].max_i = 1;
					if (a2 > a3) {
						workers[workers.size() - 1].mid_w = a2;
						workers[workers.size() - 1].mid_i = 2;
						workers[workers.size() - 1].low_w = a3;
						workers[workers.size() - 1].low_i = 3;
					} else if (a3 > a2) {
						workers[workers.size() - 1].mid_w = a3;
						workers[workers.size() - 1].mid_i = 3;
						workers[workers.size() - 1].low_w = a2;
						workers[workers.size() - 1].low_i = 2;
					} else {
						workers[workers.size() - 1].mid_w = a2;
						workers[workers.size() - 1].mid_i = 2;
						workers[workers.size() - 1].low_w = a3;
						workers[workers.size() - 1].low_i = 3;
					}
				} else if (a3 > a1) {
					workers[workers.size() - 1].max_w = a3;
					workers[workers.size() - 1].max_i = 3;
					workers[workers.size() - 1].mid_w = a1;
					workers[workers.size() - 1].mid_i = 1;
					workers[workers.size() - 1].low_w = a2;
					workers[workers.size() - 1].low_i = 2;
				} else {
					workers[workers.size() - 1].max_w = a1;
					workers[workers.size() - 1].max_i = 1;
					workers[workers.size() - 1].mid_w = a3;
					workers[workers.size() - 1].mid_i = 3;
					workers[workers.size() - 1].low_w = a2;
					workers[workers.size() - 1].low_i = 2;
				}
			} else if (a2 > a1) {
				if (a2 > a3) {
					workers[workers.size() - 1].max_w = a2;
					workers[workers.size() - 1].max_i = 2;
					if (a1 > a3) {
						workers[workers.size() - 1].mid_w = a1;
						workers[workers.size() - 1].mid_i = 1;
						workers[workers.size() - 1].low_w = a3;
						workers[workers.size() - 1].low_i = 3;
					} else if (a3 > a1) {
						workers[workers.size() - 1].mid_w = a3;
						workers[workers.size() - 1].mid_i = 3;
						workers[workers.size() - 1].low_w = a1;
						workers[workers.size() - 1].low_i = 1;
					} else {
						workers[workers.size() - 1].mid_w = a1;
						workers[workers.size() - 1].mid_i = 1;
						workers[workers.size() - 1].low_w = a3;
						workers[workers.size() - 1].low_i = 3;
					}
				} else if (a3 > a2) {
					workers[workers.size() - 1].max_w = a3;
					workers[workers.size() - 1].max_i = 3;
					workers[workers.size() - 1].mid_w = a2;
					workers[workers.size() - 1].mid_i = 2;
					workers[workers.size() - 1].low_w = a1;
					workers[workers.size() - 1].low_i = 1;
				} else {
					workers[workers.size() - 1].max_w = a2;
					workers[workers.size() - 1].max_i = 2;
					workers[workers.size() - 1].mid_w = a3;
					workers[workers.size() - 1].mid_i = 3;
					workers[workers.size() - 1].low_w = a1;
					workers[workers.size() - 1].low_i = 1;
				}
			} else {
				if (a3 > a1) {
					workers[workers.size() - 1].max_w = a3;
					workers[workers.size() - 1].max_i = 3;
					workers[workers.size() - 1].mid_w = a1;
					workers[workers.size() - 1].mid_i = 1;
					workers[workers.size() - 1].low_w = a2;
					workers[workers.size() - 1].low_i = 2;
				} else if (a1 > a3) {
					workers[workers.size() - 1].max_w = a1;
					workers[workers.size() - 1].max_i = 1;
					workers[workers.size() - 1].mid_w = a2;
					workers[workers.size() - 1].mid_i = 2;
					workers[workers.size() - 1].low_w = a3;
					workers[workers.size() - 1].low_i = 3;
				} else {
					workers[workers.size() - 1].max_w = a1;
					workers[workers.size() - 1].max_i = 1;
					workers[workers.size() - 1].mid_w = a2;
					workers[workers.size() - 1].mid_i = 2;
					workers[workers.size() - 1].low_w = a3;
					workers[workers.size() - 1].low_i = 3;
				}
			}
		}
		sort(workers.begin(), workers.end(), [](Worker & a, Worker & b) {
			return a.max_w > b.max_w;
		});
		int a = 0, b = 0, c = 0;
		int want_sum = 0;
		for (auto& worker : workers) {
			if (worker.max_w > worker.mid_w) {
				if (get_job_entered(worker.max_i, a, b, c) < n / 2) {
					enter(worker.max_i, a, b, c);
					want_sum += worker.max_w;
				} else {
					enter(worker.mid_i, a, b, c);
					want_sum += worker.mid_w;
				}
			} else {
				if (get_job_entered(worker.max_i, a, b, c) > get_job_entered(worker.mid_i, a, b, c)) {
					enter(worker.mid_i, a, b, c);
					want_sum += worker.mid_w;
				} else {
					enter(worker.max_i, a, b, c);
					want_sum += worker.max_w;
				}
			}
		}
		cout << want_sum <<endl;
	}
}
