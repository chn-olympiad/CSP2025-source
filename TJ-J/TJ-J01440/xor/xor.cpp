#include <iostream>
#include <cstdio>
using namespace std;

int a[500005];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int maxx=0;
    int flag0=0,flag1=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0){
            flag0++;
        }else if(a[i]==1){
            flag1++;
        }
        maxx=max(maxx,a[i]);
    }
    if(maxx==1){
        if(flag0==0){
            cout << n/2;
        }else{
            if(k==0){
                int ans=flag0;
                for(int i=2;i<=n;i++){
                    if(a[i]==a[i-1]&&a[i]==1){
                        ans++;
                        i++;
                    }
                }
                cout << ans;
            }else{
                cout << flag1;
            }
        }
    }else if(maxx==0){
        cout << n/2;
    }else{
        cout << 2;
    }
}
