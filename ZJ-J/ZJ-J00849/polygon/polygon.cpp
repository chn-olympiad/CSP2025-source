#include<bits/stdc++.h>
using namespace std;
int n=0;
int numb[5004]={};
int maxx=0,sum=0,ans=0;
void dfs(int m,int index){
    if(index>n||m>n) return ;
    if(m>=3&&sum>2*maxx){
        ans++;
        if(ans>998244353) ans-=998244353;
    }
    for(int i=index;i<n;i++){
        int t=maxx;
        maxx=numb[i];
        sum+=numb[i];
        dfs(m+1,i+1);
        maxx=t;
        sum-=numb[i];
    }

}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++) cin>>numb[i];
    sort(numb,numb+n);
    dfs(0,0);
    cout<<ans;
    return 0;
}
