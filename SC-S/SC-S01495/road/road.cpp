#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
#define eprintf(...) ((void)(0))
using namespace std;

typedef long long LL;
constexpr int MAXN = 1e4 + 5;
int n, m, k, c[MAXN];
LL ans = 1e18;
struct AllanR{
	int x, y, z;
	bool tp;
};
vector<AllanR> e, re;

int ufa[MAXN];
inline void uInit() { iota(ufa + 1, ufa + (n + k) + 1, 1); }
inline int uget(int x) { return x == ufa[x] ? x : ufa[x] = uget(ufa[x]); }

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		int x, y, z; cin >> x >> y >> z;
		e.push_back({ x, y, z, false });
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for (int y = 1; y <= n; y++)
		{
			int z; cin >> z;
			e.push_back({ n + i, y, z, true });
		}
	}
	
	sort(e.begin(), e.end(), [](const AllanR &x, const AllanR &y){
		return x.z < y.z;
	});
	uInit();
	for (const AllanR &t : e)
	{
		eprintf("(%d, %d, %d)(%d)", t.x, t.y, t.z, t.tp);
		int x = uget(t.x), y = uget(t.y);
		if (x != y)
		{
			re.push_back(t);
			eprintf(" ok");
			if (!t.tp) ufa[y] = x;
		}
		eprintf("\n");
	}
	
	eprintf("----------\n");
	for (int s = 0; s < (1 << k); s++)
	{
		uInit();
		LL sum = 0;
		for (int i = 0; i < k; i++)
			if ((s >> i) & 1) sum += c[i + 1];
		for (const AllanR &t : re)
		{
			if (t.tp && !((s >> (t.x - n - 1)) & 1)) continue;
			eprintf("(%d, %d, %d)(%d)", t.x, t.y, t.z, t.tp);
			int x = uget(t.x), y = uget(t.y);
			if (x != y)
			{
				eprintf(" selected");
				ufa[y] = x;
				sum += t.z;
			}
			eprintf("\n");
		}
		eprintf("%d: %lld\n", s, sum);
		ans = min(ans, sum);
	}
	cout << ans << '\n';
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/