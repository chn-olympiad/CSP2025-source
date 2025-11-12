#include <bits/stdc++.h>
using namespace std;
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int n,k,add=0;
cin>>n>>k;
int a[n+1],b[n+1]={0};


if(k==0&&n==1){
    for (int i=1;i<=n;i++){
    cin>>a[i];
    if(a[i]==0){
            add++;
    }
}
    cout<<0;
    return 0;
}
if(k==0){
for (int i=1;i<=n;i++){
    cin>>a[i];
    if(a[i]==0){
            add++;
    }
}
cout<<add;
return 0;
}




    return 0;
}
