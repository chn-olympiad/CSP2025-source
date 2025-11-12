#include <iostream>
#include <algorithm>
#define loop(idx) for (int i##idx = 0; i##idx <= 1; ++i##idx)
using namespace std;
constexpr int N = 5007;
int n, amx2;
long long ans;
int a[N];
int main()
{
    freopen("polygon.in", "r", stdin); 
    freopen("polygon.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1, greater<int>());
    amx2 = a[1] * 2;
    loop(1) loop(2) loop(3) loop(4) loop(5) loop(6) loop(7) loop(8) loop(9) loop(10)
    {
        long long sum = a[1] * i1 + a[2] * i2 + a[3] * i3 + a[4] * i4 + a[5] * i5 + a[6] * i6 + a[7] * i7 + a[8] * i8 + a[9] * i9 + a[10] * i10;
        if (sum > amx2)
            ans++;
    }
    cout << ans;
    return 0;
}
