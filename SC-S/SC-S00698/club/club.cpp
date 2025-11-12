#include<bits/stdc++.h>
using namespace std;
#define maxn 100005

ifstream is("club.in", ios::in);
ofstream os("club.out", ios::out);
#define cin is
#define cout os

struct mem
{
    int w[3], id, de;
    mem() {}
    void init() 
    {
        int wm=max({w[0], w[1], w[2]});
        de=INT_MAX;
        if(wm==w[0]) id=0;
        if(wm==w[1]) id=1;
        if(wm==w[2]) id=2;
        if(id!=0) de=min(de, wm-w[0]);
        if(id!=1) de=min(de, wm-w[1]);
        if(id!=2) de=min(de, wm-w[2]);
    }
}ms[maxn];

bool cmp1(const mem &a, const mem &b) 
{
    if(a.de!=b.de) return a.de>b.de;
    return a.w[a.id]>b.w[b.id];
}

void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>ms[i].w[0]>>ms[i].w[1]>>ms[i].w[2];
        ms[i].init();
    }
    sort(ms+1, ms+n+1, cmp1);
    vector<int> cnt(3, n/2);
    int64_t sum=0;
    for(int i=1;i<=n;i++)
    {
        int p=ms[i].id;
        if(cnt[p]) 
        {
            cnt[p]--;
            sum+=ms[i].w[p];
        }
        else
        {
            sum+=ms[i].w[p]-ms[i].de;
        }
    }
    cout<<sum<<'\n';
}

int main()
{
    int t;
    cin>>t;
    while(t--) solve();
}