#include<bits/stdc++.h>
using namespace std;
#define ll long long

int t, n, a[100005][3], o[100005];
vector<int>t1, t2, t3;

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out","w", stdout);
    cin >> t;
    for(int ii = 1; ii <= t; ii++) {
        scanf("%d", &n);
        t1.clear(), t2.clear(), t3.clear();
        int ans = 0;
        int u = n / 2;
        for(int i = 1; i <= n; i++) {
            scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
            int mx = max(max(a[i][0], a[i][1]), a[i][2]);
            if(a[i][0] == mx)t1.push_back(i);
            else if(a[i][1] == mx)t2.push_back(i);
            else t3.push_back(i);
            ans += mx;
        }
        if(t2.size() > t1.size()) {
            swap(t1, t2);
            for(int i = 1; i <= n; i++)swap(a[i][0], a[i][1]);
        }
        if(t3.size() > t1.size()) {
            swap(t1, t3);
            for(int i = 1; i <= n; i++)swap(a[i][0], a[i][2]);
        }
        if(t1.size() > u) {
            for(int i = 0; i < t1.size(); i++)o[i] = max(a[t1[i]][1], a[t1[i]][2]) - a[t1[i]][0];
            sort(o, o + t1.size());
            for(int i = u; i < t1.size(); i++)ans += o[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}

