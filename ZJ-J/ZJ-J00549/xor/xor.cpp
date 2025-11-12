#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl '\n'
//#define int long long
using namespace std;
const int N=5e5+5;
map<int,bool>mp;
int n,k;
int ans;
signed main(void){
    IOS;
     freopen("xor.in","r",stdin);
     freopen("xor.out","w",stdout);
    cin>>n>>k;
    mp[0]=1;
    int yh=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        yh^=x;
        if(mp[k^yh]==1){
            ans++;
            yh=0;
            mp.clear();
            mp[0]=1;
        }
        mp[yh]=1;
    }
    cout<<ans<<endl;
    return 0;
}