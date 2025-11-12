#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int s = 0, f = 1;
    signed c = getchar();
    for(; !isdigit(c); c = getchar()) if(c == '-') f = -f;
    for(; isdigit(c); c = getchar()) s = (s * 10) + (c ^ 48);
    return s * f;
}
void write(int x){
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) write(x / 10);
    putchar('0' + x % 10);
    return;
}
const int N = 501 + 10,
        mod = 998244353;
int n, m, a[N], c[N];
char s[N];
bool check(){
    int cnt = 0, fail_cnt = 0;
    for(int i = 1; i <= n; ++ i){
        if(fail_cnt >= c[a[i]]) ++ fail_cnt;
        else{
            if(s[i] == '1'){
                ++ cnt;
            }else ++ fail_cnt;
        }
    }
    return cnt >= m;
}
signed main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    n = read(), m = read();
    scanf("%s", s + 1);
    for(int i = 1; i <= n; ++ i) c[i] = read();
    iota(a + 1, a + n + 1, 1);
    int res = 0;
    do{
        if(check()) ++ res;
    }while(next_permutation(a + 1, a + n + 1));
    write(res % mod);
    return 0;
}