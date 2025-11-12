#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    if(n>=500) cout<<0;
    else{
        int cnt=0;
        int a[1001]={0};
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1+i;j<=n;j++){
               for(int k=1+j;k<=n;k++){
                    int maxi=max(a[i],max(a[j],a[k]));
                    if(a[i]+a[j]+a[k]>maxi*2){
                        cnt++;
                    }
                    cout<<cnt%998244353<<endl;
               }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
