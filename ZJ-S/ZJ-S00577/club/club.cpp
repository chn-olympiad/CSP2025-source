#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node{
    int x, y, z;
    int id = 0;
}a[100005];

signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        int n;scanf("%lld", &n);
        int s1 = 0, s2 = 0, s3 = 0;
        int c1 = 0, c2 = 0, c3 = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%lld%lld%lld", &a[i].x, &a[i].y, &a[i].z);
            if (a[i].x >= a[i].y && a[i].x >= a[i].z) {
                s1 += a[i].x;c1++;
                a[i].id = 1;
            }else if (a[i].y >= a[i].x && a[i].y >= a[i].z) {
                s2 += a[i].y;c2++;
                a[i].id = 2;
            }else {
                s3 += a[i].z;c3++;
                a[i].id = 3;
            }
        }
        if (c1 <= n / 2 && c2 <= n / 2 && c3 <= n / 2) {
            printf("%lld\n", s1 + s2 + s3);
            continue;
        }
        if (c1 > n / 2) {
            int t = c1 - n / 2;
            priority_queue <int> q;
            for (int i = 1; i <= n; i++) {
                if (a[i].id == 1) {
                    q.push(max(a[i].y, a[i].z) - a[i].x);
                }
            }
            for (int i = 1; i <= t; i++) {
                s1 += q.top();q.pop();
            }
            printf("%lld\n", s1 + s2 + s3);
        }else if (c2 > n / 2) {
            int t = c2 - n / 2;
            priority_queue <int> q;
            for (int i = 1; i <= n; i++) {
                if (a[i].id == 2) {
                    //cout << i << ":" << a[i].y - max(a[i].x, a[i].z) << endl;
                    q.push(max(a[i].x, a[i].z) - a[i].y);
                }
            }
            for (int i = 1; i <= t; i++) {
                s2 += q.top();q.pop();
            }
            printf("%lld\n", s1 + s2 + s3);
        }else {
            int t = c3 - n / 2;
            priority_queue <int> q;
            for (int i = 1; i <= n; i++) {
                if (a[i].id == 3) {
                    q.push(max(a[i].x, a[i].y) - a[i].z);
                }
            }
            for (int i = 1; i <= t; i++) {
                s3 += q.top();q.pop();
            }
            printf("%lld\n", s1 + s2 + s3);

        }
    }
    return 0;
}