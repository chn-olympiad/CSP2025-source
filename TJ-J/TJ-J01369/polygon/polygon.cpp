#include<bits/stdc++.h>
using namespace std;
int n,cnt;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    if(n<3) cout<<0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=3;i<=n;i++){
        for(int j=3;j<=n;j++){
            int sum=a[j-2]+a[j-1]+a[j];
            if(sum>a[j]*2) cnt++;
        }
    }
    cout<<cnt;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
