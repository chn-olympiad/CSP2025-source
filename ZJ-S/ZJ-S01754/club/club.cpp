#include <iostream>
#include <algorithm>

#define int long long

using std::cin;
using std::sort;
using std::swap;
using std::cout;

struct node
{
    bool operator<(node p)const
    {
        int x=a,y=b,z=c;
        if(x<y)swap(x,y);
        if(x<z)swap(x,z);
        if(y<z)swap(y,z);
        int bx=p.a,by=p.b,bz=p.c;
        if(bx<by)swap(bx,by);
        if(bx<bz)swap(bx,bz);
        if(by<bz)swap(by,bz);
        if(x-y==bx-by)return y-z>by-bz;
        return x-y>bx-by;
    }
    int a,b,c;
} a[100010];
int n;

signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        int a1=0,a2=0,a3=0,h=n/2,ans=0;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i].a>>a[i].b>>a[i].c;
        }
        sort(a+1,a+1+n);
        for(int i=1; i<=n; i++)
        {
            if(a[i].a>=a[i].b&&a[i].a>=a[i].c)
            {
                if(a1<h)
                {
                    ans+=a[i].a;
                    a1++;
                }
                else
                {
                    if(a[i].b>=a[i].c)
                    {
                        if(a2<h)
                        {
                            ans+=a[i].b;
                            a2++;
                        }
                        else
                        {
                            ans+=a[i].c;
                            a3++;
                        }
                    }
                    else
                    {
                        if(a3<h)
                        {
                            ans+=a[i].c;
                            a3++;
                        }
                        else
                        {
                            ans+=a[i].b;
                            a2++;

                        }
                    }
                }
            }
            else if(a[i].b>=a[i].a&&a[i].b>=a[i].c)
            {
                if(a2<h)
                {
                    ans+=a[i].b;
                    a2++;
                }
                else
                {
                    if(a[i].a>=a[i].c)
                    {
                        if(a1<h)
                        {
                            ans+=a[i].a;
                            a1++;
                        }
                        else
                        {
                            ans+=a[i].c;
                            a3++;
                        }
                    }
                    else
                    {
                        if(a3<h)
                        {
                            ans+=a[i].c;
                            a3++;
                        }
                        else
                        {
                            ans+=a[i].a;
                            a1++;
                        }
                    }
                }
            }
            else
            {
                if(a3<h)
                {
                    ans+=a[i].c;
                    a3++;
                }
                else
                {
                    if(a[i].a>=a[i].b)
                    {
                        if(a1<h)
                        {
                            ans+=a[i].a;
                            a1++;
                        }
                        else
                        {
                            ans+=a[i].b;
                            a2++;
                        }
                    }
                    else
                    {
                        if(a2<h)
                        {
                            ans+=a[i].b;
                            a2++;
                        }
                        else
                        {
                            ans+=a[i].a;
                            a1++;
                        }
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
