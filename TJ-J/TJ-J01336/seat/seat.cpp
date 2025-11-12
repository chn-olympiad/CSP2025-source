#include <bits/stdc++.h>
using namespace std;
bool cwp(int a,int b){
    return a>b;
}

int a[15][15],b[100],m,n,y;
int main(){
    freopen("seat","r",stdin);
    freopen("seat","r",stdout);
    cin>>m>>n;
    for(int i=1;i<=m*n;i++){
        cin>>b[i];
        y=b[1];
    }
    int x=m*n;
    sort(b,b+x,cwp);
    for(int i=1;i<=m;i++){
        for(int j=1;;){
            if(i%2!=0){
                j=1;
                j++;
            }else if(i%2==0){
                j=n;
                j--;
            }
            int z=1;
            z=1;
            a[i][j]=b[z];
            z++;
            if(a[i][j]==y){
                cout<<i<<" "<<j;
                return 0;
            }

        }
    }
    return 0;
}
