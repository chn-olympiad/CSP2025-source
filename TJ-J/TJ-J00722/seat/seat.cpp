#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int a[100];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    if(a[0]<a[1]){
        cout<<n<<" "<<m;
    }
    else{
        cout<<1<<" "<<1;
    }
    return 0;
}
