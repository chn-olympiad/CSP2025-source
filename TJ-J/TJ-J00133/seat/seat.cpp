#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a1=0;
    cin>>n>>m;
    int a[n*m];
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    a1=a[0];
    sort(a,a+n*m);
    int x=1,y=1,i=n*m-1;
    while(a[i]>a1){
        if(y<n){
            if(y==1&&x%2==0){
                x++;
                i--;
            }else if(x%2!=0){
                y++;
                i--;
            }else{
                y--;
                i--;
            }
        }else if(y==n&&x%2!=0 || y==1&&x%2==0){
            x++;
            i--;
        }else if(y==n){
            y--;
            i--;
        }
    }
    cout<<x<<" "<<y;
    return 0;
}
