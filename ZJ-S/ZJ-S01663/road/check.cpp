#include<bits/stdc++.h>
#define cint const int
#define uint unsigned int
#define cuint const unsigned int
#define ll long long
#define cll const long long
#define ull const unsigned long long
#define cull const unsigned long long
using namespace std;
ll read()
{
    ll x=0;
    bool zf=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')zf=1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch-'0');
        ch=getchar();
    }
    return x;
}
void print(cll x)
{
    if(x<0)
    {
        putchar('-');
        print(-x);
        return;
    }
    if(x<10)
    {
        putchar(x+'0');
        return;
    }
    print(x/10);
    putchar(x%10+'0');
}
void princh(cll x,const char ch)
{
    print(x);
    putchar(ch);
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    system("g++ road.cpp -o my -O2 -std=c++14");
    system("g++ brute.cpp -o brute -O2");
    system("g++ gen.cpp -o gen -O2");
    int tc=0;
    again:
    printf("#%d:",++tc);
    system("./gen");
    system("./brute");
    system("./my");
    if(system("diff -Z brute.out road.out"))
    {
        puts("WA");
        return 0;
    }
    puts("AC");
    goto again;
}