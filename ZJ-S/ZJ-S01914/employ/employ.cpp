#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
char t[24];
int n,c[24],m,f[(1<<18)][20];
int lowbit(int x){
    return x&(-x);
}
int pcnt(int x){
    int rs=0;
    while(x){
        rs++;
        x-=lowbit(x);
    }
    return rs;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdin);
    scanf("%d%d",&n,&m);
    scanf("%s",t+1);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    f[0][0]=1;
    int S=(1<<n);
    for(int s=0;s<S;s++){
        int ppc=pcnt(s);
       // printf("%d %d\n",s,ppc);
        for(int j=1;j<=n;j++){
            if(s&(1<<(j-1))) continue;
            int to=s|(1<<(j-1));
            for(int i=0;i<=ppc;i++){
                if(t[ppc+1]=='0'){
                    f[to][i+1]+=f[s][i];
                }else{
                    if(i>=c[j]) f[to][i+1]+=f[s][i];
                    else f[to][i]+=f[s][i];
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<=n;i++){
       // printf("%d %d %d\n",f[S-1][i],n-i,m);
        if((n-i)>=m) ans+=f[S-1][i];
    }
    printf("%d",ans);
}