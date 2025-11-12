#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,ans,baoli[500010];
long long a[500010],k,t;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    if (k==0){
        for(int i=0;i<n;i++){
            cin >> a[i];
            if(a[i]==0){
                ans++;
            }
        }

    }
    else{
        for(int i=0;i<n;i++){
            cin >> a[i];
		}
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(baoli[i]){
                    break;
                }
                t=a[i];
                for(int z=1;z<=j-i;z++){
                    if(baoli[i+z]){
                        break;
                    }
                    t = a[i+z]^t;
                }
                if(t==k){
                    for(int z=0;z<=j-i;z++){
                        baoli[i+z]++;
                    }
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans;

    fclose(stdin);
    fclose(stdout);
}
