#include <bits/stdc++.h>
using namespace std;
int main() {
  freopen("seat.in", "r", stdin);
  freopen("seat.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  vector<int> score(n * m, 0);
  int R;
  cin >> R;
  score[0] = R;
  for (int i = 1; i < n * m ; i ++) {
    cin >> score[i];
  }
  sort(score.begin(), score.end());
  int seat = lower_bound(score.begin(), score.end(), R) - score.begin();
  seat = n * m - 1 - seat;
  int x, y;
  y = seat / n + 1;
  if (y & 1) {
    x = seat % n + 1;
  } else {
    x = n - seat % n;
  }
  cout << y << ' ' << x << endl;
}