#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>


namespace club {
	std::ofstream fout("club.out");
	struct student {
		int a, b, c;
		int max;
		int index;
		std::pair<int *, int> other1, other2;
	};
	void solve(int n, std::vector<student> data) {
		int limit = n / 2;
		std::vector<unsigned> cnt(3, 0);
		unsigned long long ans = 0;
		for (auto &s : data) {
			if (cnt[s.index] < limit) {
				++cnt[s.index];
				ans += s.max;
				continue;
			} else {
				std::pair<int *, int> max, min;
				if (*(s.other1.first) > *s.other2.first) {
					max = s.other1;
					min = s.other2;
				} else {
					max = s.other2;
					min = s.other1;
				}
				if (cnt[max.second] < limit) {
					++cnt[max.second];
					ans += *max.first;
				} else {
					++cnt[min.second];
					ans += *min.first;
				}
			}
		}
		fout << ans << "\n";
	}
}

int main() {
	unsigned t;
	std::ifstream fin("club.in");
	fin >> t;
	while (t--) {
		int n;
		fin >> n;
		std::vector<club::student> data;
		for (int i = 0; i < n; ++i) {
			club::student s;
			fin >> s.a >> s.b >> s.c;
			s.max = std::max(s.a, std::max(s.b, s.c));
			if (s.max == s.a) {
				s.index = 0;
				s.other1 = {&s.b, 1};
				s.other2 = {&s.c, 2};
			} else if (s.max == s.b) {
				s.index = 1;
				s.other1 = {&s.a, 0};
				s.other2 = {&s.c, 2};
			} else {
				s.index = 2;
				s.other1 = {&s.a, 0};
				s.other2 = {&s.b, 1};
			}
			data.push_back(s);

		}
		std::sort(data.begin(), data.end(),
		[](const club::student & a, const club::student & b) {
			return a.max > b.max;
		});
		club::solve(n, data);
	}
}