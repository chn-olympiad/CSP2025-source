#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxn=310000;
int max(int a,int b){
    if(a>b) return a;
    return b;
}
int T;
int a1[maxn],a2[maxn],a3[maxn];
int b1[maxn],b2[maxn],b3[maxn];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T-->0){
        int n;
        int c1=0,c2=0,c3=0;
        long long ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int M=0;
            scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
            M=max(max(a1[i],a2[i]),a3[i]);
            if(M==a1[i]){
                b1[++c1]=a1[i]-max(a2[i],a3[i]);
            } else if(M==a2[i]){
                b2[++c2]=a2[i]-max(a1[i],a3[i]);
            } else{
                b3[++c3]=a3[i]-max(a1[i],a2[i]);
            }
            ans+=M;
        }
        if(c1>n/2){
            std::sort(b1+1,b1+c1+1);
            int i=0;
            while(c1>n/2){
                i++; c1--;
                ans-=b1[i];
            }
        } else if(c2>n/2){
            std::sort(b2+1,b2+c2+1);
            int i=0;
            while(c2>n/2){
                i++; c2--;
                ans-=b2[i];
            }
        } else if(c3>n/2){
            std::sort(b3+1,b3+c3+1);
            int i=0;
            while(c3>n/2){
                i++; c3--;
                ans-=b3[i];
            }
        }
        printf("%lld\n",ans);
        memset(a1,0,sizeof(int)*(n+5));
        memset(a2,0,sizeof(int)*(n+5));
        memset(a3,0,sizeof(int)*(n+5));
        memset(b1,0,sizeof(int)*(n+5));
        memset(b2,0,sizeof(int)*(n+5));
        memset(b3,0,sizeof(int)*(n+5));
    }
    return 0;
}
//#Ren5Jie4Di4Ling5%