#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
struct HLC{
    int x,id;
    bool operator <(const HLC b)const{return x>b.x;}
}a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i].x,a[i].id=i;
    sort(a+1,a+1+n*m);
    for(int j=1;j<=m;j++)
    if(j%2){
        for(int i=1;i<=n;i++){
            cnt++;
            if(a[cnt].id==1){cout<<j<<' '<<i;return 0;}
        }
    }else{
        for(int i=n;i;i--){
            cnt++;
            if(a[cnt].id==1){cout<<j<<' '<<i;return 0;}
        }
    }
    return 0;
}