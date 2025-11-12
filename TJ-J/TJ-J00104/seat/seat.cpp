#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int s=a[1];
    sort(a+1,a+1+n,cmp);
    cout<<m<<' '<<n;
    return 0;

}
