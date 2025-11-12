#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[1005];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>a[1]){
            cnt++;
        }
    }
    int t1=cnt/n;
    int t2=cnt%n;
    if(t1%2==1){
        cout << t1+1<< ' ' << n-t2;
    }else{
        cout << t1+1<< ' ' << t2+1;
    }
    return 0;
}
