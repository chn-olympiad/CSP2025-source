#include<bits/stdc++.h>
using namespace std;
struct hg
{
    int ha,hb,hc,maxx,minn=99999999,middle,bhd,bhz,bhx,vis;
} a[100005];
int n,b,s,kma,kmb,kmc;
bool cmp(hg x,hg y)
{
    return x.maxx>y.maxx;
}
bool cmpp(hg x,hg y)
{
    return x.middle>y.middle;
}
bool cmppp(hg x,hg y)
{
    return x.minn>y.minn;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    for(int i=1; i<=100004; i++)
    {
        a[i].minn=9999999;
    }
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>b;
        for(int j=1; j<=b; j++)
        {
            cin>>a[j].ha>>a[j].hb>>a[j].hc;
            if(a[j].maxx<a[j].ha)
            {
                a[j].maxx=a[j].ha;
                a[j].bhd=1;
            }
            if(a[j].maxx<a[j].hb)
            {
                a[j].maxx=a[j].hb;
                a[j].bhd=2;
            }
            if(a[j].maxx<a[j].hc)
            {
                a[j].maxx=a[j].hc;
                a[j].bhd=3;
            }
            if(a[j].minn>a[j].ha)
            {
                a[j].minn=a[j].ha;
                a[j].bhx=1;
            }
            if(a[j].minn>a[j].hb)
            {
                a[j].minn=a[j].hb;
                a[j].bhx=2;
            }
            if(a[j].minn>a[j].hc)
            {
                a[j].minn=a[j].hc;
                a[j].bhx=3;
            }
            if(a[j].ha>a[j].minn&&a[j].ha<a[j].maxx)
            {
                a[j].middle=a[j].ha;
                a[j].bhz=1;
            }
            if(a[j].hb>a[j].minn&&a[j].hb<a[j].maxx)
            {
                a[j].middle=a[j].hb;
                a[j].bhz=2;
            }
            if(a[j].hc>a[j].minn&&a[j].hc<a[j].maxx)
            {
                a[j].middle=a[j].hc;
                a[j].bhz=3;
            }
        }
        sort(a+1,a+b+1,cmp);
        for(int j=1; j<=b; j++)
        {
            if(kma<b/2&&a[j].bhd==1)
            {
                s+=a[j].maxx;
                kma++;
                a[j].vis=1;
            }
            if(kmb<b/2&&a[j].bhd==2)
            {
                s+=a[j].maxx;
                kmb++;
                a[j].vis=1;
            }
            if(kmc<b/2&&a[j].bhd==3)
            {
                s+=a[j].maxx;
                kmc++;
                a[j].vis=1;
            }
        }
        sort(a+1,a+b+1,cmpp);
        for(int j=1; j<=b; j++)
        {
            if(a[j].vis==0&&kma<b/2&&a[j].bhz==1)
            {
                s+=a[j].middle;
                kma++;
                a[j].vis=1;
            }
            if(a[j].vis==0&&kmb<b/2&&a[j].bhz==2)
            {
                s+=a[j].middle;
                kmb++;
                a[j].vis=1;
            }
            if(a[j].vis==0&&kmc<b/2&&a[j].bhz==3)
            {
                s+=a[j].middle;
                kmc++;
                a[j].vis=1;
            }
        }
        sort(a+1,a+b+1,cmppp);
        for(int j=1; j<=b; j++)
        {
            if(a[j].vis==0&&kma<b/2&&a[j].bhx==1)
            {
                s+=a[j].minn;
                kma++;
                a[j].vis=1;
            }
            if(a[j].vis==0&&kmb<b/2&&a[j].bhx==2)
            {
                s+=a[j].minn;
                kmb++;
                a[j].vis=1;
            }
            if(a[j].vis==0&&kmc<b/2&&a[j].bhx==3)
            {
                s+=a[j].minn;
                kmc++;
                a[j].vis=1;
            }
        }
        for(int j=1; j<=100004; j++)
        {
            a[j].maxx=0;
        }
        for(int j=1; j<=100004; j++)
        {
            a[j].middle=0;
        }
        for(int j=1; j<=100004; j++)
        {
            a[j].vis=0;
        }
        for(int j=1; j<=100004; j++)
        {
            a[j].minn=9999999;
        }
		cout<<s<<endl;
        s=0;
    }
    return 0;
}