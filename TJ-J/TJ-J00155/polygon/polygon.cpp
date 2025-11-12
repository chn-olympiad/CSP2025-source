#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a, s[1001] = {}, ans = 0;
    cin >> a;
    for(int i = 0;i < a;i++)
    {
        cin >> s[i];
        if(s[i] + s[i+1]>s[i+2] && a == 3)
        {
            ans++;
        }
    }
    if(ans > 0)
    {
        cout << 1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
