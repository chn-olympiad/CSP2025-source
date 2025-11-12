#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define rep(k,l,r) for(int k=l;k<=r;++k)
#define per(k,r,l) for(int k=r;k>=l;--k)
#define ll long long 
#define ull unsigned long long
#define PII pair<int,int>
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define ld double
#define cl(f,x) memset(f,x,sizeof(f))
using namespace std;
void file_IO() {
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
}
bool M1;
const int INF=0x3f3f3f3f;
const ll INFLL=0x3f3f3f3f3f3f3f3f;
const ld eps=1e-9;
void solve() {
    system("fc replace.out replace.ans");
}
bool M2;
// g++ checker.cpp -std=c++14 -Wall -O2 -o checker
signed main() {
    // file_IO();
    int testcase=1;
    // scanf("%d",&testcase);
    while(testcase--)
        solve();
    debug("used time = %dms\n",(signed)(1000*clock()/CLOCKS_PER_SEC));
    debug("used memory = %dMB\n",(signed)((&M2-&M1)/1024/1024));
    return 0;
}