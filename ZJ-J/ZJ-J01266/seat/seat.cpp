#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int l=1;
    int a;
    cin>>a;
    for(int i=1;i<n*m;i++){
        int x;
        cin>>x;
        if(x>a) l++;
    }int r=l/n+1;
    int c=l%(2*n);
    if(c%n==0) r--;
    if(c==0) c=1;
    else if(c>n){
        c=2*n+1-c;
    }cout<<r<<' '<<c;
    return 0;
}
