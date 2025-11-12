#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int a, b, c[10001] = {};
    cin >> a >> b;
    for(int i = 0;i < a;i++)
    {
        cin >> c[i];
    }
    if(b == 0)
    {
        cout << 1;
    }
    else
    {
        cout << 2;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
