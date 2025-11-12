#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l),qwp=(r);i<=qwp;i++)
#define per(i,r,l) for(int i=(r),qwp=(l);i>=qwp;i--)
#define pb push_back
#define clr clear
using namespace std;
namespace ax_by_c{
constexpr int N=1e5+5;
constexpr int M=4;
int frint(){int n=0;char c=getchar();while(c<'0'||'9'<c)c=getchar();while('0'<=c&&c<='9')n=n*10+c-48,c=getchar();return n;}
void wrint(int x){if(x>9)wrint(x/10);putchar(x%10+48);}
int n,a[N][M],sum[M],cnt[M];
vector<int>ws[M];
void slv(){
    rep(i,1,3)sum[i]=cnt[i]=0,ws[i].clr();
    n=frint();
    rep(i,1,n){
        rep(j,1,3)a[i][j]=frint();
        int p=1;rep(j,2,3)if(a[i][j]>a[i][p])p=j;
        sum[p]+=a[i][p],cnt[p]++,ws[p].pb(a[i][p]-max(a[i][(p+1)%3+1],a[i][p%3+1]));
    }
    int ans=0;
    rep(i,1,3){
        ans+=sum[i];
        if(cnt[i]>n/2){
            sort(ws[i].begin(),ws[i].end());
            rep(j,1,cnt[i]-n/2)ans-=ws[i][j-1];
        }
    }
    wrint(ans),putchar('\n');
}
void main(){
    int T;T=frint();
    while(T--)slv();
}
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ax_by_c::main();
    return 0;
}
/*
ulimit -s 524288
g++ -O2 -std=c++14 -static club.cpp -o club.exe
g++ -O2 -std=c++14 -static -Wall -Wextra club.cpp -o club.exe
g++ -O2 -std=c++14 -Wall -Wextra -fsanitize=address,leak,undefined club.cpp -o club.exe
./club.exe
*/