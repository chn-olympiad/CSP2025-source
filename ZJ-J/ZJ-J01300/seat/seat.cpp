#include<bits/stdc++.h>
using namespace std;
const int MAXN=18;
int n,m,a[MAXN*MAXN],b[MAXN][MAXN];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    int t=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    int idx=1;
    for(int j=1;j<=m;j++){
        if(j%2==1)
            for(int i=1;i<=n;i++){
                if(a[idx]==t)return cout<<j<<" "<<i,0;
                b[i][j]=a[idx++];
            }
        else
            for(int i=n;i>=1;i--){
                if(a[idx]==t)return cout<<j<<" "<<i,0;
                b[i][j]=a[idx++];
            }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
