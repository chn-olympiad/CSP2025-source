#include <bits/stdc++.h>
using namespace std;
int mian(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;i++){
            for(int i=j;i<=k;i++){
                if(i+j>=n){
                    cout<<i+j;
                }else{
                    cout<<"no";
                }
            }
        }
    }
    cout<<n<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
