#include <bits/stdc++.h>
using namespace std;
int n,k,a[114],s=0;
void dfs(int x,int y){
    for(int j=y+1;j<=n;j++){
        if(ih(x,a[j])==k){
            s++;
            break;
        }
        dfs(ih(x,a[j]),j);
    }
}
int ih(int x,int y){
    if(x==y){
        return 0;
    }
    if((x%2==0 && x>y) || (y%2==0 && y>x)){
        return x+y;
    }
    if((y%2==0 && x>y) || (x%2==0 && y>x)){
        return x-y;
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]==k){
            s++;
        }
        else{
            dfs(a[i],i);
        }
    }
    cout<<s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
