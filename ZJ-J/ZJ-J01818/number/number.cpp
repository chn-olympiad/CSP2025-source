#include <bits/stdc++.h>

using namespace std;

string s;
int b[11];
bool o=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            ++b[s[i]-'0'];
            if(s[i]!='0')
            {
                o=1;
            }
        }
    }
    if(o==0)
    {
        printf("0\n");
    }
    else
    {
        for(int i=9;i>=0;--i)
        {
            for(int j=1;j<=b[i];++j)
            {
                printf("%d",i);
            }
        }
    }

    return 0;
}

