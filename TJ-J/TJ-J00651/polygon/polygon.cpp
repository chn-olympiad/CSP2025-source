#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<3)return cout<<0,0;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    if(accumulate(a.begin(),a.end(),0)>*max_element(a.begin(),a.end())*2)cout<<1;
    else cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
