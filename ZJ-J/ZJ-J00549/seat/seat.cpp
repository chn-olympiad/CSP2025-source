#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl '\n'
//#define int long long
using namespace std;
const int N=15;
int a[N*N];
signed main(void){
    IOS;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        a[i]=-a[i];
    }
    int xl=a[1];
    sort(a+1,a+1+n*m);
    for(int i=1;i<=n*m;i++){
        if(a[i]==xl){
            if(((i-1)/n)%2==0){
                cout<<((i+n-1)/n)<<" "<<((i-1)%n+1)<<endl;
            }else{
                cout<<((i+n-1)/n)<<" "<<n-((i-1)%n+1)+1<<endl;
            }
            return 0;
        }
    }
    return 0;
}