#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int n[15];
int m[15];
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int t=n*m;
    int d=0;
    for(int i=1;i<=t;i++){
        cin>>a[i];
    }
     d=a[0];
    sort(a,a+t+1,cmp);
            for(int j=1;j<=m;j++){
                if(a[j]==d){
                    cout<<j<<" "<<"1";
                }
            }
    return 0;
}
