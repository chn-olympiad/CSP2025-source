#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

int b[N];
int mvp(int n){
    if(n%2==0){
        return true;
    }
    return false;
}
int cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,ans=0;
    cin >> n >> m;
    for(int  i=1;i<=n*m;i++){
        if(i=1){
            ans=b[i];
        }
        cin >> b[i];
    }
    sort(b+1,n*m+b,cmp);
    for(int i=1;i<=n*m;i++){
        if(b[i]==ans){
            int z=i/n+1;
            int y=i%n;
            if(mvp(z)){
                int x=m-(m-y);
                cout << z << " " << x;
                break;
            }else{
                cout << z << " " << y;
                break;
            }
        }
    }
    return 0;
}
