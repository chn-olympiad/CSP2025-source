#include <bits/stdc++.h>
using namespace std;
int t;
int a1[10005],a2[10005],a3[10005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    int c1,c2,c3,c4,c5,c6;
    for(int k=1;k<=t;k++)
    {
        int b[100005];
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a1[i]>>a2[i]>>a3[i];
        }
        if(max(max(a1[1],a2[1]),a3[1])==a1[1])
        {
            b[1]=1;
            c1=a1[1];
            if(max(a2[1],a3[1])==a2[1])
            {
                c2=a2[1];
                c3=a3[1];
            }
            else
            {
                c2=a3[1];
                c3=a2[1];
            }
        }
        cout<<max(max(a1[1],a2[1]),a3[1])+max(max(a1[2],a2[2]),a3[2])<<endl;

    }
    return 0;
}
