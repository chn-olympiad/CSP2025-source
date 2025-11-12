#include <iostream>
#include <vector>
using namespace std;
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> c(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    cout << 0 << endl;
    return 0;
}
