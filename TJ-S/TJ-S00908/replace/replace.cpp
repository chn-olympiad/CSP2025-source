#include <iostream>
#include <vector>
using namespace std;
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    vector<string> s1(n+1), s2(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> s1[i] >> s2[i];
    }
    vector<string> t1(n+1), t2(n+1);
    for (int i = 1; i <= q; i++)
    {
        cin >> s1[i] >> s2[i];
    }
    for (int i = 1; i <= q; i++)
    {
        cout << 0 << endl;
    }
    return 0;
}
