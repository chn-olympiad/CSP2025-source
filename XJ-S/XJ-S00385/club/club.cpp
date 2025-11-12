#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N][4],ans,c[5],tmp[N];
inline void dfs(int i,int s){
    if(i==n+1){
        ans=max(ans,s);
        return ;
    }
    for(int j=1;j<=3;j++){
        if(c[j]+1<=n/2){
            c[j]+=1;
            dfs(i+1,s+a[i][j]);
            c[j]-=1;
        }
    }
}
inline bool cmp(const int &x,const int &y){
    return x>y;
}
inline void solve(){
    memset(tmp,0,sizeof(tmp));
    ans=0;
    memset(c,0,sizeof(c));
    scanf("%d",&n);
    int m=0;
    bool A[4]={1,1,1,1};
    for(int i=1;i<=n;i++)
        for(int j=1;j<=3;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]!=a[1][j])
                A[j]=false;
        }
    if(A[2]&&A[3]){
        for(int i=1;i<=n;i++){
            tmp[++m]=a[i][1];
        }
        sort(tmp+1,tmp+1+m,cmp);
        long long ret=0;
        for(int i=1;i<=n/2;i++)
            ret+=tmp[i];
        printf("%lld\n",ret);
        return ;
    }
    dfs(1,0);
    printf("%d\n",ans);
    return ;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}