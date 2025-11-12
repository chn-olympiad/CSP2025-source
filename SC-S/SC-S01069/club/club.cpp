#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,cnt[N],a[N][3],id[N][3],val[N],pval;
void Work(){
    cin>>n;
    for(int i:{0,1,2}) cnt[i]=0;
    int ans=0;
    for(int i=1;i<=n;++i){
        for(int j:{0,1,2}){
            cin>>a[i][j];
            id[i][j]=j;
        }
        sort(id[i],id[i]+3,[&](int x,int y){
            return a[i][x]>a[i][y];
        });
        ans+=a[i][id[i][0]],++cnt[id[i][0]];
    }
    int mx=0;
    for(int i:{1,2})
        if(cnt[i]>cnt[mx]) mx=i;
    if(cnt[mx]>n/2){
        pval=0;
        for(int i=1;i<=n;++i)
            if(id[i][0]==mx) val[++pval]=a[i][id[i][0]]-a[i][id[i][1]];
        sort(val+1,val+pval+1);
        for(int i=1;i<=cnt[mx]-n/2;++i) ans-=val[i];
    }
    printf("%d\n",ans);
}
int main(){
    freopen("club.in","r",stdin),freopen("club.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int T; cin>>T;
    while(T--) Work();
    fclose(stdin),fclose(stdout);
    return 0;
}