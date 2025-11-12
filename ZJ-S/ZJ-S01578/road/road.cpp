#include<bits/stdc++.h>
#define maxn 10025
using namespace std;
int N,M,K,tot,Fa[maxn];long long Ans;
int C[15][maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
    while( isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
    return ret*f;
}
struct QSQ{
    int u,v,w;
    bool operator<(const QSQ &b)const{
        return w<b.w;
    }
}E[1000005],Enew[maxn];
int get(int x){if(x==Fa[x])return x;return Fa[x]=get(Fa[x]);}
signed main(){
    freopen("road.in","r",stdin),freopen("road.out","w",stdout);
    N=read(),M=read(),K=read();
    for(int i=1;i<=M;i++){
        int x=read(),y=read(),z=read();
        E[i]=(QSQ){x,y,z};
    }
    sort(E+1,E+1+M);
    for(int i=1;i<=N;i++) Fa[i]=i;
    for(int i=1;i<=M;i++){
        int x=get(E[i].u),y=get(E[i].v);
        if(x==y)continue;
        Fa[x]=y; Enew[++tot]=E[i]; Ans+=E[i].w;
        if(tot==N-1)break;
    }
    for(int i=1;i<=K;i++)
    for(int j=0;j<=N;j++) C[i][j]=read();
    for(int s=1;s<(1<<K);++s){
        long long Sum=0;int cnt=tot,nowk=0;
        for(int i=1;i<=tot;i++)E[i]=Enew[i];
        for(int i=0;i<K;i++) if((s>>i)&1) 
        {
            Sum+=C[i+1][0];
            for(int j=1;j<=N;j++)
                if(C[i+1][j]<=Enew[tot].w)
                E[++cnt]=(QSQ){j,N+1+i,C[i+1][j]}; //else break;
            ++nowk;
        }
        for(int i=1;i<=N+15;i++) Fa[i]=i;
        int tt=0;
        // printf("%lld %lld\n",s,Sum);
        sort(E+1,E+1+cnt);
        for(int i=1;i<=cnt;i++){
            int x=get(E[i].u),y=get(E[i].v);
            if(x==y)continue;
            Fa[x]=y; Sum+=E[i].w;
            if(Sum>=Ans||++tt==N-1+nowk)break;
        }
        Ans=min(Ans,Sum);
    }
    printf("%lld\n",Ans);
    // printf("%.4f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}