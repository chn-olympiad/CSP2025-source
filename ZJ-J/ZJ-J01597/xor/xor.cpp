#include <iostream>
#include <vector>
using namespace std;
constexpr int N = 500007;
int n, k;
int a[N];
vector<int> rs;
vector<int> ls;
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
        bool f = false;
    int l = 1, r = n, sxor = 0, ans = 0;
    for (int i = 1; ; ++i)
    {
        if (f && (ls.size() <= 1 || l > *(rs.end() - 1)))
            ans++;
        if (i > n)
            break;
        while (i > r && !rs.empty())
            r = *(rs.end() - 1), l = *(ls.end() - 1), rs.pop_back(), ls.pop_back();
        sxor = 0;
        f = false;
        for (int j = i; j <= r; ++j)
        {
            sxor ^= a[j];
            if (sxor == k)
            {
                f = true;
                ls.push_back(l);
                rs.push_back(r);
                l = i;
                r = j;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
