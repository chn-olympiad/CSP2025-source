#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,stu[115],a,num,b=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>stu[i];
    }
    a=stu[1];
    sort(stu+1,stu+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(stu[i]==a)
        {
            num=i;
            break;
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=n;j++)
            {
                b++;
                if(b==num)
                {
                    cout<<i<<' '<<j;
                    return 0;
                }
            }
        }
        else if(i%2==0)
        {
            for(int j=n;j>=1;j--)
            {
                b++;
                if(b==num)
                {
                    cout<<i<<' '<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
