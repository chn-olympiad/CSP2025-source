#define file_io(id) do { \
    freopen(id".in", "r", stdin); freopen(id".out", "w", stdout); } while(false)
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, target;
int scores[200];

int main() {
    file_io("seat");
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
        cin >> scores[i];
    target = scores[1];
    sort(scores + 1, scores + n * m + 1, greater<int>());

    int rank;
    for (int i = 1; i <= n * m; i++) {
        if (scores[i] == target) {
            rank = i; break;
        }
    }

    int col = (rank - 1) / n + 1;
    int row = (col % 2 == 0) ? (n - (rank - 1) % n) : ((rank - 1) % n + 1);
    cout << col << ' ' << row << endl;

	return 0;
}

