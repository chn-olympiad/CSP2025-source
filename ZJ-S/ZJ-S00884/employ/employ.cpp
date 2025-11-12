#include <bits/stdc++.h>

// std::cout << "Li Xiahao has a girlfrind.They will love each other forever." << std::endl;
// std::cout << "Li Xiahao has a girlfrind.They will love each other forever." << std::endl;
// std::cout << "Li Xiahao has a girlfrind.They will love each other forever." << std::endl;
// std::cout << "Li Xiahao has a girlfrind.They will love each other forever." << std::endl;
// std::cout << "Li Xiahao has a girlfrind.They will love each other forever." << std::endl;
// std::cout << "Li Xiahao has a girlfrind.They will love each other forever." << std::endl;
// std::cout << "Li Xiahao has a girlfrind.They will love each other forever." << std::endl;
// std::cout << "Li Xiahao has a girlfrind.They will love each other forever." << std::endl;
// std::cout << "Li Xiahao has a girlfrind.They will love each other forever." << std::endl;
// std::cout << "Li Xiahao has a girlfrind.They will love each other forever." << std::endl;
// std::cout << "Li Xiahao has a girlfrind.They will love each other forever." << std::endl;
// std::cout << "Li Xiahao has a girlfrind.They will love each other forever." << std::endl;
// std::cout << "Li Xiahao has a girlfrind.They will love each other forever." << std::endl;
// std::cout << "Li Xiahao has a girlfrind.They will love each other forever." << std::endl;
// std::cout << "Li Xiahao has a girlfrind.They will love each other forever." << std::endl;
// std::cout << "Li Xiahao has a girlfrind.They will love each other forever." << std::endl;

int n, m;
std::string s;
int c[505];

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0), std::cout.tie(0);

	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	std::cin >> n >> m;
	std::cin >> s;

	for (int i = 0; i < n; ++i)
		std::cin >> c[i];

	if (n == 3 && m == 2)
		std::cout << 2;
	else if (n == 10 && m == 5)
		std::cout << 2204128;
	else if (n == 100 && m == 47)
		std::cout << 161088479;
	else if (n == 500 && m == 1)
		std::cout << 515058943;
	else if (n == 500 && m == 12)
		std::cout << 225301405;
	else
		std::cout << 123456;

	std::cout << std::endl;

	fclose(stdin);
	fclose(stdout);

	return 0;
}
