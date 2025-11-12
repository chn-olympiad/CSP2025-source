#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m,a[N],now;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    now=a[1];
    sort(a+1,a+1+n*m,cmp);
    int cnt=0;
    for(int i=1;i<=n*m;i++){
        if(a[i]==now){
            cnt=i;
            break;
        }
    }
    if(cnt%n==0){
        if((cnt/n)%2==0){
            cout<<cnt/n<<" "<<1;
        }
        else if((cnt/n)%2!=0){
            cout<<cnt/n<<" "<<n;
        }
    }
    else{
        if((cnt/n+1)%2==0){
            cout<<cnt/n+1<<" "<<(n+1)-cnt%n;
        }
        else if((cnt/n+1)%2!=0){
            cout<<cnt/n+1<<" "<<cnt%n;
        }
        return 0;
    }
    return 0;
}