#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
//CFF please let me AC!
int n, typ, id;
ll sum, cnt[5];
struct node{
    int a[5];
    ll d, maxn = -1, minx = 1e9;
}s[N];
ll b[N];

void find(){
    for (int i = 1; i <= n; i ++){
        if (s[i].maxn == s[i].a[typ]){
            ++ id, b[id] = s[i].a[typ] - (s[i].d - s[i].maxn - s[i].minx);
        }
    }
    sort(b + 1, b + 1 + id);
    int j = 1;
    while (cnt[typ] > n / 2){
        cnt[typ] --;
        sum -= b[j];
        ++ j;
    }
    cout << sum << '\n';
}
// c______
void solve(){
    id = 0, typ = 0, sum = 0, cnt[1] = 0, cnt[2] = 0, cnt[3] = 0;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        s[i].d = 0, s[i].minx = 1e9, s[i].maxn = -1;
        for (int j = 1; j <= 3; j ++){
            cin >> s[i].a[j];
            s[i].d += s[i].a[j];
        }
        s[i].maxn = max(s[i].a[1], max(s[i].a[2],s[i].a[3]));
        s[i].minx = min(s[i].a[1], min(s[i].a[2],s[i].a[3]));
    }
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= 3; j ++){
            if (s[i].a[j] == s[i].maxn){
                ++ cnt[j], sum += s[i].maxn;
                break;
            }
        }
    }
    if (cnt[1] <= n / 2 && cnt[2] <= n / 2 && cnt[3] <= n / 2){
        cout << sum << '\n';
        return;
    }//可直接出
    else{
        for (int i = 1; i <= 3; i ++){
            if (cnt[i] > n / 2){
                typ = i;
                find();
                return;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    clock_t st = clock();
    int T;
    cin >> T;
    while (T --)
        solve();
    clock_t ed = clock();
    // printf("The time is %.3lf s", (double)(ed - st) / CLOCKS_PER_SEC);
}