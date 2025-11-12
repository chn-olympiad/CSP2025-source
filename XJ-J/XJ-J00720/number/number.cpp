//01
#include <bits/stdc++.h>
using namespace std;
int num;
string s;
int a[114514];
string number;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for (int i=0;i<s.length();i++)
    {
        if (s[i]>='0'&&s[i]<='9') num++;
        if (num==1) cout<<s[i];
        else if (num==0) break;
        else
        {
            //maopaopaixu
            for (int i=s.length();i>=0;i--)
            {
                a[s[i]]++;
                if (a[s[i]]>a[s[i-1]])
                {
                    for (int i=0;i<=1e6;i++) number[i]+=s[i];
                }
            }
        }

    }
    cout<<number;
    return 0;
}
