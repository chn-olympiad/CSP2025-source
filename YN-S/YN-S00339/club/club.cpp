#include <iostream>
#include <cstdio>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;


int do_it(vector<array<int, 4>> *group_data, int cnt_a, int cnt_b, int cnt_c, int max_number, int cnt_obj = 0,
          bool begin = false,
          int current_val = 0) {
	if (begin == false) {
		int max_val_ = 0;
		int max_val = 0;
		for (int i = 0; i < 3; i++) {
			max_val = (*group_data)[cnt_obj][i];
			if (i == 0) {
				max_val_ = max(max_val_, do_it(group_data, cnt_a - 1, cnt_b, cnt_c, max_number, cnt_obj + 1, true, max_val));

			}
			if (i == 1) {
				max_val_ = max(max_val_, do_it(group_data, cnt_a, cnt_b - 1, cnt_c, max_number, cnt_obj + 1, true, max_val));

			};
			if (i == 2) {
				max_val_ = max(max_val_, do_it(group_data, cnt_a, cnt_b, cnt_c - 1, max_number, cnt_obj + 1, true, max_val));
			}
		}
		return max_val_;
	} else {
		if (cnt_obj >= max_number) {
			return -1;
		};
		int max_val = 0;
		int orginal_ = current_val;
		for (int i = 0; i < 3; i++) {
			current_val = orginal_;
			if (i == 0 && cnt_a != 0) {
				current_val += (*group_data)[cnt_obj][i];
				current_val = max(current_val, do_it(group_data, cnt_a - 1, cnt_b, cnt_c, max_number, cnt_obj + 1, true, current_val));
				max_val = max(max_val, current_val);
			}
			if (i == 1 && cnt_b != 0) {
				current_val += (*group_data)[cnt_obj][i];
				current_val = max(current_val, do_it(group_data, cnt_a, cnt_b - 1, cnt_c, max_number, cnt_obj + 1, true, current_val));
				max_val = max(max_val, current_val);
			}
			if (i == 2 && cnt_c != 0) {
				current_val += (*group_data)[cnt_obj][i];
				current_val = max(current_val, do_it(group_data, cnt_a, cnt_b, cnt_c - 1, max_number, cnt_obj + 1, true, current_val));
				max_val = max(max_val, current_val);
			}
		}
		return max_val;
	}
};

int get_it(vector<array<int, 4>> *group_data, int number_count) {
	int cnt_a = number_count / 2;
	int cnt_b = number_count / 2;
	int cnt_c = number_count / 2;
	return do_it(group_data, cnt_a, cnt_b, cnt_c, number_count);
};

int main(void) {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int group_test = 0;
	int group_number = 0;
	int people_count = 0;
	scanf("%d", &group_test);
	vector<array<int, 4>> *group_data = new vector<array<int, 4>>();
	for (int i = 0; i < group_test; i++) {
		scanf("%d", &group_number);
		for (int j = 0; j < group_number; j++) {
			group_data->push_back(array<int, 4>());
			scanf("%d %d %d", &(*group_data)[j][0], &(*group_data)[j][1], &(*group_data)[j][2]);
			(*group_data)[j][3] = 1;
		}
		int result = get_it(group_data, group_number);
		printf("%d\n", result);
		group_data->clear();
	};
	return 0;
}