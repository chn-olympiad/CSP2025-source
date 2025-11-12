#include<bits/stdc++.h>
using namespace std;
int n,m;
int c,r;
int a[1000005];
bool cmp(int a,int b){
    if(a>b) return 1;
    else  return 0;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
    }
    int sc=a[1];
    int f=0;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
   //         cout<<a[i]<<" ";
        if(a[i]==sc){
            f=i;
            break;
        }
    }
   // cout<<f<<endl;
    if(f%n==0){
        r=f/n;
        if(r%2) c=n;
        else c=1;
    }else{
        r=f/n+1;
        if(r%2) c=f%n;
        else c=n+1-f%n;
    }
    cout<<r<<" "<<c;
    return 0;
}
