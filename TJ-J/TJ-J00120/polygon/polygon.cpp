#include <bits/stdc++.h>
using namespace std;
long long n,a[5005],s=0,m=0,mm=0,c=0,co=0;
void dfs(int x){
    for(int i=x;i<n;i++){
        co++;
        s+=a[i];
        mm=m;
        m=max(a[i],m);
        if(s>2*m && co>=3){
            c=c%998244353+1;
        }
        dfs(i+1);
        m=mm;
        s-=a[i];
        co--;
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dfs(0);
    cout<<c;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
