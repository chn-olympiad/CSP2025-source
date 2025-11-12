#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[(int)1e5+10];
bool cmp(int a,int b) {
    return a>b;
}
int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) {
        cin>>a[i];
    }
    k=a[1];
    sort(a+1,a+n*m+1,cmp);
    // for(int i=1;i<=n*m;i++) {
    //     cout<<a[i]<<" ";
    // }
    int cnt=1;
    for(int i=1;i<=m;i++) {
        if(i%2==0) {
            for(int j=n;j>=1;j--) {
                if(a[cnt]==k) {
                    cout<<i<<" "<<j;
                    return 0;
                }
                cnt++;
            }
        }else {
            for(int j=1;j<=n;j++) {
                if(a[cnt]==k) {
                    cout<<i<<" "<<j;
                    return 0;
                }
                cnt++;
            }
        }

    }
    return 0;
}
