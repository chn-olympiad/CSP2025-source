#include<bits/stdc++.h>
using namespace std;

int x[11][11];

int y[200];

bool cmp(int a,int b){

     return a>b;

}
int n,m;

int main(){

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin >>n >>m;

    for(int i=0;i<n*m;i++){
        cin >>y[i];
    }
    int l=0;
    int r=y[0];
    sort(y,y+n*m,cmp);
    for(int i=0;i<n;i++){
        if(i%2==0){
            for(int j=0;j<m;j++){
                x[i][j]=y[l];
                l++;
            }
        }else{
            for(int j=m-1;j>=0;j--){
                x[i][j]=y[l];
                l++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(x[i][j]==r){
                cout <<i+1 <<" " <<j+1;
                return 0;
            }
        }
    }

    return 0;

}
