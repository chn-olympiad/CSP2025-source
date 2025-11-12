#include <iostream>
#include <algorithm>
#define END cout.flush(); fclose(stdin); fclose(stdout);
using namespace std;

int a[100010], b[100010], c[100010];
pair<int, int> ga[100010], gb[100010], gc[100010];

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i] >> c[i];
            if (max({a[i], b[i], c[i]}) == a[i]) {
                cnt1++;
                ga[cnt1] = {a[i] - max(b[i], c[i]), i};
            }
            else if (max({a[i], b[i], c[i]}) == b[i]) {
                cnt2++;
                gb[cnt2] = {b[i] - max(a[i], c[i]), i};
            }
            else {
                cnt3++;
                gc[cnt3] = {c[i] - max(a[i], b[i]), i};
            }
        }
        if (cnt1 > (n >> 1)) {
            sort(ga + 1, ga + cnt1 + 1, greater<pair<int, int>>());
            for (int i = (n >> 1) + 1; i <= cnt1; i++) {
                if (max(b[ga[i].second], c[ga[i].second]) == b[ga[i].second]) {
                    cnt2++;
                    gb[cnt2] = {b[ga[i].second] - max(a[ga[i].second], c[ga[i].second]), ga[i].second};
                }
                else {
                    cnt3++;
                    gc[cnt3] = {c[ga[i].second] - max(a[ga[i].second], b[ga[i].second]), ga[i].second};
                }
            }
            cnt1 = n >> 1;
        }
        else if (cnt2 > (n >> 1)) {
            sort(gb + 1, gb + cnt2 + 1, greater<pair<int, int>>());
            for (int i = (n >> 1) + 1; i <= cnt2; i++) {
                if (max(a[gb[i].second], c[gb[i].second]) == a[gb[i].second]) {
                    cnt1++;
                    ga[cnt1] = {a[gb[i].second] - max(b[gb[i].second], c[gb[i].second]), gb[i].second};
                }
                else {
                    cnt3++;
                    gc[cnt3] = {c[gb[i].second] - max(a[gb[i].second], b[gb[i].second]), gb[i].second};
                }
            }
            cnt2 = n >> 1;
        }
        else if (cnt3 > (n >> 1)) {
            sort(gc + 1, gc + cnt3 + 1, greater<pair<int, int>>());
            for (int i = (n >> 1) + 1; i <= cnt3; i++) {
                if (max(a[gc[i].second], b[gc[i].second]) == a[gc[i].second]) {
                    cnt1++;
                    ga[cnt1] = {a[gc[i].second] - max(b[gc[i].second], c[gc[i].second]), gc[i].second};
                }
                else {
                    cnt2++;
                    gb[cnt2] = {b[gc[i].second] - max(a[gc[i].second], c[gc[i].second]), gc[i].second};
                }
            }
            cnt3 = n >> 1;
        }
        int ans = 0;
        for (int i = 1; i <= cnt1; i++) {
            ans += a[ga[i].second];
        }
        for (int i = 1; i <= cnt2; i++) {
            ans += b[gb[i].second];
        }
        for (int i = 1; i <= cnt3; i++) {
            ans += c[gc[i].second];
        }
        cout << ans << '\n';
    }
    END;
    return 0;
}
