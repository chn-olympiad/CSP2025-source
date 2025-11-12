// Points that are worth to smile: it's dp

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
namespace common {
	int max(std::initializer_list<int> things) {
		int res = -1e9;
		for (const auto& t : things) res = std::max(res, t);
		return res;
	}
	int max_for_index(std::initializer_list<int> things) {
		int res = 0;
		for (int i = 0;i < things.size();i++) res = (*(things.begin() + res) >= *(things.begin() + i) ? res : i);
		return res;
	}
	int max_for_index(int* begin, int* end) {
		int* res = begin;
		for (int* i = begin;i < end;i++) res = (*res >= *i ? res : i);
		return res - begin;
	}
	int k_max_for_index(int* begin, int* end, int k) {
		int arr[end - begin];
		std::memcpy(arr, begin, end - begin);
		std::sort(arr, arr + (end - begin), std::greater<int>());
		return std::find(begin, end, arr[k - 1]) - begin;
	}
}
int n, score = 0;
int d_chosen_amount[3] { };
struct stu {
	int d[3] { };
	bool chosen { };
	bool operator<(const stu& another) const { 
		if (chosen) return false;
		if (another.chosen) return true;
		int d1[3] = { d[1], d[2], d[3] }, d2[3] = { another.d[1], another.d[2], another.d[3] };
		std::sort(d1, d1 + 3, std::greater<int>());
		std::sort(d2, d2 + 3, std::greater<int>());
		for (int i = 0;i < 3;i++) {
			if (d_chosen_amount[i] <= n / 2 && d1[i] < d2[i]) return true;
			else if (d_chosen_amount[i] <= n / 2 && d1[i] > d2[i]) return false;
		}
		return false;
	}
	bool operator>(const stu& another) const { 
		if (chosen) return true;
		if (another.chosen) return false;
		int d1[3] = { d[1], d[2], d[3] }, d2[3] = { another.d[1], another.d[2], another.d[3] };
		std::sort(d1, d1 + 3, std::greater<int>());
		std::sort(d2, d2 + 3, std::greater<int>());
		for (int i = 0;i < 3;i++) {
			if (d_chosen_amount[i] <= n / 2 && d1[i] < d2[i]) return false;
			else if (d_chosen_amount[i] <= n / 2 && d1[i] > d2[i]) return true;
		}
		return true;
	}
};

constexpr int maxn = 1e5 + 10;
std::vector<stu> students;
int main() {
	std::freopen("club.in", "r", stdin);
	std::freopen("club.out", "w", stdout);
	
	int t;
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		for (int i = 1;i <= n;i++) {
			stu s;
			for (int j = 0;j < 3;j++) {
				std::cin >> s.d[j];
			}
			students.emplace_back(s);
		}
		std::sort(students.begin(), students.end(), std::greater<stu>());
		bool stage2 = false;
		int abandoned_index = -1;
		for (int i = 0;i < students.size();i++) {
			if (students[i].chosen) continue;
			int index = common::max_for_index(students[i].d, students[i].d + 3);
			if (stage2 && index == abandoned_index) {
				index = common::k_max_for_index(students[i].d, students[i].d + 3, 2);
			}
			score += students[i].d[index];
			students[i].chosen = true;
			d_chosen_amount[index]++;
			//std::cout << "choose " << index << " for student " << i + 1 << ", get score " << students[i].d[index] << "\n";
			if (d_chosen_amount[index] == n / 2) stage2 = true, std::sort(students.begin(), students.end(), std::greater<stu>()), i = 0, abandoned_index = index;
		}
		std::cout << score << "\n";
		score = 0;
		std::memset(d_chosen_amount, 0, sizeof(int) * 3);
		students.clear();
	}
	
	std::fclose(stdin);
	std::fclose(stdout);
	return 0;
}