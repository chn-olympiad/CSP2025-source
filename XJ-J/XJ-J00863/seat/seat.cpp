#include <bits/stdc++.h>
using namespace std;
const int MAXN=105,MAXA=101;
bool arr[MAXA]={0};
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int R;
    for(int i=0;i<n*m;i++){
        int t;
        cin>>t;
        if(i==0) R=t;
        arr[t]=true;
    }
    int cnt=0;
    for(int i=MAXA-1;i>R;i--) if(arr[i]) cnt++;
    int i=cnt/n,j=cnt%n;
    if(i%2==1) j=n-j-1;
    cout<<(i+1)<<" "<<(j+1)<<"\n";
    return 0;
}