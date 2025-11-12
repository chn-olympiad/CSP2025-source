#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        long long n,a[100010][10],ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
            sort(a[i]+1,a[i]+4);

        }
        for(int i=1;i<=n;i++){
            ans+=a[i][1];
        }
        cout<<ans;
    }

	return 0;
}
