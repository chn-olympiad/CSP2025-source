#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct _T{
    int v;
    int w;
    bool operator < (_T b) const {
        return w > b.w;
    }
};
int N,M,K;
vector<_T> MAP[10008];
int A[18][10008];
int C[18];
bool vism[10008];
bool visa[18];

priority_queue<_T> q;

void b() {
    q.push({1, 0});

}

int main() {
    //freopen("road.in", "r", stdin);
    //freopen("road.out", "w", stdout);
    cin >> N >> M >> K;
    int u, v, w;
    for (int i = 1; i <= M;i++) {
        cin >> u >> v >> w;
        MAP[u].push_back({v, w});
        MAP[v].push_back({u, w});
    }
    for (int i = 1; i <= K;i++) {
        cin >> C[i];
        for (int j = 1; j <= N;j++) {
            cin >> A[i][j];
        }
    }

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