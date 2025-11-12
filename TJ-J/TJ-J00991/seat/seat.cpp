#include<bits/stdc++.h>

using namespace std;
int main(){
    freopen("seat.in","r","stdin");
    freopen("seat.out","w","stdout");
    int w,h,s,a[105];
    cin>>w>>h;
    s=w*h;
    int b[105][105],x=0;
    for(int i=0;i<s;i++){
        cin>>a[i];
    }
    int m=a[0];
    for(int i=0;i<s;i++){
        for(int j=i+1;j<s;j++){
            if(a[i]<a[j]){
                swap(a[i],a[j]);
            }
        }
    }
    for(int i=w;i>0;i--){
        if(i%2==1){
            for(int j=0;j<h;j++){
                b[i][j]=a[x];
            }
        }
        else{
            for(int j=h;j>0;j--){
                b[i][j]=a[x];
            }
        }
        x++;
    }
    for(int i=0;i<w;i++){
        for(int j=0;j<h;j++){
            if(b[i][j]==m){
                cout<<i+1<<' '<<j+1;
                return 0;
            }
        }
    }
    return 0;
}

