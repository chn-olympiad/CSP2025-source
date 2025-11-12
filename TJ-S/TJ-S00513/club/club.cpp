#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int t, n;
long long ans;
int cnt[4] = {0, 0, 0, 0}, lst[4] = {0, 0, 0, 0};
struct  mem {
    int d[4], id;
    int mx, md, mn;
} a[N];
bool cmp(mem x, mem y) {
    if(x.d[x.mx] != y.d[y.mx]) return x.d[x.mx] > y.d[y.mx];
    else if(x.d[y.md] != y.d[y.md])return x.d[y.md] > y.d[y.md];
    else return x.d[y.mn] > y.d[y.mn];
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
    scanf("%d", &t);
    for(int j = 1; j <= t; j++) {
        for(int i = 0; i <= n + 10; i++) {
            a[i].id = 0;
            a[i].d[1] = a[i].d[2] = a[i].d[3] = 0;
            a[i].mx = a[i].md = a[i].mn = 0;
        }
        ans = 0, n = 0;
        cnt[0] = cnt[1] = cnt[2] = cnt[3] = 0;
        lst[0] = lst[1] = lst[2] = lst[3] = 0;

        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d%d%d", &a[i].d[1], &a[i].d[2], &a[i].d[3]);
            if(max(max(a[i].d[1], a[i].d[2]), a[i].d[3]) == a[i].d[1]) a[i].mx = 1;
            else if(max(max(a[i].d[1], a[i].d[2]), a[i].d[3]) == a[i].d[2]) a[i].mx = 2;
            else if(max(max(a[i].d[1], a[i].d[2]), a[i].d[3]) == a[i].d[3]) a[i].mx = 3;
            if(min(min(a[i].d[1], a[i].d[2]), a[i].d[3]) == a[i].d[1]) a[i].mn = 1;
            else if(min(min(a[i].d[1], a[i].d[2]), a[i].d[3]) == a[i].d[2]) a[i].mn = 2;
            else if(min(min(a[i].d[1], a[i].d[2]), a[i].d[3]) == a[i].d[3]) a[i].mn = 3;
            a[i].md = 6 - a[i].mx - a[i].mn;
        }
        sort(a + 1, a + n + 1, cmp);
        for(int i = 1; i <= n; i++) {
            a[i].id = i;
            if(cnt[a[i].mx] >= n / 2 && a[lst[a[i].mx]].d[a[lst[a[i].mx]].md] + a[i].d[a[i].mx] >=
                                        a[lst[a[i].mx]].d[a[lst[a[i].mx]].mx] + a[i].d[a[i].md]) {
                ans -= a[lst[a[i].mx]].d[a[lst[a[i].mx]].mx];
                ans += a[lst[a[i].mx]].d[a[lst[a[i].mx]].md] + a[i].d[a[i].mx];
                cnt[a[lst[a[i].mx]].md]++;
                lst[a[lst[a[i].mx]].md] = max(lst[a[lst[a[i].mx]].md], a[lst[a[i].mx]].id);
                lst[a[i].mx] = i;
            }
            else {
                if(cnt[a[i].mx] < n / 2) {
                    ans += a[i].d[a[i].mx];
                    cnt[a[i].mx]++;
                    lst[a[i].mx] = i;
                }
                else if(cnt[a[i].mx] == n / 2) {
                    ans += a[i].d[a[i].md];
                    cnt[a[i].md]++;
                    lst[a[i].md] = i;
                    //cout << i <<endl;
                    //cout <<"asdfghjkl" <<endl;
                }
            }
            //cout << cnt[1] <<" " << cnt[2] << " " << cnt[3] << endl;
            //cout << a[i].d[1] <<" "<< a[i].d[2]  << "  " << a[i].d[3] << endl;
        }
        cout << ans << endl;
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
