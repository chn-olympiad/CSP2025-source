#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],n,k,cnt,flag,f,ans,ans1;
void dfs(int x,int s){
    if(x>n) return;
    int c=0;
    for(int i=x;i<=n;i++){
        c^=a[i];
        if(c==k){
            cnt++;
            if(cnt>=s){
                return;
            }
            dfs(i+1,s);
            return ;
        }
    }
    dfs(x+1,s);
}
bool check(int x){
    for(int i=1;i<=n-x+1;i++){
        cnt=0;
        dfs(i,x);
        if(cnt>=x){
            return 1;
        }
    }
    return 0;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1){
            flag=1;
        }
        if(a[i]!=1){
            f=1;
        }
        if(a[i]==1){
            ans1++;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]==1&&a[i+1]==1){
            ans++,i++;
        }
    }
    if(flag==0){
        if(f==1){
            if(k==1){
                cout<<ans1;
                return 0;
            }else{
                cout<<n-ans1+ans;
                return 0;
            }
        }else{
            cout<<n/2;
            return 0;
        }
    }
    int l=0,r=n+1;
    while(l+1<r){
        int mid=(l+r)/2;
        if(check(mid)){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    cout<<l;
    return 0;
}