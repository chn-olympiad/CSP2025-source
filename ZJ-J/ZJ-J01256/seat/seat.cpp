#include <iostream>
using namespace std;

int N,M;
int A;
int cnt;

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin >> N >> M;
    cin >> A;
    int t;
    for (int i = 1; i <= N * M - 1;i++) {
        cin >> t;
        if (t>A)
            cnt++;
    }
    int x=(cnt)/N+1, y;
    if (x%2==1) {
        y = (cnt % N) + 1;
    }else{
        y = N - (cnt % N);
    }
    cout << x << " " << y;

    return 0;
}

/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92
*/