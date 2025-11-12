#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,a[100005][5],ans=0;
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>a[j][1]>>a[j][2]>>a[j][3];
        }
        int u=t/2;
        if(max(max(a[i][1],a[i][2]),a[i][3])>=u){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
