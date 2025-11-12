#include <cstdio>
#include <iostream>
const int maxn=1100;
const long long mod=998244353;
int n,m;
char s[maxn];
int c[maxn];
int flagA=1;
long long ans=0;

int p[maxn],h[maxn];
void dfs(int x){
    if(x>n){
        int del=0,sum=0;
        for(int i=1;i<=n;i++){
            if(del>=c[p[i]])
                del++;
            else{
                if(s[i-1]=='0')
                    del++;
                else
                    sum++;
            }
        }
        if(sum>=m)
            ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(h[i]==0){
            h[i]=1;
            p[x]=i;
            dfs(x+1);
            h[i]=0;
        }
    }
    return;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    std::cin>>n>>m;
    std::cin>>s;
    for(int i=1;i<=n;i++){
        std::cin>>c[i];
        if(s[i-1]=='0')
            flagA=0;
    }
    if(n<=10){
        dfs(1);
        printf("%lld",ans);
    } else if(m==n){
        ans=1;
        for(int i=1;i<=n;i++){
            if(s[i-1]=='0')
                ans=0;
            else if(c[i]<=0)
                ans=0;
            ans=(ans*i)%mod;
        }
        printf("%lld",ans);
    } else {
        dfs(1);
        printf("%lld",ans);
    }
    // if(n<=10){
    //     dfs(1);
    //     printf("%lld",ans);
    // }
    // else if(m==1){

    // } else if(m==n){
    //     ans=1;
    //     for(int i=1;i<=n;i++){
    //         if(s[i-1]=='0')
    //             ans=0;
    //         else if(c[i]<=0)
    //             ans=0;
    //         ans=(ans*i)%mod;
    //     }
    //     printf("%lld",ans);
    // } else if(flagA==1){
    //     ans=1;
    //     for(int i=1;i<=n;i++)
    //         ans=(ans*i)%mod;
    //     printf("%lld",ans);
    // } else {
    //     dfs(1);
    //     printf("%lld",ans);
    // }
    return 0;
}