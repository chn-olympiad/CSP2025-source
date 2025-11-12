#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ent putchar('\n')
#define sp putchar(' ')
#define pii pair<int,int>
#define fi first
#define se second
#define pl (p<<1)
#define pr ((p<<1)|1)
const int mod=998244353,inf=LONG_LONG_MAX/4;
int read(){int t;scanf("%lld",&t);return t;}
void write(int x){printf("%lld",x);return;}
const int N=1e5+10,RN=1e5;
int T,n,ans,cnt1,cnt2,cnt3;
pii a[3*N];
int vis[N];
struct node{
    int x,y,z,bs,cha;
}qaq[N];
inline bool cmp(const node&x,const node&y){return x.cha>y.cha;}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=read();
    while(T--){
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        ans=cnt1=cnt2=cnt3=0;
        n=read();
        int lim=n/2;
        for(int i=1;i<=n;i++){
            a[i*3-2].fi=read(),a[i*3-1].fi=read(),a[3*i].fi=read();
            a[i*3-2].se=i*3-2;
            a[i*3-1].se=i*3-1;
            a[i*3].se=i*3;
            qaq[i].x=a[i*3-2].fi,qaq[i].y=a[i*3-1].fi,qaq[i].z=a[i*3].fi;
        }
        sort(a+1,a+3*n+1,greater<pii>());
        for(int i=1;i<=3*n;i++){
            if(vis[(a[i].se-1)/3+1]) continue;
            if(a[i].se%3==1&&cnt1==lim) continue;
            if(a[i].se%3==2&&cnt2==lim) continue;
            if(a[i].se%3==0&&cnt3==lim) continue;
            if(a[i].se%3==1) cnt1++;
            if(a[i].se%3==2) cnt2++;
            if(a[i].se%3==0) cnt3++;
            vis[(a[i].se-1)/3+1]=1;
            ans+=a[i].fi;
        }
        int res1=0,res2=0,res3=0;
        for(int i=1;i<=n;i++){
            qaq[i].bs=max(qaq[i].y,qaq[i].z),qaq[i].cha=qaq[i].x-qaq[i].bs;
        }
        sort(qaq+1,qaq+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(i<=lim) res1+=qaq[i].x;
            else res1+=qaq[i].bs;
        } 
        for(int i=1;i<=n;i++){
            qaq[i].bs=max(qaq[i].x,qaq[i].z),qaq[i].cha=qaq[i].y-qaq[i].bs;
        }
        sort(qaq+1,qaq+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(i<=lim) res2+=qaq[i].y;
            else res2+=qaq[i].bs;
        } 
        for(int i=1;i<=n;i++){
            qaq[i].bs=max(qaq[i].x,qaq[i].y),qaq[i].cha=qaq[i].z-qaq[i].bs;
        }
        sort(qaq+1,qaq+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(i<=lim) res3+=qaq[i].z;
            else res3+=qaq[i].bs;
        } 
        ans=max({ans,res1,res2,res3});
        write(ans),ent;
    }
    return 0;
}
