#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        ans+=a[i];
    }ans=(ans+8/n*3)/2;
	cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
