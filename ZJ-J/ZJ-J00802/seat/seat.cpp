#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,m;
int a[1005],x,id;
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    //freopen("seat3.in","r",stdin);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    x=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==x) id=i;
    }
    int sum=0;
    while(id>n){
        id-=n;
        sum++;
    }
    if(sum%2==0){
        cout<<sum+1<<' '<<id;
    }else{
        cout<<sum+1<<' '<<m-id+1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
