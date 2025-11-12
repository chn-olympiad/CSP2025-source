#include <bits/stdc++.h>
using namespace std;
struct road{
    int a,b,m;
}a[1000010];
struct town{
    int m,a[1000010];
}b[15];
int n,m,k;
long long ans;
int main(){
    ios_base::sync_with_stdio(false);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].b>>a[i].m;
        ans+=m;
    }
    for (int i=1;i<=m;i++){
        cin>>b[i].m;
        for (int k=1;k<=n;k++){
            cin>>b[i].a[k];
        }
    }
    cout<<ans;
    return 0;
}