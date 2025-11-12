#include <bits/stdc++.h>
using namespace std;
struct name
{
    int c1,c2,c3;
};
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    name a[100005]={};
    int ans[5]={};
    for(int k=0;k<t;k++)
    {
        int n;
        cin>>n;

        for(int i=0;i<n;i++)
        {
            cin>>a[i].c1>>a[i].c2>>a[i].c3;
        }
        for(int i=0;i<n;i++)
        {
            ans[i]+=max(a[i].c1,max(a[i].c2,a[i].c3));
        }
        
    }
    for(int i=0;i<t;i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}

