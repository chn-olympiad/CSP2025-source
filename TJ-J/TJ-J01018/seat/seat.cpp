#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int a[105]={0};
    cin>>n>>m;
    int r;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    r=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==r){
            r=i;
        }
    }
    if(r%n==0){

        if((r/n)%2!=0)cout<<r/n<<" "<<n;
        else cout<<r/n<<" "<<1;
    }
    else if((r/n+1)%2!=0) cout<<r/n+1<<" "<<r%n;
    else if((r/n+1)%2==0) cout<<r/n+1<<" "<<n-r%n+1;
    return 0;
}
