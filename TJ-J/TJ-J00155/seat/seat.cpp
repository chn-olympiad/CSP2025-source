#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int c, r, s[20] = {}, k = 0, cnt = 0, i;
    cin >> c >> r;
    for(int i = 0;i < r;i++)
    {
        cin >> s[i];
    }
    if(c == 1 && r == 1)
    {
        cout << "1 1";
        return 0;
    }
    else
    {
        cnt = s[0];
        for(int i = 1;i < r;i++)
        {
            if(s[i] > cnt)
            {
                k++;
            }
        }
        cout << "1 " << k;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
