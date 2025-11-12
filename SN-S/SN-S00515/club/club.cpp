#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll T;
const int N = 1e5 + 10;

struct node{
    int a, b, c;
    int maxx = 0;
}a[N];
bool cmp1(node rhs, node lhs){
    return rhs.a > lhs.a;

}
bool cmp2(node rhs, node lhs){
    return rhs.a * lhs.b > lhs.a * lhs.c;

}

void chick(){
    int n, fa = 1, fb = 1, ans = 0;
    cin >> n;
    int p = n / 2;
    for (int i = 0; i < n; i ++){
        scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
        if (a[i].b != 0 || a[i].c != 0)
            fa = 0;
        else if (a[i].c != 0)
            fb = 0;
        a[i].maxx = max(a[i].a, max(a[i].b, a[i].c));
    }
    if (fa){
        sort(a, a + n, cmp1);
        for (int i = 0; i < p; i ++)
            ans += a[i].a;
        printf("%d\n", ans);
        return;
    }
    if (fb){
        sort(a, a + n, cmp2);
        int a1 = 0, b1 = 0;
        for (int i = 0; i < n; i ++){
            if (a1 < p && a[i].maxx == a[i].a){
                a1 ++, ans += a[i].a;
            }
            else if (a1 >= p && a[i].maxx == a[i].a)
                b1 ++, ans += a[i].b;
            if (b1 < p && a[i].maxx == a[i].b){
                b1 ++, ans += a[i].b;
            }
            else if (b1 >= p && a[i].maxx == a[i].b)
                a1 ++, ans += a[i].a;
        }
        printf("%d\n", ans);
        return;
    }

}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while(T --) chick();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
