#include<bits/stdc++.h>
using namespace std;
const int maxn=1e2+6;
int n,m,a[maxn];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    int pos=n*m;
    int ans=a[1];
    sort(a+1,a+1+n*m);
    for(int i=1;i<=m;i++){
        if(i%2!=0){
            for(int j=1;j<=n;j++){
                if(a[pos]==ans){
                    cout<<i<<" "<<j;
                    return 0;
                }
                pos--;
            }
        }
        if(i%2==0){
            for(int j=n;j>=1;j--){
                if(a[pos]==ans){
                    cout<<i<<" "<<j;
                    return 0;
                }
                pos--;
            }
        }
    }
    return 0;
}
