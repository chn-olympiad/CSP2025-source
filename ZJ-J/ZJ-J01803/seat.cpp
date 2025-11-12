#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define VE vector
LL n,m,h=1,l=1,lun=1;VE<LL> ar;unordered_map<LL,pair<LL,LL>>a;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;ar.resize(n*m);
    for(LL i=0;i<n*m;i++){cin>>ar[i];}LL mi=ar[0];
    sort(ar.begin(),ar.end());
    for(LL i=0;i<n*m;i++){
        a[ar[i]]={h,l};
        if(lun%2){
            if(h==n){l++,lun++;}
            else h++;
        }else{
            if(h==1){l++,lun++;}
            else h--;
        }
    }
    cout<<a[mi].first<<" "<<a[mi].second;
}
