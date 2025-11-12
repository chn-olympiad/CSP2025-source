#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int ans=0;
void godblessmeplease(){
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
        int maxx=max(max(a[1],a[2]),a[3]);
        if((a[1]+a[2]+a[3])>maxx*2){
            cout<<1;
        }else{
            cout<<0;
        }
    }else{
        godblessmeplease();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}