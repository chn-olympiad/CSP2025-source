#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size;i++)
    {
        char s[i];
        if((s[i]<'0')||(s[i]>'9'))
        {
            s[s.size+1]=s[i];
        }
    }
    sort(s[0],s.size-1);
    for(int i=s.size-1;i>=0;i--)
    {
         cout<<s[i];
    }
    return 0;
}
