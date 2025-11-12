#include <iostream>
#include <cstdio>
using namespace std;

#define mod 998244353
int a[5005];
int n;
long long ans;
bool flag[5005];

bool f(){
    int maxx=0,sum=0,cnt=0;
    for(int i=1;i<=n;i++){
        if(flag[i]){
            sum+=a[i];
            maxx=max(maxx,a[i]);
            cnt++;
        }
    }
    if(sum>maxx*2&&cnt>=3){
        return true;
    }else{
        return false;
    }
    return false;
}

void dfs(int x){
    if(x==n+1){
        ans+=f();
        ans%=mod;
        return;
    }
    flag[x]=true;
    dfs(x+1);
    flag[x]=false;
    dfs(x+1);
    return;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int maxx=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    if(maxx==1){
        for(int i=3;i<=n;i++){
            int t=min(i,n-i);
            long long cnt=1;
            for(int j=1;j<=t;j++){
                cnt*=j;
            }
            long long cnt1=1;
            for(int j=n;j>=n-t+1;j--){
                cnt1*=j;
            }
            cnt1/=cnt;
            ans+=cnt1;
            ans%=mod;
        }
    }else{
        dfs(1);
    }
    cout << ans;
}
