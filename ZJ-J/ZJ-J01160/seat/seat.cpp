#include <bits/stdc++.h>
using  namespace std;
int a[100000];
int main(){
    //cerr<<"deb\n";
    freopen("seat3.in","r",stdin);
    //freopen("seat.out","w",stdout);
    int n,m,t;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    t=a[1];
    sort(a+1,a+n*m+1,greater<>());
    for(int i=1;i<=n*m;i++){
        if(a[i]==t){
            t=i;
            break;
        };
    }
    int i=1,j=1,c=1;
    while(1){
        //cerr<<"D"<<i<<" "<<j<<"\n";
        if(c==t){
            cout<<i<<" "<<j;
            return 0;
        }
        if(j+1>m && i%2==1 || j-1<1 && i%2==0){
            i++;
        }
        else if(i%2==1){
            j++;
        }else{
            j--;
            if(j<=0){
                i++;
                j++;
            }
        }
        c++;

    }
}
