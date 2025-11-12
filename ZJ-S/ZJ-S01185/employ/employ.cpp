#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll read(){
    ll w=1,c,ret;
    while((c=getchar())<'0'||c>'9') w=(c=='-'?-1:1);
    ret=c-48;
    while((c=getchar())>='0'&&c<='9') ret=ret*10+c-48;
    return w*ret;
}

int const maxn=505;
int const mod=998244353;
int n,m;

char str[maxn];

int p[maxn];
int c[maxn];

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.ans","w",stdout);
    n=read(),m=read();
    scanf("%s",str+1);
    for(int i=1;i<=n;i++) c[i]=read();
    for(int i=1;i<=n;i++) p[i]=i;
    if(n<=10){
        //n!
        int ans=0;
        do{
            int cnt=0,s=0;
            for(int i=1;i<=n;i++){
                if(str[i]=='0'){
                    cnt++;
                    continue;
                }
                if(cnt>=c[p[i]]){
                    cnt++;
                    continue;
                }
                if(str[i]=='1') s++;
            }
            ans+=(s>=m);
        }while(next_permutation(p+1,p+n+1));
        cout<<ans<<'\n';

        return 0;
    }
    bool A=1;
    for(int i=1;i<=n;i++) if(str[i]=='0') A=0;
    if(A){
        ll ans=1;
        for(ll i=2;i<=n;i++) ans=ans*i%mod;
        cout<<ans;
        return 0;
    }
    cout<<0;








    
    





    return 0;
}
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0

*/