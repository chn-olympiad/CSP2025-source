#include<bits/stdc++.h>
#define cint const int
#define uint unsigned int
#define cuint const unsigned int
#define ll long long
#define cll const long long
#define ull const unsigned long long
#define cull const unsigned long long
using namespace std;
ll read()
{
    ll x=0;
    bool zf=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')zf=1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch-'0');
        ch=getchar();
    }
    return x;
}
void print(cll x)
{
    if(x<0)
    {
        putchar('-');
        print(-x);
        return;
    }
    if(x<10)
    {
        putchar(x+'0');
        return;
    }
    print(x/10);
    putchar(x%10+'0');
}
void princh(cll x,const char ch)
{
    print(x);
    putchar(ch);
}
cint N=2e5,L=1e7+4e5+1;
int n,q;
struct Aho_Corasick_Automaton{
    struct node{
        int son[27];
        int fail;
        int cnt;
    }t[L+1];
    int tot;
    void insert(string st)
    {
        int p=0;
        // printf("%d ",p);
        for(char ch:st)
        {
            cint c=ch-'a';
            if(!t[p].son[c])t[p].son[c]=++tot;
            // printf("t[%d].son[%d]=%d\n",p,c,tot);
            p=t[p].son[c];
            // printf("%d ",p);
        }
        ++t[p].cnt;
        // putchar('\n');
    }
    struct que{
        int a[L+1],h,t;
        inline void clear(){h=0,t=-1;}
        inline void push(cint x){a[++t]=x;}
        inline void pop(){++h;}
        inline int front(){return a[h];}
        bool empty(){return (t<h);}
    }q;
    void init()
    {
        // printf("init:\n");
        q.clear();
        for(int i=0;i<=26;++i)
        {
            if(t[0].son[i])q.push(t[0].son[i]);
        }
        while(!q.empty())
        {
            cint p=q.front();
            q.pop();
            t[p].cnt+=t[t[p].fail].cnt;
            // printf("%d:%d\n",p,t[p].cnt);
            for(int c=0;c<=26;++c)
            {
                if(t[p].son[c])
                {
                    t[t[p].son[c]].fail=t[t[p].fail].son[c];
                    q.push(t[p].son[c]);
                }
                else
                {
                    t[p].son[c]=t[t[p].fail].son[c];
                }
            }
        }
    }
    int ask(string st)
    {
        int p=0,ans=0;
        for(char ch:st)
        {
            cint c=ch-'a';
            p=t[p].son[c];
            ans+=t[p].cnt;
        }
        return ans;
    }
}AC;
string s,t,st;
int pl,pr;
void insert()
{
    cin>>s>>t;
    if(s==t)return;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]!=t[i])
        {
            pl=i;
            break;
        }
    }
    for(int i=0;i<s.size();++i)
    {
        if(s[i]!=t[i])
        {
            pr=i;
        }
    }
    st="";
    for(int i=0;i<s.size();++i)
    {
        if(pl==i)st+='{';
        st+=s[i];
        st+=t[i];
        if(pr==i)st+='{';
    }
    // cout<<"ins:"<<st<<'\n';
    AC.insert(st);
}
void query()
{
    cin>>s>>t;
    if(s.size()!=t.size())
    {
        princh(0,'\n');
        return;
    }
    for(int i=0;i<s.size();++i)
    {
        if(s[i]!=t[i])
        {
            pl=i;
            break;
        }
    }
    for(int i=0;i<s.size();++i)
    {
        if(s[i]!=t[i])
        {
            pr=i;
        }
    }
    st="";
    for(int i=0;i<s.size();++i)
    {
        if(pl==i)st+='{';
        st+=s[i];
        st+=t[i];
        if(pr==i)st+='{';
    }
    // cout<<"qry:"<<st<<'\n';
    princh(AC.ask(st),'\n');
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    n=read();
    q=read();
    while(n--)insert();
    AC.init();
    while(q--)query();
    return 0;
}