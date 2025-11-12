#include<bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;

int n, a[N][3];

signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        priority_queue<int> q[3];
        cin >> n;
        int rsl=0;
        for(int i=1; i<=n; ++i) {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            int x=max_element(a[i], a[i]+3)-a[i];
            rsl+=a[i][x];
            if(x==0)
                q[0].push(max(a[i][1], a[i][2])-a[i][0]);
            else if(x==1) {
                q[1].push(max(a[i][0], a[i][2])-a[i][1]);
            } else {
                q[2].push(max(a[i][0], a[i][1])-a[i][2]);
            }
        }
        for(int i=0; i<3; ++i) {
            while(q[i].size()>n/2) {
                rsl+=q[i].top();
                q[i].pop();
            }
        }
        cout << rsl << '\n';
    }
    return 0;
}