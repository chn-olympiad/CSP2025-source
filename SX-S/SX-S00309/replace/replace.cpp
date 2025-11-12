#include<bits/stdc++.h>
#define ll long long
#define ls u<<1
#define rs u<<1|1
#define PII piar<int,int>
#define fi first 
#define se second 
#define _128 __int128
using namespace std;
inline int inint()
{
    int x = 0, f = 1;
    char c = getchar();
    while((c < '0') || (c > '9'))
    {
        if(c == '-') f = -1;
        c = getchar();
    }
    while((c >= '0') && (c <= '9'))
    {
        x = x*10 + (c^'0');
        c = getchar();
    }
    return f*x;
}
inline ll inll()
{
    ll x = 0, f = 1;
    char c = getchar();
    while((c < '0') || (c > '9'))
    {
        if(c == '-') f = -1;
        c = getchar();
    }
    while((c >= '0') && (c <= '9'))
    {
        x = x*10 + (c^'0');
        c = getchar();
    }
    return f*x;
}
inline _128 read()
{
    __int128 x = 0, f = 1;
    char c = getchar();
    while((c < '0') || (c > '9'))
    {
        if(c == '-') f = -1;
        c = getchar();
    }
    while((c >= '0') && (c <= '9'))
    {
        x = x*10 + (c^'0');
        c = getchar();
    }
    return f*x;
}
void print(__int128 x)
{
    if(x < 0) 
    {
        putchar('-');
        x = -x;
    }
    if(x > 9) print(x/10);
    putchar(x%10+'0');
}
int n, q;
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    n = inint(), q = inint();
    while(q--)
    {
        printf("0\n");
    }
    return 0;
}