#include <bits/stdc++.h>
using namespace std;
const int MAXN=500005;
int arr[MAXN];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    bool Aflag=true,Bflag=true;
    int cnt1=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(!Bflag) continue;
        if(arr[i]==1) cnt1++;
        if(arr[i]>1){
            Aflag=false;
            Bflag=false;
        }
        else if(arr[i]!=1) Aflag=false;
    }
    if(Aflag){
        int res;
        if(k==0) res=n/2;
        if(k==1) res=n;
        cout<<res<<"\n";
    }
    if(Bflag){
        int res;
        if(k==0){
            int cnt0=n-cnt1,cnt1to0=0;
            for(int i=0;i<n;i++){
                if(arr[i]==0||i==n-1) continue;
                if(arr[i+1]==1){
                    cnt1to0++;
                    i++;
                    continue;
                }
            }
            res=cnt0+cnt1to0;
        }
        if(k==1) res=cnt1;
        cout<<res<<"\n";
    }
    return 0;
}