// md I forget how to use Prim
// woc I create Prim
// 16(?) + 32(A) = 48

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

namespace noip {
typedef long long Int;

Int fa[10005], n, m, k;
Int u, v, w;
Int ct[15][10005];

struct Node {
	std::vector< std::pair<Int, Int> > og;
} nd[10005];

struct P {
	Int u, v, w;
};

bool operator> (const P& a, const P& b) {
	return a.w > b.w;
}

void init() {
	for (Int i = 1; i <= n; i++) fa[i] = i;	
}

Int find(Int x) {
	if (fa[x] == x) return x;
	else return fa[x] = noip::find(fa[x]);
}

bool ins(Int x, Int y) {
	if (noip::find(x) == noip::find(y)) return 1;
	else return 0;
}

bool merge(Int x, Int y) {
	x = noip::find(x), y = noip::find(y);
	if (x == y) return 1;
	fa[x] = y;
	return 0;	
}

P mp(Int u, Int v, Int w) {
	P np;
	np.u = u; np.v = v; np.w = w;
	return np;
}

bool cmp(const P& a, const P& b) {
	return a.w < b.w;
}

Int mst() {
	noip::init();

	Int s = 0, la, u, v, w;
	std::priority_queue< P, std::vector<P>, std::greater<P> > q;
			  	  
	for (Int i = 0; i < nd[1].og.size(); i++)
		q.push(noip::mp(1LL, nd[1].og[i].first, nd[1].og[i].second));
		
	while (!q.empty()) {
		la = q.top().u, u = q.top().v, w = q.top().w; q.pop();
		//std::cout << "now " << la << ' ' << u << ' ' << w << std::endl;
		if (noip::merge(la, u)) continue;
		s += w;
		
		//std::cout << "now still " << la << ' ' << u << ' ' << w << std::endl;
		for (Int i = 0; i < nd[u].og.size(); i++) {
			v = nd[u].og[i].first, w = nd[u].og[i].second;
			if (noip::ins(v, u)) continue;
			q.push(noip::mp(u, v, w));
		}
	}
	
	return s;
}

void main() {
	std::freopen("road.in", "r", stdin);
	std::freopen("road.out", "w", stdout);
	
	std::cin >> n >> m >> k;
//	std::cout << (noip::mp(1,2,3) < noip::mp(2,3,4)) << std::endl;
	for (Int i = 1; i <= m; i++) {
		std::cin >> u >> v >> w;
		nd[u].og.push_back(std::make_pair(v, w));
		nd[v].og.push_back(std::make_pair(u, w));
	}
	
	for (Int i = 1; i <= k; i++)
		for (Int j = 1; j <= n; j++)
			std::cin >> ct[i][j]; 
	
	if (k == 0) std::cout << noip::mst() << std::endl;
	else std::cout << 0 << std::endl;
}
} int main() {
	noip::main();
	return 0;
}
