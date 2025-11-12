#include <bits/stdc++.h>
using namespace std;
int n,m,a[114],k,bf=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>a[0];
    k=a[0];
    for(int i=1;i<n*m;i++){
        cin>>a[i];
    }
    sort(a,a+n*m);
    int s=0,t=1,x=0;
    for(int i=n*m-1;i>=0;i--){
        s++;
        if(a[i]==k){
            if(bf==1){
                x=s;
            }
            else{
                x=n-s+1;
            }
            break;
        }
        if(n==s){
            s=0;
            bf=-bf;
            t++;
        }
    }
    cout<<t<<' '<<x;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
