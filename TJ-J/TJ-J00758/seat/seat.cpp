#include<bits/stdc++.h>
using namespace std;
int c;
int j=1,n,m,x=1,y=1,u;
int s[10010];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>s[i];
    }
    j = s[1];
    sort(s+1,s+(n*m)+1,greater<int>());//paixu
    for(int i=1;i<=n*m;i++){
        if(s[i]==j){
            u = i;
            break;
        }
    }
    x = (u+n-1)/n;
    cout<<x<<" ";
    u = u-n*(x-1);
    if(x%2==0){//jiouxing
        cout<<n-u+1;
    }else{
        cout<<u;
    }
    return 0;
}
//O(nm lognm)
