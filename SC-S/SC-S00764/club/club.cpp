#include<bits/stdc++.h>
using namespace std;

// struct IO{
//     char buf[1<<21],*p1,*p2;
//     #define gc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
//     inline int read(){  // used in unsigned. (0 ~ 2^31-1).
//         int x; char c=gc();
//         while(c<'0' || c>'9') c=gc();
//         while(c<='9' && c>='0') x=(x<<3)+(x<<1)+c-'0',c=gc();
//         return x;
//     }
// };

const int N=1e5+10;
int n,a[N][3],b[N],c[3],w[3];
int oth(int i,int o){
    if(o==0) return max(a[i][1],a[i][2]);
    if(o==1) return max(a[i][0],a[i][2]);
    return max(a[i][0],a[i][1]);
}
int calc(int o){
    iota(b+1,b+1+n,1);
    sort(b+1,b+1+n,[&](int x,int y){
        return a[x][o]-oth(x,o)>a[y][o]-oth(y,o);
    });
    int ret=0;
    for(int i=1;i<=n;i++){
        int u=b[i];
        ret+=(i<=n/2?a[u][o]:oth(u,o));
    }
    return ret;
}
void solve(){
    scanf("%d",&n);
    for(int i=0;i<3;i++)
        c[i]=w[i]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++)
            scanf("%d",&a[i][j]);
        if(a[i][0]>=oth(i,0)) ++c[0],w[0]+=a[i][0];
        else if(a[i][1]>=oth(i,1)) ++c[1],w[1]+=a[i][1];
        else ++c[2],w[2]+=a[i][2];
    }
    int hal=n/2;
    if(c[0]<=hal && c[1]<=hal && c[2]<=hal) printf("%d\n",w[0]+w[1]+w[2]);
    else printf("%d\n",max({calc(0),calc(1),calc(2)}));
    return ;
}
int main(){
    freopen("club.in","r",stdin);
    // freopen("./down/club/club5.in","r",stdin);
    freopen("club.out","w",stdout);
    int T; scanf("%d",&T);
    while(T--)  solve();
    return 0;
}