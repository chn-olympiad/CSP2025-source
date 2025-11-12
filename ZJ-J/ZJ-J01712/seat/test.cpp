#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn = 1e5 + 10;
char name[maxn] , cmd[maxn] , add[maxn];
signed main()
{
    printf("source name:");
    scanf("%s",name);
    sprintf(add , "-s -w -B");
    printf("Compiling...\n");
    sprintf(cmd , "g++ %s.cpp -o %s -O2 -std=c++14 -static",name,name);
    system(cmd);
    int n;
    printf("number of tests:");
    scanf("%lld",&n);
    for(int i = 1; i <= n; ++i)
    {
        printf("Running on Test %lld...\n",i);
        sprintf(cmd , "cp %s%lld.in %s.in",name,i,name);
        system(cmd);
        sprintf(cmd , "time -p ./%s",name);
        system(cmd);
        sprintf(cmd , "diff %s%lld.ans %s.out %s",name,i,name,add);
        system(cmd);
    }
    printf("Finish!");
    return 0;
}
