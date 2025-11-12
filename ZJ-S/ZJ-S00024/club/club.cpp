#include <bits/stdc++.h>
using namespace std;
const int Maxn=100010;
long long T,n,a1[Maxn],a2[Maxn],a3[Maxn],cha[Maxn],top=1;
int c1,c2,c3;
long long Max;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        memset(a1,0,sizeof(a1));
        memset(a2,0,sizeof(a2));
        memset(a3,0,sizeof(a3));
        memset(cha,0,sizeof(cha));
        Max=0;
        top=1;
        c1=0;
        c2=0;
        c3=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a1[i]>>a2[i]>>a3[i];
        }
        for(int i=1;i<=n;i++)
        {
            if(a1[i]>=a2[i] and a1[i]>=a3[i])
            {
                Max+=a1[i];
                c1+=1;
            }
            else if(a2[i]>a1[i] and a2[i]>=a3[i])
            {
                Max+=a2[i];
                c2+=1;
            }
            else
            {
                Max+=a3[i];
                c3+=1;
            }
        }
        if(c1>n/2)
        {
            for(int i=1;i<=n;i++)
            {
                if(a1[i]>=a2[i] and a1[i]>=a3[i])
                {
                    cha[top]=a1[i]-max(a2[i],a3[i]);
                    top+=1;
                }
            }
            sort(cha+1,cha+top);
            for(int i=1;i<=c1-n/2;i++)
            {
                Max-=cha[i];
            }
        }
        if(c2>n/2)
        {
            for(int i=1;i<=n;i++)
            {
                if(a2[i]>a1[i] and a2[i]>=a3[i])
                {
                    cha[top]=a2[i]-max(a1[i],a3[i]);
                    top+=1;
                }
            }
            sort(cha+1,cha+top);
            for(int i=1;i<=c2-n/2;i++)
            {
                Max-=cha[i];
            }
        }
        if(c3>n/2)
        {
            for(int i=1;i<=n;i++)
            {
                if(a3[i]>a2[i] and a3[i]>a1[i])
                {
                    cha[top]=a3[i]-max(a2[i],a1[i]);
                    top+=1;
                }
            }
            sort(cha+1,cha+top);
            for(int i=1;i<=c3-n/2;i++)
            {
                Max-=cha[i];
            }
        }
        cout<<Max<<endl;
    }
    return 0;
}
