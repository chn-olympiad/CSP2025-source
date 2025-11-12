#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
    int a[200000];
    int jsq = 1;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0')
        {
            a[jsq] = 0;
            jsq++;
        }
        if(s[i]=='1')
        {
            a[jsq] = 1;
            jsq++;
        }
        if(s[i]=='2')
        {
            a[jsq] = 2;
            jsq++;
        }
        if(s[i]=='3')
        {
            a[jsq] = 3;
            jsq++;
        }
        if(s[i]=='4')
        {
            a[jsq] = 4;
            jsq++;
        }
        if(s[i]=='5')
        {
            a[jsq] = 5;
            jsq++;
        }
        if(s[i]=='6')
        {
            a[jsq] = 6;
            jsq++;
        }
        if(s[i]=='7')
        {
            a[jsq] = 7;
            jsq++;
        }
        if(s[i]=='8')
        {
            a[jsq] = 8;
            jsq++;
        }
        if(s[i]=='9')
        {
            a[jsq] = 9;
            jsq++;
        }
    }
	sort(a+1,a+jsq);

    for(int i=jsq-1;i>0;i--)
    {
        cout<<a[i];
    }
	return 0;
}

