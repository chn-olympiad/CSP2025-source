#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
struct node{
    int l, r, sum;
}tr[2000005], ans[1000005];
bool vis[500005];
bool cmp(node a, node b){return a.sum < b.sum;}
void build(int p, int l, int r){
    tr[p].l = l;
    tr[p].r = r;
    if(l == r){
        tr[p].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    tr[p].sum = tr[p * 2].sum ^ tr[p * 2 + 1].sum;
}
int query(int p, int l, int r){
    if(tr[p].l >= l && tr[p].r <= r)return tr[p].sum;
    int mid = (tr[p].l + tr[p].r) >> 1;
    int ans = 0;
    if(l <= mid)ans ^= query(p * 2, l, r);
    if(r > mid)ans ^= query(p * 2 + 1, l, r);
    return ans;
}
signed main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1, 1, n);
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(query(1, i, j) == k){
                ans[++cnt] = {i, j, j - i + 1};
            }
        }
    }
    int res = 0;
    sort(ans + 1, ans + cnt + 1, cmp);
    for(int i = 1; i <= cnt; i++){
        bool f = 0;
        for(int j = ans[i].l; j <= ans[i].r; j++){
            if(vis[j]){
                f = 1;
                break;
            }
        }
        if(!f){
            res++;
            for(int j = ans[i].l; j <= ans[i].r; j++)vis[j] = 1;
        }
    }
    cout << res;
    return 0;
}
/*
4 2
2 1 0 3
*/