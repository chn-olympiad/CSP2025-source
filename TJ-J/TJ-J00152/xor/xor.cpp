#include <bits/stdc++.h>
using namespace std;
constexpr int N=5e5+5;
int n,k,a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    int cnt0=0,cnt1=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0) cnt0++;
        if(a[i]==1) cnt1++;
    }
    /// Special Type A
    if(cnt0==n&&k==0){
        cout<<n/2<<endl;
        return 0;
    }

    /// Special Type B
    /*
        0 xor 0 = 0
        0.xor 1 = 1
        1 xor 0 = 1
        1 xor 1 = 0
    */
    int cnt=0,flag=0;
    if(cnt0+cnt1==n&&k<=1){
        int xorr=a[1],i=1;
        for(;i<=n;i++){
            if(xorr==k&&flag!=1){
                cnt++;
                ///printf("i=%d,cnt=%d,xorr=%d\n",i,cnt,xorr);
                xorr=a[i+1];
                continue;
            }
            flag=0;
            xorr^=a[i];
            if(xorr==k){
                cnt++;
                ///printf("i=%d,cnt=%d,xorr=%d\n",i,cnt,xorr);
                xorr=a[i+1];
                flag=1;
            }
        }
    }
    cout<<cnt<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
