#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >>s;
    for (int i=0; i<=s.length(); i++)
    {
        if (s[i]<s[i+1])
        {
            int t=s[i];
            s[i]=s[i+1];
            s[i+1]=t;
        }
        if (s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0')
        {
            cout <<s[i];
        }
        else
        {
            continue;
        }
    }
    return 0;
}
