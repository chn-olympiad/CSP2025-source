#include <bits/stdc++.h>
using namespace std;
string s;
bool f = true;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin >> s;
    for(int i = 0;i < s.length();i++)
    {
        if(s[i] == '9')
        {
            cout << 9;
            f = false;
        }
    }
    for(int i = 0;i < s.length();i++)
    {
        if(s[i] == '8')
        {
            cout << 8;
            f = false;
        }
    }
    for(int i = 0;i < s.length();i++)
    {
        if(s[i] == '7')
        {
            cout << 7;
            f = false;
        }
    }
    for(int i = 0;i < s.length();i++)
    {
        if(s[i] == '6')
        {
            cout << 6;
            f = false;
        }
    }
    for(int i = 0;i < s.length();i++)
    {
        if(s[i] == '5')
        {
            cout << 5;
            f = false;
        }
    }
    for(int i = 0;i < s.length();i++)
    {
        if(s[i] == '4')
        {
            cout << 4;
            f = false;
        }
    }for(int i = 0;i < s.length();i++)
    {
        if(s[i] == '3')
        {
            cout << 3;
            f = false;
        }
    }
    for(int i = 0;i < s.length();i++)
    {
        if(s[i] == '2')
        {
            cout << 2;
            f = false;
        }
    }
    for(int i = 0;i < s.length();i++)
    {
        if(s[i] == '1')
        {
            cout << 1;
            f = false;
        }
    }
    if(f == true)
    {
        cout << 0;
    }
    else
    {
        for(int i = 0;i < s.length();i++)
        {
            if(s[i] == '0')
            {
                cout << 0;
                f = false;
            }
        }
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
