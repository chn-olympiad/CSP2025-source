#include <bits/stdc++.h>
using namespace std;
int a[5050],b[5050];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    if(s.size()==1)
    {
        cout<<s;
        return 0;
    }
    sort(b,b+s.size());
    for(int i=s.size();i>=0;i--)
    {
        cout<<s[i];
    }
    return 0;
}
