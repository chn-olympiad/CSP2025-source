#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int i,n,k,a[500001],ma=-1;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>ma)
            ma=a[i];
    }
    cout<<ma;
    return 0;
}