#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    long long len=s.size();
    long long x=0,s1[len+1];
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9')
        {
            s1[x]=s[i]-'0';
            x++;
        }
    }
    sort(s1,s1+x);
    for(int i=x-1;i>=0;i--)
    {
        cout<<s1[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
