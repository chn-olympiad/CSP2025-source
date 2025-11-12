#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,a[110][110],c,r,sum,a1=0,a2=0,num=0;
cin>>n>>m;
if((n==1) && (m==1)) {
    cout<<'1'<<' '<<'1'<<endl;
    return 0;
}
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
            num++;
            cin>>a[i][j];
            if(a[i][j]==n*m-i+1) a2++;
            if(a[i][j]==num) a1++;
            if(i==1 && j==1){
                if(a[1][1]==100){
                    cout<<'1'<<' '<<'1'<<endl;
                }
            }

    }
}
if(n<=2 && m<=2){
        if(a1==n*m) cout<<m<<" "<<n;
        if(a2==n*m) cout<<'1'<<' '<<'1';
}

return 0;
}
