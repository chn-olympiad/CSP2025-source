#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
int n, a[500005], k, c, _ = 0;
map <int, int> first;
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        _ ^= a[i];
        if (!first.count(_))
        {
            first[_] = i;
        }
        if (_ == k || (first.count(_^k) && first[_^k] != i))
        {
            c++;
            _ = 0;
            first.clear();
        }
    }
    cout << c;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
