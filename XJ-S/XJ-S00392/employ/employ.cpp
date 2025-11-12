#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long pass_cnt=0,no_cnt=0;
    for(long long i=0;i<n;i++){
        char c;
        cin>>c;
        // cout<<c;
        if(c=='1') pass_cnt++;
    }
    cout<<pass_cnt<<endl;
    no_cnt=n-pass_cnt;
    if(pass_cnt==n){
        long long res=1;
        for(long long i=n;i>1;i++) res*=i;
        cout<<res<<"\n";
        return 0;
    }
    return 0;
}