#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int read(){
    int ret=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
    while( isdigit(ch)){ret=(ret<<3)+(ret<<1)+(ch&15);ch=getchar();}
    return ret*f;
}
int T,n,cnt1,cnt2,cnt3;
int a[maxn][4],del[maxn],id1[maxn],id2[maxn],id3[maxn];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    T=read();
    while(T--){
        long long ans=0;
        n=read();cnt1=cnt2=cnt3=0;
        for(int i=1;i<=n;++i){
            a[i][1]=read();
            a[i][2]=read();
            a[i][3]=read();
            int trv=max({a[i][1],a[i][2],a[i][3]});
            if(a[i][1]==trv){
                id1[++cnt1]=i;
            }else if(a[i][2]==trv){
                id2[++cnt2]=i;
            }else{
                id3[++cnt3]=i;
            }
            ans+=trv;
        }
        if(cnt1>n/2){
            for(int i=1;i<=cnt1;++i) del[i]=a[id1[i]][1]-max(a[id1[i]][2],a[id1[i]][3]);
            sort(del+1,del+cnt1+1);
            int m=cnt1-(n/2);
            for(int i=1;i<=m;++i) ans-=del[i];
        }else if(cnt2>n/2){
            for(int i=1;i<=cnt2;++i) del[i]=a[id2[i]][2]-max(a[id2[i]][1],a[id2[i]][3]);
            sort(del+1,del+cnt2+1);
            int m=cnt2-(n/2);
            for(int i=1;i<=m;++i) ans-=del[i];
        }else if(cnt3>n/2){
            for(int i=1;i<=cnt3;++i) del[i]=a[id3[i]][3]-max(a[id3[i]][1],a[id3[i]][2]);
            sort(del+1,del+cnt3+1);
            int m=cnt3-(n/2);
            for(int i=1;i<=m;++i) ans-=del[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}