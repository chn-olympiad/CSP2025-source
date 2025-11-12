#include <iostream>
#include <string>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int ti=0;
    string s,a;
    cin >> s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[ti]+=s[i];
            ti++;
        }
    }
    for(int i=0;i<a.length()-1;i++)
    {
        for(int j=0;j<a.length()-i;j++)
        {
            if(a[j]-'0'<a[j+1]-'0')
            {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    cout << a;
    return 0;
}
