#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5010];
bool b[5010];
inline void dfs(int x){
    if(x==n+1){
        int ma=0,sum=0,c=0;
        for(int i=1;i<=n;i++)
            if(b[i]==true){
                ma=max(ma,a[i]);
                sum+=a[i];
                c++;
            }
        if(sum-ma>ma&&c>=3){
            ans++;
            ans%=998244353;
        }
        return;
    }
    b[x]=false;
    dfs(x+1);
    b[x]=true;
    dfs(x+1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    dfs(1);
    printf("%d",ans);
    return 0;
}

