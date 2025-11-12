#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for(int i = 0;i <= s.size()-1;i++)
    {
        if(s[i]>=0&&s[i]<=9)
        {
           if(s[i]<s[i-1])
           {
               int x = s[i];
               s[i] = s[i-1];
               s[i-1] = x;
           }
           else{
               continue;
           }
        }
        else{
            continue;
        }
    }
    for(int i = 0;i <= s.size()-1;i++)
        cout << s[i];
    return 0;
}
