#include <bits/stdc++.h>
using namespace std;

struct person {
  array<uint64_t, 3> cost;

  array<size_t, 3> get_rank() const {
    array<size_t, 3> rank {{0, 1, 2}};
    sort(rank.begin(), rank.end(), [&](size_t lhs, size_t rhs) -> bool {
      return cost[lhs] > cost[rhs];
    });
    return rank;
  }

  uint64_t get_cost() const {
    auto rank = get_rank();
    return cost[rank[0]] - cost[rank[1]];
  }
};

static void solve() {
  size_t n;
  cin >> n;

  vector<person> ps(n);
  for (size_t i = 0; i < n; ++i)
    cin >> ps[i].cost[0] >> ps[i].cost[1] >> ps[i].cost[2];

  sort(ps.begin(), ps.end(), [](const person& lhs, const person& rhs) -> bool {
    return lhs.get_cost() < rhs.get_cost();
  });

  size_t limit = n / 2;
  uint64_t score = 0;
  array<queue<size_t>, 3> group;
  for (size_t i = 0; i < n; ++i) {
    auto rank = ps[i].get_rank();
    if (group[rank[0]].size() == limit) {
      size_t y = group[rank[0]].front();
      group[rank[0]].pop();
      auto rank_y = ps[y].get_rank();
      score -= ps[y].cost[rank_y[0]];
      score += ps[y].cost[rank_y[1]];
      group[rank_y[1]].push(y);
    }
    score += ps[i].cost[rank[0]];
    group[rank[0]].push(i);
  }
  cout << score << '\n';
}

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.badbit | cin.failbit);
  size_t t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}

