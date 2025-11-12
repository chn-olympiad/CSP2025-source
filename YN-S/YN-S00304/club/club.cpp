#include <iostream>
#include <string>
#include <algorithm>
using std::cin; using std::cout;

void freopen(std::string const && s) noexcept {std::freopen((s + ".in").c_str(), "r", stdin), std::freopen((s + ".out").c_str(), "w", stdout);}

struct Node {
	unsigned x, y, z;
	Node() noexcept {cin >> x >> y >> z;}
};

int main(int avgc, char ** avgv) noexcept
{
	freopen("club");
	std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	unsigned t; cin >> t;
	
	while (t--)
	{
		unsigned n; cin >> n;
		
		Node * a{new Node[n] {}};
		
		unsigned result{0};
		
		std::sort(a, a + n, [](Node const & a, Node const & b) {return a.x > b.x;});
		for (unsigned i{0}; i < (n >> 1); ++i) result += a[i].x;
		
		cout << result << '\n';
		
		delete[] a;
	}
	
	
	return 0;
}