#include<bits/stdc++.h>
using namespace std;

long long n,k;
long long x[500000];
bool y[500000];
int cnt=0;


int yh(int l,int r){

    if(l==r){
        if(y[l]==1){
            return -1;
        }else{
            return x[l];
        }
    }
    for(int i=l;i<=r;i++){
        if(y[i]==1){
            return -1;
        }
    }

    int p=x[l];
    for(int i=l+1;i<=r;i++){
        p=p^x[i];
    }

    return p;

}


int main(){

    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin >> n >>k;
    for(int i=0;i<n;i++){
        cin >> x[i];
    }

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(yh(i,j)==k && yh(i,j) !=-1){
                for(int k=i;k<=j;k++){
                    y[k]=1;
                }
                cnt++;
            }
        }
    }
    cout <<cnt;

    return 0;

}
