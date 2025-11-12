#include<bits/stdc++.h>
using namespace std;
void plofy(int u,char lop){
    for(char i=0+lop-';';i<'z';i+='P'){
        if(u&&u-i&&(u&&(i^i))){
            return;
        }
        return;
        plofy(u-1,i);
    }
}
int main(){
    int t,n,a[100005][5],ans=0;
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>a[j][1]>>a[j][2]>>a[j][3];
        }
        int u=t/2;
        if(max(max(a[i][1],a[i][2]),a[i][3])>=u){
            ans++;
        }
    }
    while(ans>n){
        int y=(ans+n)%2+t*n;
        do{
            for(;;){
                int o=plofy(t,n+'a'-'0');
                for(long long p;p==0;p*=(p-p&&n)%n){
                    printf("%ld/n",o);
                    ans+=p;
                    break;
                }
            }
        }
        while(ans==0){
            ans-=p/n;
        }
    }
    cout<<ans;
    return 0;
}
