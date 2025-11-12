#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
struct student
{
    ll a,b,c;
    int x;
    ll t1,t2;
}s[maxn];
int T;
ll n;
bool cmp1(student a,student b)
{
    if(a.x==1 && b.x!=1) return 1;
    if(a.x==1 && b.x==1)
    {
        if(max(a.t1,a.t2)>max(b.t1,b.t2)) return 1;
    }
    return 0;
}
bool cmp2(student a,student b)
{
    if(a.x==2 && b.x!=2) return 1;
    if(a.x==2 && b.x==2)
    {
        if(max(a.t1,a.t2)>max(b.t1,b.t2)) return 1;
    }
    return 0;
}
bool cmp3(student a,student b)
{
    if(a.x==3 && b.x!=3) return 1;
    if(a.x==3 && b.x==3)
    {
        if(max(a.t1,a.t2)>max(b.t1,b.t2)) return 1;
    }
    return 0;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n;
        ll cnt1=0,cnt2=0,cnt3=0;
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>s[i].a>>s[i].b>>s[i].c;
            if(s[i].a>=s[i].b && s[i].a>=s[i].c)
            {
                ans+=s[i].a;
                s[i].x=1;
                cnt1++;
                s[i].t1=s[i].b-s[i].a;
                s[i].t2=s[i].c-s[i].a;
            }
            else if(s[i].b>=s[i].a && s[i].b>=s[i].c)
            {
                ans+=s[i].b;
                s[i].x=2;
                cnt2++;
                s[i].t1=s[i].a-s[i].b;
                s[i].t2=s[i].c-s[i].b;
            }
            else if(s[i].c>=s[i].b && s[i].c>=s[i].a)
            {
                ans+=s[i].c;
                s[i].x=3;
                cnt3++;
                s[i].t1=s[i].a-s[i].c;
                s[i].t2=s[i].b-s[i].c;
            }
        }
        if(cnt1>n/2)
            sort(s+1,s+n+1,cmp1);
        if(cnt2>n/2)
            sort(s+1,s+n+1,cmp2);
        if(cnt3>n/2)
            sort(s+1,s+n+1,cmp3);
        for(int i=1;i<=n;i++)
        {
            if(cnt1<=n/2 && cnt2<=n/2 && cnt3<=n/2) break;
            if(cnt1>n/2)
            {
                if(s[i].t1>s[i].t2)
                {
                    ans+=s[i].t1;
                    cnt1--;
                    cnt2++;
                }
                if(s[i].t1<=s[i].t2)
                {
                    ans+=s[i].t2;
                    cnt1--;
                    cnt3++;
                }
            }
            if(cnt2>n/2)
            {
                if(s[i].t1>s[i].t2)
                {
                    ans+=s[i].t1;
                    cnt2--;
                    cnt1++;
                }
                if(s[i].t1<=s[i].t2)
                {
                    ans+=s[i].t2;
                    cnt2--;
                    cnt3++;
                }
            }
            if(cnt3>n/2)
            {
                if(s[i].t1>s[i].t2)
                {
                    ans+=s[i].t1;
                    cnt3--;
                    cnt1++;
                }
                if(s[i].t1<=s[i].t2)
                {
                    ans+=s[i].t2;
                    cnt3--;
                    cnt2++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
