#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int T,N,Ans,cnt1,cnt2,cnt3,A[maxn],B[maxn],C[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
    while( isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
    return ret*f;
}
int main(){
    freopen("club.in","r",stdin),freopen("club.out","w",stdout);
    T=read();
    while(T--){
        N=read();
        cnt1=0,cnt2=0,cnt3=0;Ans=0;
        for(int i=1;i<=N;i++){
            int x=read(),y=read(),z=read();
            if(x>=y&&x>=z){
                Ans+=x;
                A[++cnt1]=min(x-y,x-z);
                continue;
            }if(y>=x&&y>=z){
                Ans+=y;
                B[++cnt2]=min(y-x,y-z);
                continue;
            }if(z>=x&&z>=y){
                Ans+=z;
                C[++cnt3]=min(z-x,z-y);
                continue;
            }
        }
        if(cnt1*2<=N&&cnt2*2<=N&&cnt3*2<=N) {printf("%d\n",Ans);continue;}
        if(cnt1*2>N){
            sort(A+1,A+1+cnt1);
            for(int i=1;i<=cnt1-N/2;i++)Ans-=A[i];
        }if(cnt2*2>N){
            sort(B+1,B+1+cnt2);
            for(int i=1;i<=cnt2-N/2;i++)Ans-=B[i];
        }if(cnt3*3>N){
            sort(C+1,C+1+cnt3);
            for(int i=1;i<=cnt3-N/2;i++)Ans-=C[i];
        }
        printf("%d\n",Ans);
    }
    return 0;
}