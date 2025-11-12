#include <bits/stdc++.h>
using namespace std;
struct ppppp
{
    int a,b,c;
    ppppp()=default;
    ppppp(int a,int b,int c):a(a),b(b),c(c){}
};
vector<ppppp> p;
struct awa
{
    int idx;
    awa()=default;
    awa(int i):idx(i){}
    bool operator<(const awa &x) const
    {
        return p[idx].a>p[x.idx].a;
    }
};
struct bbbbb
{
    int idx;
    bbbbb()=default;
    bbbbb(int i):idx(i){}
    bool operator<(const bbbbb &x) const
    {
        return p[idx].b>p[x.idx].b;
    }
};
struct chy
{
    int idx;
    chy()=default;
    chy(int i):idx(i){}
    bool operator<(const chy&x) const
    {
        return p[idx].c>p[x.idx].c;
    }
};

signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        p.assign(n,ppppp());
        if(n<=10)
        {
            for(int i=0;i<n;++i)
            {
                scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
            }
            int awaawa=1;
            for(int i=1;i<=n;++i)
            {
                awaawa*=3;
            }
            int res=0;
            for(int i=0;i<awaawa;++i)
            {
                int tmpi=i;
                int tmp=0;
                int cnt1=0;
                int cnt2=0;
                int cnt3=0;
                for(int j=0;j<n;++j)
                {
                    if(tmpi%3==0)
                    {
                        ++cnt1;
                        if(cnt1>n>>1)
                        {
                            goto nxt;
                        }
                        tmp+=p[j].a;
                    }
                    else if(tmpi%3==1)
                    {
                        ++cnt2;
                        if(cnt2>n>>1)
                        {
                            goto nxt;
                        }
                        tmp+=p[j].b;
                    }
                    else
                    {
                        ++cnt3;
                        if(cnt3>n>>1)
                        {
                            goto nxt;
                        }
                        tmp+=p[j].c;
                    }
                    tmpi/=3;
                }
                res=max(res,tmp);
                nxt:;
            }
            printf("%d\n",res);
        }
        else
        {
            priority_queue<awa> a;
            priority_queue<bbbbb> b;
            priority_queue<chy> c;
            for(int i=0;i<n;++i)
            {
                scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
                if(p[i].a==max({p[i].a,p[i].b,p[i].c}))
                {
                    if(a.size()==n>>1)
                    {
                        int atop=a.top().idx;
                        const auto &aa=p[atop];
                        const auto &nn=p[i];
                        a.pop();
                        int maxnum=max
                        ({
                            aa.a+nn.b,
                            aa.a+nn.c,
                            nn.a+aa.b,
                            nn.a+aa.c
                        });
                        if(aa.a+nn.b==maxnum)
                        {
                            a.emplace(atop);
                            b.emplace(i);
                        }
                        else if(aa.a+nn.c==maxnum)
                        {
                            a.emplace(atop);
                            c.emplace(i);
                        }
                        else if(nn.a+aa.b==maxnum)
                        {
                            a.emplace(i);
                            b.emplace(atop);
                        }
                        else
                        {
                            a.emplace(i);
                            c.emplace(atop);
                        }
                    }
                    else
                    {
                        a.emplace(i);
                    }
                }
                else if(p[i].b==max({p[i].a,p[i].b,p[i].c}))
                {
                    if(b.size()==n>>1)
                    {
                        int btop=b.top().idx;
                        const auto &bb=p[btop];
                        const auto &nn=p[i];
                        b.pop();
                        int maxnum=max
                        ({
                            bb.b+nn.a,
                            bb.b+nn.c,
                            nn.b+bb.a,
                            nn.b+bb.c
                        });
                        if(bb.b+nn.a==maxnum)
                        {
                            b.emplace(btop);
                            a.emplace(i);
                        }
                        else if(bb.b+nn.c==maxnum)
                        {
                            b.emplace(btop);
                            c.emplace(i);
                        }
                        else if(nn.b+bb.a==maxnum)
                        {
                            b.emplace(i);
                            a.emplace(btop);
                        }
                        else
                        {
                            b.emplace(i);
                            c.emplace(btop);
                        }
                    }
                    else
                    {
                        b.emplace(i);
                    }
                }
                else
                {
                    if(c.size()==n>>1)
                    {
                        int ctop=c.top().idx;
                        const auto &cc=p[ctop];
                        const auto &nn=p[i];
                        c.pop();
                        int maxnum=max
                        ({
                            cc.c+nn.a,
                            cc.c+nn.b,
                            nn.c+cc.a,
                            nn.c+cc.b
                        });
                        if(cc.c+nn.a==maxnum)
                        {
                            c.emplace(ctop);
                            a.emplace(i);
                        }
                        else if(cc.c+nn.b==maxnum)
                        {
                            c.emplace(ctop);
                            b.emplace(i);
                        }
                        else if(nn.c+cc.a==maxnum)
                        {
                            c.emplace(i);
                            a.emplace(ctop);
                        }
                        else
                        {
                            c.emplace(i);
                            b.emplace(ctop);
                        }
                    }
                    else
                    {
                        c.emplace(i);
                    }
                }
            }
            int res=0;
            while(!a.empty())
            {
                res+=p[a.top().idx].a;
                a.pop();
            }
            while(!b.empty())
            {
                res+=p[b.top().idx].b;
                b.pop();
            }
            while(!c.empty())
            {
                res+=p[c.top().idx].c;
                c.pop();
            }
            printf("%d\n",res);
        }
    }
}