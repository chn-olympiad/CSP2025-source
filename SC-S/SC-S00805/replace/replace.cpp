#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
pair<string, string> dict[N];
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> dict[i].first >> dict[i].second;
    while (q--) {
        string from, to;
        cin >> from >> to;
        int lena = from.length(), lenb = to.length();
        if (lena != lenb) {
            puts("0");
            continue;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (dict[i].first == from)
                cnt += dict[i].second == to;
            else {
                int pos = from.find(dict[i].first);
                if (pos != -1) {
                    string processed = from;
                    for (int k = 0; k < dict[k].second.length(); k++)
                        processed[pos + k] = dict[i].second[k];
                    cnt += processed == to;
                }
            }
        printf("%d\n", cnt);
    }
    return 0;
}