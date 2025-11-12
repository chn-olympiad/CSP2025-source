#include <bits/stdc++.h>
using namespace std;
#define int long long
#define itn long long

constexpr int maxn = 1e5+10;
typedef struct stu
{
    int fir,sec,thr;
    int c12,c23,c13;
    bool operator<(const stu& x)const
    {
        return (fir == x.fir)?(sec == x.sec)?thr<x.thr:sec<x.sec:fir<x.fir;
    }
} stu;
stu stus[maxn];
int n;
int ans;
void subA()
{
    ans = 0;
    sort(stus+1,stus+n+1);
    for(int i = n; i>(n>>1); --i)
    {
        ans += stus[i].fir;
    }
    printf("%lld\n",ans);
}
vector<int> id1;
vector<int> id2;
bool cmp1(int a,int b)
{
    return stus[a].c12>stus[b].c12;
}
bool cmp2(int a,int b)
{
    return stus[a].c12>stus[b].c12;
}
void subB()
{
    id1.clear();
    id2.clear();
    int sum1 = 0,sum2 = 0;
    for(int i = 1; i<=n; ++i)
    {
        if(stus[i].fir>stus[i].sec)
        {
            sum1 += stus[i].fir;
            id1.push_back(i);
        }
        else
        {
            sum2 += stus[i].sec;
            id2.push_back(i);
        }
    }
    sort(id1.begin(),id1.end(),cmp1);
    sort(id2.begin(),id2.end(),cmp2);
    int n1 = id1.size();
    int n2 = id2.size();
    int hfn = n>>1;
    while(n1>hfn)
    {
        sum1 -= stus[id1.back()].fir;
        sum2 += stus[id1.back()].sec;
        id1.pop_back();
        --n1;
    }
    while(n2>hfn)
    {
        sum1 += stus[id2.back()].fir;
        sum2 -= stus[id2.back()].sec;
        id2.pop_back();
        --n2;
    }
    printf("%lld\n",sum1+sum2);
}
vector<int> id3;
bool svcmp1(int a,int b)
{
    int amin = min(stus[a].c12,stus[a].c13);
    int bmin = min(stus[b].c12,stus[b].c13);
    return amin>bmin;
}
bool svcmp2(int a,int b)
{
    int amin = min(stus[a].c23,stus[a].c12);
    int bmin = min(stus[b].c23,stus[b].c12);
    return amin>bmin;
}
bool svcmp3(int a,int b)
{
    int amin = min(stus[a].c13,stus[a].c23);
    int bmin = min(stus[b].c23,stus[b].c13);
    return amin>bmin;
}
void solve()
{
    id1.clear();
    id2.clear();
    id3.clear();
    int sum1 = 0,sum2 = 0,sum3 = 0;
    for(int i = 1; i<=n; ++i)
    {
        bool p1 = stus[i].fir>=stus[i].sec;
        bool p2 = stus[i].fir>=stus[i].thr;
        bool p3 = stus[i].sec>=stus[i].thr;
        if(p1&&p2)
        {
            sum1 += stus[i].fir;
            id1.push_back(i);
        }
        else if((!p1)&&p3)
        {
            sum2 += stus[i].sec;
            id2.push_back(i);
        }
        else
        {
            sum3 += stus[i].thr;
            id3.push_back(i);
        }
    }
    int hfn = n>>1;
    int n1 = id1.size();
    int n2 = id2.size();
    int n3 = id3.size();
    while(n1>hfn||n2>hfn||n3>hfn)
    {
        sort(id1.begin(),id1.end(),svcmp1);
        while(n1>hfn)
        {
            int a = id1.back();
            sum1 -= stus[a].fir;
            if(stus[a].c12<stus[a].c13)
            {
                sum2 += stus[a].sec;
                id2.push_back(a);
                ++n2;
            }
            else if(stus[a].c12>stus[a].c13)
            {
                sum3 += stus[a].thr;
                id3.push_back(a);
                ++n3;
            }
            else
            {
                if(n2<hfn)
                {
                    sum2 += stus[a].sec;
                    id2.push_back(a);
                    ++n2;
                }
                else
                {
                    sum3 += stus[a].thr;
                    id3.push_back(a);
                    ++n3;
                }
            }
            id1.pop_back();
            --n1;
        }
        sort(id2.begin(),id2.end(),svcmp2);
        while(n2>hfn)
        {
            int a = id2.back();
            sum2 -= stus[a].sec;
            if(stus[a].c23<stus[a].c12)
            {
                sum3 += stus[a].thr;
                id3.push_back(a);
                ++n3;
            }
            else if(stus[a].c23>stus[a].c12)
            {
                sum1 += stus[a].fir;
                id1.push_back(a);
                ++n1;
            }
            else
            {
                if(n1<hfn)
                {
                    sum1 += stus[a].fir;
                    id1.push_back(a);
                    ++n1;
                }
                else
                {
                    sum3 += stus[a].thr;
                    id3.push_back(a);
                    ++n3;
                }
            }
            id2.pop_back();
            --n2;
        }
        sort(id3.begin(),id3.end(),svcmp3);
        while(n3>hfn)
        {
            int a = id3.back();
            sum3 -= stus[a].thr;
            if(stus[a].c13<stus[a].c23)
            {
                sum1 += stus[a].fir;
                id1.push_back(a);
                ++n1;
            }
            else if(stus[a].c13>stus[a].c23)
            {
                sum2 += stus[a].sec;
                id2.push_back(a);
                ++n2;
            }
            else
            {
                if(n1<hfn)
                {
                    sum1 += stus[a].fir;
                    id1.push_back(a);
                    ++n1;
                }
                else
                {
                    sum2 += stus[a].sec;
                    id2.push_back(a);
                    ++n2;
                }
            }
            id3.pop_back();
            --n3;
        }
    }
    printf("%lld\n",sum1+sum2+sum3);
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%lld",&t);
    while(t--)
    {
        int A = 0,B = 0;
        scanf("%lld",&n);
        for(int i = 1; i<=n; ++i)
        {
            scanf("%lld%lld%lld",&stus[i].fir,&stus[i].sec,&stus[i].thr);
            stus[i].c12 = llabs(stus[i].fir-stus[i].sec);
            stus[i].c13 = llabs(stus[i].fir-stus[i].thr);
            stus[i].c23 = llabs(stus[i].sec-stus[i].thr);
            if(stus[i].sec == 0 &&stus[i].thr == 0)
            {
                ++A;
            }
            if(stus[i].thr == 0)
            {
                ++B;
            }
        }
        if(A == n)
        {
            subA();
        }
        else if(B == n)
        {
            subB();
        }
        else
        {
            solve();
        }
    }
    return 0;
}
