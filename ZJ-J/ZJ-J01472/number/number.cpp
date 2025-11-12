//CCF CSP-J/S 2025 Junior
//number.cpp

#include <iostream>
#include <string.h>
#include <algorithm>

std::string solve1(std::string s);
std::string solve2(std::string s);

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	std::string str;
	std::cin >> str;
	
	std::cout << solve2(solve1(str));
	
	return 0;
}

std::string solve1(std::string s) {
	std::string ans;
	int t = 0;
	
	for (int i = 0; (int(s[i]) <= 57 && int(s[i]) >= 48) || (int(s[i]) <= 122 && int(s[i]) >= 97); ++i) {
		if (int(s[i]) <= 57 && int(s[i]) >= 48) {
			ans += s[i];
			t++;
		}
	}
	
	return ans;
}

std::string solve2(std::string t) {
	
	int lllen = 0;
	for (; int(t[lllen]) <= 57 && int(t[lllen]) >= 48; ++lllen);
	
	while (true) {
		bool isSorted = 1;
		for (int i = 0; i <= lllen - 2; ++i) {
			if (int(t[i]) < int(t[i + 1])) {
				char tmp;
				isSorted = 0;
				tmp = t[i + 1];
				t[i + 1] = t[i];
				t[i] = tmp;
			}
		}
		if (isSorted == 1) break;
	}
	
	return t;
}

//written by ZJ-J01472
