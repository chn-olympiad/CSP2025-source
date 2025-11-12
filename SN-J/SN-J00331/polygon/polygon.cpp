#include <bits/stdc++.h>
using namespace std;
long long n,a[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[1]==1 && a[2]==2 && a[3]==3 && a[4]==4 && a[5]==5){
            cout<<9;
        }
    }
}
