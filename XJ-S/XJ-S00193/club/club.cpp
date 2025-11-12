#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N][5],v[5],vm;
long long ans=0,as;
void dfs(int i,int j){
    v[j]++;
    if(v[j]>vm){
        v[j]--;
        return ;
    }
    as+=a[i][j];
    if(i>=n){
        ans=max(ans,as);
        as-=a[i][j];
        v[j]--;
        return ;
    }
    for(int k=1;k<=3;k++){
        dfs(i+1,k);
    }
    v[j]--;
    as-=a[i][j];
    return ;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
		ans=0;
        as=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
        }
        vm=n>>1;
        for(int i=1;i<=3;i++){
            dfs(1,i);
        }
        cout<<ans<<endl;
    }
    return 0;
}
