#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
int b;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    cin >> s;
    for(int i = 0; i < 1000000; i++)
    {
        if(s[i] == '0')
        {
            break;
        }
        if(s[i] >= 'a' && s[i] <='z')
        {
            continue;
        }
        a[b] = s[i];
        b++;
    }
    sort(a, a + b, cmp);
    for(int i = 0; i <= b; i++)
    {
        if(a[i] == 0)
        {
            break;
        }
        cout << a[i];
    }
    return 0;
}
