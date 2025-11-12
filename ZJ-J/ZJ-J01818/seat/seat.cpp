#include <bits/stdc++.h>
using namespace std;

int n,m;
typedef struct ppp
{
    int idx;
    int score;
    bool operator<(const ppp &c)const
    {
        return score>c.score;
    }
}ppp;
ppp a[114];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;++i)
    {
        scanf("%d",&a[i].score);
        a[i].idx=i;
    }
    sort(a+1,a+n*m+1);
    int now=0;
    int x=1,y=0;
    for(int i=1;i<=n*m;++i)
    {
        if(x&1)
        {
            ++y;
            if(y==n+1)
            {
                y=n;
                ++x;
            }
        }
        else
        {
            --y;
            if(y==0)
            {
                y=1;
                ++x;
            }
        }
        if(a[i].idx==1)
        {
            printf("%d %d",x,y);
            return 0;
        }
    }



    return 0;
}

