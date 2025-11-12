#include<bits/stdc++.h>
using namespace std;
#define N 1000005
string r;
int ans[N],j;
int main(){
    freopen ("number.in","r",stdin);
    freopen ("number.out","w",stdout);
    cin>>r;
    for(int i=0;i<r.size();i++){
        if(r[i]>='0'&&r[i]<='9'){
            ans[j]+=r[i]-'0';
            j++;
        }
    }
    sort(ans,ans+j);
    for(int i=j-1;i>=0;i--){
        cout<<ans[i];
    }
    return 0;
}
