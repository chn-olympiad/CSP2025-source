#include <algorithm>
#include <iostream>
#include <vector>

struct area {
	int l, r;
};
bool f(area a, area b);

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int n, k, *t, *a, result = 0, current = 0;
	std::vector<area> areas;
	
	std::cin >> n >> k;
	t = (int*)malloc(sizeof(int) * n);
	a = (int*)malloc(sizeof(int) * n);
	
	std::cin >> t[0];
	a[0] = t[0];
	if(t[0] = k){
		areas.push_back({0,0});
	}
	for(int c = 1; c < n; c++) {
		std::cin >> t[c];
		if(t[c] == k) {
			area x = {c, c};
			areas.push_back(x);
		}
		a[c] = t[c]^a[c - 1];
		std::cout << t[c] << ' ' << a[c] << std::endl;
	}
	for(int c = 0; c < (n - 1); c++) {
		for(int C = (c + 1); C < n; C++) {
			std::cout << c << ' ' << C << ' ' << a[c] << ' ' << a[C] << ' ' << (a[c]^a[C]) << ' ' << k << std::endl;
			if((a[c]^a[C]) == k) {
				area x = {c, C};
				areas.push_back(x);
				break;
			}
		}
	}
	std::sort(areas.begin(), areas.end(), f);
	for(int c= 0; c < areas.size(); c++) {
		if(areas[c].l >= current) {
			current = areas[c].r;
			result++;
		}
    }
    std::cout << result;

	return 0x000000;
}

bool f(area a, area b){
	return a.r < b.r;
}
