#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[15][15],b[15];
int c,r,R;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    int x=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            b[x]=a[i][j];
            x++;
        }
    }
    R=a[1][1];
    sort(b+1,b+n+1);
    x=1;
    for(int i=m;i>=1;i--){
        if(i%2==0){
            for(int j=1;j<=n;j++){
                a[j][i]=b[x];
            }
        }
        else{
            for(int j=n;j>=1;j--){
                a[j][i]=b[x];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==R){
                r=i;
                c=j;
                break;
            }
        }
    }
    cout<<c<<" "<<r;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
