#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int n2=n*m;
    int c;
    for(int i=1;i<=n2;i++){
        cin>>a[i];
        if(i==1){
            c=a[i];
        }
    }
    int l,r;
    sort(a+1,a+n2+1);
    for(int i=n2;i>=1;i--){
        if(a[i]==c){
            l=i;
        }
    }
    r=n2-(l-1);
    if(n2%2==1){
        int b=r/m,t=r-(b*n);
        cout<<b+1<<' '<<t;
    }
    else{
        int b=r/m,t=r%n;
        cout<<b+1<<' '<<t+1;
    }
    return 0;
}
