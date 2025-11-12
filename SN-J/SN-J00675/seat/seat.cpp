#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int my;
int a;
int n = 0;
int m = 0;
cin>>m;
cin>>n;
int z = n*m;
int b[100];
int c[11][11];
int d = 100;
for(int i=0;i<=100;i++){
    b[i]=-1;
}
for(int i=1;i<=z;i++){
    cin>>a;
    if(i==1){
        my = a;
    }
    b[a]++;
}
for(int i = 1;i<=m;i++){
    if(i%2==0){
    for(int j = n;j>=1;j--){
        while(b[d]==-1){
            d--;

        }
        c[j][i]=b[d];
        }
    }
    else{
        for(int j = 1;j<=n;j++){
        while(b[d]==-1){
            d--;
        }
        c[j][i]=b[d];
        }
    }
}
for(int j=0;j<=m;j++){
    for(int i = 0;i<=n;i++){
        if(c[j][i]==my){
            cout<<i<<" "<<j;
            return 0;
        }
    }
}
return 0;
}
