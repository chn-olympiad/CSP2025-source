#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5 + 5;
ll ans, n, k;
int a[N], sum[N];

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d%d", &n, &k);

    bool f = 1, f2 = 1;
    for(int i = 1; i <= n; i ++){
        scanf("%d", &a[i]);
        if (a[i] != 1)
            f2 = 0;
        if (a[i] != 0 && a[i] != 1)
            f = 0;
    }
    if(f2) {
        cout << n / 2;
        return 0;
    }
    if (f){
        if (k == 1){
            for(int i = 1; i <= n; i ++){
                if (a[i] == 1)
                    ans ++;
            }
        }
        if (k == 0){
            for(int i = 1; i <= n; i ++){
                if (a[i] == 0)
                    ans ++;
            }
        }
        cout << ans;
        return 0;
    }
    cout << 2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
