#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5 + 3;
ll ans, a[N], n, vis[N];
void dfs1(int n, int t){
    if (t == n){
        ans ++;
        return;
    }
    for (int i = 0; i < n; i ++){
        if (vis[i])
            continue;
        vis[i] = 1;
        t ++;
        dfs1(n, t);
        t --;
        vis[i] = 0;
    }


}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d",&n);
    for (int i = 0; i < n; i ++)
        scanf("%d",&a[i]);
    if (n == 3){
        if (2 * max(a[0], max(a[1], a[2])) < a[0] + a[1] + a[2])
            cout << 1;
        else cout << 0;
        return 0;
    }
    printf("0");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
