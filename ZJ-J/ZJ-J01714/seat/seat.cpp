#include <iostream>
#include <algorithm>

using std::cin;
using std::sort;
using std::cout;

int n,m,ansi,ansj,ok;
int a[110];

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n*m; i++)
    {
        cin>>a[i];
    }
    int x=a[1];
    sort(a+1,a+1+n*m,cmp);
    int flag=1;
    for(int j=1; j<=m; j++)
    {
        if(ok)break;
        if(flag==1)
        {
            for(int i=1; i<=n; i++)
            {
                int id=(j-1)*n+i;
                if(a[id]==x)
                {
                    ok=1;
                    ansi=i;
                    ansj=j;
                    break;
                }
            }
        }
        if(flag==-1)
        {
            for(int i=n; i>=1; i--)
            {
                int id=(j-1)*n+n-i+1;
                if(a[id]==x)
                {
                    ok=1;
                    ansi=i;
                    ansj=j;
                    break;
                }
            }
        }
        flag=-flag;
    }
    cout<<ansj<<' '<<ansi<<'\n';
    return 0;
}
