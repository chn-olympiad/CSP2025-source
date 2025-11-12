#include <iostream>
using std::cin; using std::cout;

inline void freopen(std::string const && s) noexcept
{
	std::freopen((s + ".in").c_str(), "r", stdin),
	std::freopen((s + ".out").c_str(), "w", stdout);
}

int main() noexcept
{
	freopen("replace");
	std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);


	return 0;
}
