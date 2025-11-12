#include<bits/stdc++.h>
using namespace std;
int const modd=998244353;
int main{
    int n,m,c[500],ans=0;
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    char s[500];
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    for(int i=0;i<n;i++){
        if(c[i]<0){
            break;
        }
        if(s[i]==0){
            c[i]=-1;
            c[i+1]--;
        }
    }
    for(int i=0;i<n;i++){
        if(c[i]>0){
            ans++;
        }
    }
    cout<<ans%modd;
    return 0;
}
