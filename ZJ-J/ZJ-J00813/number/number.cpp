#include <bits/stdc++.h>
using namespace std;

char s[2000006];
int cnt[100];

int main()
{
    freopen("number.in",  "r", stdin);
    freopen("number.out", "w", stdout);
    scanf("%s", s);
    size_t len = strlen(s);
    for (size_t i = 0; i < len; i++)
    {
        if ('0' <= s[i] && s[i] <= '9')
        {
            cnt[s[i]]++;
        }
    }
    for (int i = '9'; i >= '0'; i--)
    {
        for (int j = 0; j < cnt[i]; j++)
        {
            putchar(i);
        }
    }
    return 0;
}
