#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
string s;
int a[1000005], c;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            c++;
            a[c] = s[i]-'0';
        }
    }
    sort(a+1, a+c+1);
    for (int i = c; i >= 1; i--)
    {
        cout << a[i];
    }
    fclose(stdin);
	fclose(stdout);
    return 0;
}
