#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,jjjjj,iin,ans=1,ans1,ans2;
    bool a[105];
    cin>>n>>m;
    cin>>jjjjj;
    for(int i=1;i<n*m;i++){
        cin>>iin;
        if(iin>jjjjj){
            ans++;
        }
    }
    if((ans-1)/n%2==1){
        cout<<(ans-1)/n+1<<" "<<n-((ans-1)%n);
    }else{
        cout<<(ans-1)/n+1<<" "<<(ans-1)%n+1;
    }
    return 0;
}

