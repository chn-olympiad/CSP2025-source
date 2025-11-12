#include <cstdio>
#include <vector>
#include <algorithm>

const int N = 5e5 + 9;

typedef std::pair<int, int> pii;

int T, n, m;

struct Data {
    std::vector<pii> p;
    void input() {
        for (int i = 0, x; i < 3; i++) {
            scanf("%d", &x);
            p.emplace_back(x, i);
        }
        std::sort(p.begin(), p.end(), [](const pii& x, const pii& y) {
            return x.first > y.first;
        });
    }
} a[N];

std::vector<Data> vec[3];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n), m = n >> 1;
        for (int i = 1; i <= n; i++)
            a[i].input();

        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += a[i].p[0].first;
            vec[a[i].p[0].second].push_back(a[i]);
        }

        for (int i = 0; i < 3; i++) {
            if ((int)vec[i].size() > m) {
                std::sort(vec[i].begin(), vec[i].end(), [](const Data& x, const Data& y) {
                    if (x.p[0].first - x.p[1].first == y.p[0].first - y.p[1].first)
                        return x.p[0].first > y.p[0].first;
                    return x.p[0].first - x.p[1].first < y.p[0].first - y.p[1].first;
                });
                int c = vec[i].size() - m;
                for (int j = 0; j < c; j++) {
                    ans -= vec[i][j].p[0].first;
                    ans += vec[i][j].p[1].first;
                }
            }
        }

        printf("%lld\n", ans);

        for (int i = 1; i <= n; i++)
            a[i].p.clear();
        for (int i = 0; i < 3; i++)
            vec[i].clear();
    }

	fclose(stdin);
	fclose(stdout);
	
    return 0;
}