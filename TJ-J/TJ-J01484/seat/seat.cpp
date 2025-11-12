#include<iostream>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,p=0,a[101],h,l;
    cin>>n>>m;
    for (int i=0;i<n*m;i++){
        cin>>a[i];
    }
    for (int i=1;i<n*m;i++){
        if (a[i]>a[0])
            p++;
    }
    l=p/n;
    if (l%2==0){
        h=p%n+1;
    }
    if (l%2==1){
        h=n-p%n;
    }
    cout<<l+1<<' '<<h;
    return 0;
}
