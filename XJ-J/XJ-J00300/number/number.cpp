#include <bits/stdc++.h>
using namespace std;
string s;
char n[1005];
int a = 1;
int main()
{
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    cin >> s;
    for(int i = 1;i <= s.len();i++)
    {
        if(s[i] <= '9' and s[i] >= '1')
        {
            n[a] = s[i];
            a++;
        }
    }
    cout << s;
}
