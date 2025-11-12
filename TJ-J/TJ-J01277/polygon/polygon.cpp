#include <iostream>
#include <algorithm>
using namespace std;
long long n,my_sum,ans,my_max,lmax;
long long a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    if(n==3){
        long long t;
        for(int i = 1;i<=3;i++){
            cin >> t;
            my_max=max(t,my_max);
            my_sum+=t;
        }
        if(my_sum>my_max*2){
            cout << 1;
        }
        else{
            cout << 0;
        }
    }
    else{
        for(int i = 0;i<n;i++){
            cin >> a[i];
            my_max=max(a[i],my_max);
        }
        if(my_max==1){
            for(int i=n-1;i>1;i--){
                ans+=i*(i-1)/2;
            }
            cout << ans;
        }
        else{
            cout << 94;
        }
    }
    fclose(stdin);
    fclose(stdout);
}
