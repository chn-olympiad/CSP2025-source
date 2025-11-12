#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,t,cnt=0,ans;
    cin>>t;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=3;j++){
            cnt+=i+j;
            cin>>a[i+j];
        }
    }
    cout<<cnt;
    return 0;
}
