#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=998244353;
bool pas[N];
int fac[N];
string s;
int n,m;
int c[N];
void init(){
    fac[0]=1;
    for(int i=1;i<=n+2;++i) fac[i]=(fac[i-1]*i)%M;
}
namespace TA{
    void main(){
        int ha=0;
        for(int i=1;i<=n;++i){
            if(c[i]==0) continue;
            ++ha;
        }
        if(ha<m){
            puts("0");
            return;
        }
        else{
            printf("%lld\n",fac[n]);
        }
    }
}
namespace BL{
    int p[N];
    int ans=0;
    void che(){
        int use=0;
        int no=0;
        for(int i=1;i<=n;++i){
            if(no>=c[p[i]])
                ++no;
            else{
                if(pas[i]){
                    ++use;
                    continue;
                }
                else    ++no;
            }
        }
        if(use>=m)  ++ans;
    }
    void main(){
        for(int i=1;i<=n;++i)   p[i]=i;
        che();
        while(next_permutation(p+1,p+1+n)){
            che();
        }
        printf("%d\n",ans);
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    cin>>s;
    bool fa=1;
    init();
    for(int i=0;i<n;++i){
        if(s[i]=='1')
            pas[i+1]=1;
        else
            pas[i+1]=0,fa=0;
    }
    for(int i=1;i<=n;++i)   scanf("%lld",&c[i]);
    if(fa)  TA::main();
    else BL::main();
    return 0;
}
