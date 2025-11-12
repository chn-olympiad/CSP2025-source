//40
#include<bits/stdc++.h>
using namespace std;
int n;
int a[(int)1e5+10];
int sum=0;
void dfs(int m,int s,int num,int maxx) {    //n bangxin s:zuidashu
    if(!m) {
        // cout<<m<<" "<<num<<" "<<maxx<<endl;
        if(num>maxx*2) {
            sum=sum%998244353+1;
        }
        return ;    
    }
    for(int i=s+1;i<=n;i++) {
        dfs(m-1,i,num+a[i],max(maxx,a[i]));
    }
}
int main() {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i=3;i<=n;i++) {
        dfs(i,0,0,0);

    }
    cout<<sum;
    return 0;
}
