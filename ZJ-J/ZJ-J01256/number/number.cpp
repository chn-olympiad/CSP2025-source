#include <iostream>
using namespace std;

char C;
int cnt[10];

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    while (cin >> C) {
        if ('0'<=C&&C<='9') {
            cnt[C - '0']++;
        }
    }
    for (int i = 9;i>=0;i--) {
        while(cnt[i]) {
            cout << i;
            cnt[i]--;
        }
    }

    return 0;
}