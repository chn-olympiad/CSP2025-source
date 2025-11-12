#include<bits/stdc++.h>
using namespace std;
#define ll long long
// ll n=1e3,m=1e5,k=4;
ll n=1e4,m=1e6,k=10;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("road.in","w",stdout);
    cout<<n<<" "<<m<<" "<<k<<"\n";
    srand(time(0));
    for(int i=2;i<=n;i++){
        ll x=rand()%i+1;
        cout<<x<<" "<<i<<" "<<rand()%1000<<"\n";
    }
    for(int i=n;i<=m;i++){
        ll x=rand()%n+1,y=rand()%n+1;
        while(x==y) x=rand()%n+1;
        cout<<x<<" "<<y<<" "<<rand()%100<<"\n";
    }
    for(int i=1;i<=k;i++){
        cout<<rand()%100<<" ";
        for(int i=1;i<=n;i++) cout<<rand()%1000<<" ";
        cout<<"\n";
    }
    return 0;
}