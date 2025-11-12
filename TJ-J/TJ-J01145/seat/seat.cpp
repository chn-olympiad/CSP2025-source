#include <bits/stdc++.h>
using namespace std;

int mm[101];

bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,k=0;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>mm[i];
    }
    int a=mm[0];
    sort(mm,mm+n*m,cmp);
    for(int i=0;i<m;i++){
        if(i%2==0){
            for(int j=0;j<n;j++){
                if(mm[k]==a){
                    cout<<i+1<<' '<<j+1;
                }
                k++;
            }
        }else{
            for(int j=n-1;j>=0;j--){
                if(mm[k]==a){
                    cout<<i+1<<' '<<j+1;
                }
                k++;
            }
        }
    }
    return 0;
}
