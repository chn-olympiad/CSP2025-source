#include <iostream>
using namespace std;

int N;
int A[100008][3];
int ans = 0;
int x, y, z;
int ma;

int T;

void d(int i,int val) {
    if (i>=N) {
        ans = max(ans, val);
        return;
    }
    if (x<ma) {
        x++;
        d(i + 1, val + A[i][0]);
        x--;
    }
    if (y<ma) {
        y++;
        d(i + 1, val + A[i][1]);
        y--;
    }
    if (z<ma) {
        z++;
        d(i + 1, val + A[i][2]);
        z--;
    }
    return;
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        ans = 0;
        ma = N / 2;
        for (int i = 0; i < N;i++) {
            scanf("%d%d%d", &A[i][0], &A[i][1], &A[i][2]);
            
        }
        d(0,0);
        printf("%d\n", ans);
    }

    return 0;
}

/*
4
4 2 1
3 2 4
5 3 4
3 5 1

*/