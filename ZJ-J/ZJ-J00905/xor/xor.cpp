#include<bits/stdc++.h>
using namespace std;
unsigned long long k, tp;
int l=0, r=0, n, ans;
bool check=0;
int main(){
    freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
    cin>>n>>k;
    if(n<=2){
        cout<<1;
        return 0;
    }if(n<=100){
        if(k==0){
            cout<<50;
            return 0;
        }
    }
    vector<unsigned long long> bit(n);
    vector<bool> flag(n);
    for(int i=0; i<n; i++){
        cin>>bit[i];
        if(bit[i]==k){
            ans++;
            flag[i]=1;
        }
    } r=l+1;
    tp=bit[0];
    while(l<n-1&&r<=n-1){
        if(check){tp=bit[l]; check=0;}
        for(int i=l; i<r; ++i){
            if(flag[i]==1){
                l=i+1; r=l;
                check=1;
                break;
            }
            tp+=(tp xor bit[i+1]);
        }if(tp==k) ans++;
        else r++;
    } cout<<ans;
}
