#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int q=0;q<t;q++)
    {
        int n;
        cin>>n;
        int a[100005][5],b[100005]={};
        for(int j=0;j<n;j++)
        {
            for(int p=0;p<3;p++)
            {
                cin>>a[j][p];
            }
        }
        for(int i=0;i<n;i++)
        {
            b[i]=a[i][0];
        }
        sort(b,b+n);
        for(int i=0;i<n/2;i++)
        {
            b[i]=0;
        }
        int k=0;
        for(int i=0;i<n;i++)
        {
            k+=b[i];
        }
        cout<<k;
    }
    return 0;
}
