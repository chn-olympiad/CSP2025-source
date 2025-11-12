#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[11][11];
    for(int i=0;i<m;i++){
        for(int j=0;i<n;i++){
            cin>>a[i][j];
        }
    }
    int a1=a[1][1];
    for(int i=0;i<m;i++){
        for(int j=0;i<n-1;i++){
            if(i%2==0){
                if(a[i][j]<a[i][j+1]){
                    a[i][j]=a[i][j+1];
                }
            }
            else{
                if(a[i][j]>a[i][j+1]){
                    a[i][j+1]<a[i][j];
                }
            }
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;i<n;i++){
            if(a[i][j]==a1){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
