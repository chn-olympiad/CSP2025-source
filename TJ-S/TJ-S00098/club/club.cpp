#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,n,cnt[4],ans,anstmp;
struct A{
    ll v,id;
}a[100001][4];
void f(ll x){
    if(x>n){
        ans=max(ans,anstmp);
        return;
    }
    for(ll i=1;i<=3;i++){
        anstmp+=a[x][i].v;
        cnt[a[x][i].id]++;
        if(cnt[a[x][i].id]>(n>>1)){
            anstmp-=a[x][i].v;
            cnt[a[x][i].id]--;
            continue;
        }
        f(x+1);
        anstmp-=a[x][i].v;
        cnt[a[x][i].id]--;
    }
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T;
    while(T--){
        ans=0,anstmp=0;
        cin>>n;
        for(ll i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j].v;
                a[i][j].id=j;
            }
            sort(a[i]+1,a[i]+3,[](const A xx,const A yy){return xx.v<yy.v;});
        }
        f(1);
        cout<<ans<<'\n';
    }
	return 0;
}

