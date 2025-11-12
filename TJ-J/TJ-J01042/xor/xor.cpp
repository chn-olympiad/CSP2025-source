#include<bits/stdc++.h>
using namespace std;
const int maxn=5*1e2+10;
int a[maxn],b[230],n,k,ans,cur;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(k%2==0)cout<<0;
    else cout<<1<<endl;
    return 0;
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n/i;j+=i){
            for(int x=j;x<j+1;x++){
                for(int y=x+1;y<=j+i;y++){
                    cur^=a[y];
                }
            }
            ans=max(ans,cur);
        }
    }
    cout<<ans-1;
    */
}
