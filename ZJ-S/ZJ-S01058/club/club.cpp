#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int w=0;char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) w=w*10+ch-'0',ch=getchar();
    return w;
}
const int N=100005;
int t;
int n;
int d[N][5];
int cnt[5];
int ans,bel[N];
int m;
int rk[N],val[N];
bool cmp(int a1,int a2){return val[a1]>val[a2];}
void mian(){
    cnt[0]=cnt[1]=cnt[2]=0;ans=0;
    n=read();
    for(int i=1;i<=n;i++){
        int cs=0;
        for(int j=0;j<3;j++){
            d[i][j]=read();
            if(d[i][j]>d[i][cs]) cs=j;
        }
        cnt[cs]++;
        ans+=d[i][cs];
        bel[i]=cs;
    }
    if(cnt[0]<=n/2&&cnt[1]<=n/2&&cnt[2]<=n/2){
        printf("%d\n",ans);
        return;
    }
    int ts=0;
    for(int i=1;i<3;i++) if(cnt[i]>cnt[ts]) ts=i;
    m=0;
    for(int i=1;i<=n;i++){
        if(bel[i]!=ts) continue;
        rk[++m]=i;
        val[i]=1e9;
        for(int j=0;j<3;j++){
            if(j==bel[i]) continue;
            val[i]=min(val[i],d[i][bel[i]]-d[i][j]);
        }
        // printf("QWQ %d %d\n",i,val[i]);
    }
    sort(rk+1,rk+1+m,cmp);
    while(m>n/2) ans-=val[rk[m--]];
    printf("%d\n",ans);
}
main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    t=read();
    while(t--){
        mian();
    }
}