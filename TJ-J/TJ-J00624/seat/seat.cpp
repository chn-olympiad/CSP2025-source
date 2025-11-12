#include <bits/stdc++.h>

using namespace std;

int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,b=0,v,c=0,r=0,add=1;
cin>>n>>m;
int a[n*m]={0};
for (int i=0;i<n*m;i++){
    cin>>a[i];
    b++;
}
v=a[0];
for (int i=0;i<b;i++){
    for (int j=1;j<b;i++){
        int lin=0;
        if(a[j-1]<a[j]){
            a[j]=lin;
            a[j]=a[j-1];
            a[j-1]=lin;
        }
    }
}

for (int i=0;i<b;i++){
    if (a[i]!=v){
        if(r=n){
            c++;
        add=-add;
        }
        else{
            r=r+add;
        }
    }
}
cout<<c<<' '<<r;
    return 0;
}
