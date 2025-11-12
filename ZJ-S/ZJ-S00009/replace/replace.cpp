/*
#include<bits/stdc++.h>
using namespace std;
const int N=5e6+10;
int n,Q,len,tot1,tot2,d1[N],d2[N],son1[N][27],son2[N][27];
char s1[N],s2[N];
int pos1[N],pos2[N],ok1[N],ok2[N];
map<pair<int,int>,int>mp;
vector<int>v[N];
void insert(int id)
{
    int p1=0,p2=0;
    for(int i=0;i<len;i++)
    {
        if(!son1[p1][s1[i]-'a'])son1[p1][s1[i]-'a']=++tot1;
        if(!son2[p2][s2[i]-'a'])son2[p2][s2[i]-'a']=++tot2;
        d1[son1[p1][s1[i]-'a']]=d1[p1]+1,d2[son2[p2][s2[i]-'a']]=d[p2]+1;
        p1=son1[p1][s1[i]-'a'],p2=son2[p2][s2[i]-'a'];
        // cout<<p1<<" "<<p2<<" "<<tot1<<" "<<tot2<<endl;
    }
    if(!mp[make_pair(p1,p2)])mp[make_pair(p1,p2)]=++node;
    pos1[id]=p1,pos2[id]=p2;
    return;
}
int hd,tl,q[N],fail1[N];
void build1()
{
    hd=1,tl=0;
    for(int i=0;i<26;i++)
    {
        if(son1[0][i])
        {
            q[++tl]=son1[0][i];
        }
    }
    while(hd<=tl)
    {
        int u=q[hd++];
        for(int i=0;i<26;i++)
        {
            if(son1[u][i])
            {
                fail1[son1[u][i]]=son1[fail1[u]][i];
                q[++tl]=son1[u][i];
            }
            else son1[u][i]=son1[fail1[u]][i];
        }
    }
    return;
}
int fail2[N];
void build2()
{
    hd=1,tl=0;
    for(int i=0;i<26;i++)
    {
        if(son2[0][i])
        {
            q[++tl]=son2[0][i];
        }
    }
    while(hd<=tl)
    {
        int u=q[hd++];
        for(int i=0;i<26;i++)
        {
            if(son2[u][i])
            {
                fail2[son2[u][i]]=son2[fail2[u]][i];
                q[++tl]=son2[u][i];
            }
            else son2[u][i]=son2[fail2[u]][i];
        }
    }
    return;
}
long long query()
{
    int p1=0,p2=0;
    long long res=0;
    for(int i=0;i<len;i++)
    {
        p1=son1[p1][s1[i]-'a'];
        p2=son2[p2][s2[i]-'a'];
        res+=mp[make_pair(p1,p2)];
    }
    return res;
}
int node,s[200010],fnode[200010][25],dep[200010];
pair<int,int>pi[N];
int find_fa(int p1,int p2)
{
    int tot=0;
    while(p2)
    {
        pi[++tot]={d2[p2],p2};
        p2=fail2[p2];
    }
    int j=1,ll;
    while(p1)
    {
        while(j<=tot&&pi[j].first>d1[p1])j++;
        if(j<=tot&&pi[j].first==d1[p1])
        {
            ll=mp[make_pair(p1,pi[j].second)];
            if(ll)return ll;
        }
        p1=fail1[p1];
    }
    return 0;
}
vector<int>nt[200010];
int lcs,lcp;
void dfs(int u)
{
    for(int v:nt[u])
    {
        s[v]+=s[u],dfs(v,u);
    }
    return;
}
int main()
{
    freopen("replace1.in","r",stdin);
    scanf("%d%d",&n,&Q);
    for(int i=1;i<=n;i++)
    {
        scanf("%s%s",s1,s2);
        len=strlen(s1);
        insert(i);
    }
    build1(),build2();
    for(int i=1;i<=n;i++)
    {
        int id=mp[make_pair(pos1[i],pos2[i])];
        if(!s[id])
        {
            dep[id]=d1[pos1[i]],fnode[id]=find_fa(pos1[i],pos2[i]);
        }
        s[id]++;
    }
    for(int i=1;i<=node;i++)nt[fnode[i]].push_back(i);
    for(int j=1;j<=20;j++)
    {
        for(int i=1;i<=node;i++)fnode[i][j]=fnode[fnode[i][j-1]][j-1];
    }
    while(Q--)
    {
        scanf("%s%s",s1,s2);
        len=strlen(s1);
        if(strlen(s2)!=len)printf("0\n");
        else 
        {
            lcs=lcp=0;
            for(int i=0;i<len;i++)
            {
                if(s1[i]==s2[i])lcp=i+1;
                else break;
            }
            for(int i=len-1;i>=0;i--)
            {
                if(s1[i]==s2[i])lcs=len-i;
                else break;
            }
            int p1=0,p2=0;
            for(int i=max(0,len-1-lcs);i<len;i++)
            {

            }
        }
    }
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,base=131,mod=1e9+7;
struct node{
    int h1,h2;
    vector<char>s1,s2;
}s[N];
char S1[5000010],S2[5000010];
int n,Q;
bool cmp(node x,node y)
{
    return x.s1.size()<y.s1.size();
}
int H1[5000010],H2[5000010],pw[5000010];
int sum(int h[5000010],int l,int r)
{
    if(l==0)return h[r];
    else return 1ll*(h[r]+mod-1ll*h[l-1]*pw[r-l+1]%mod)%mod;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    pw[0]=1;
    for(int i=1;i<=5000000;i++)pw[i]=1ll*pw[i-1]*base%mod;
    scanf("%d%d",&n,&Q);
    for(int i=1,len;i<=n;i++)
    {
        scanf("%s%s",S1,S2);
        len=strlen(S1);
        for(int j=0;j<len;j++)
        {
            s[i].s1.push_back(S1[j]),s[i].h1=(1ll*s[i].h1*base%mod+(S1[j]-'a'))%mod;
            s[i].s2.push_back(S2[j]),s[i].h2=(1ll*s[i].h2*base%mod+(S2[j]-'a'))%mod;
        }
    }
    sort(s+1,s+1+n,cmp);
    while(Q--)
    {
        scanf("%s%s",S1,S2);
        int len=strlen(S1);
        if(strlen(S2)!=len)
        {
            printf("0\n");
        }
        else
        {
            int lcs=0,lcp=0;
            for(int i=0;i<len;i++)
            {
                if(S1[i]==S2[i])lcp=i+1;
                else break;
            }
            for(int i=len-1;i>=0;i--)
            {
                if(S1[i]==S2[i])lcs=len-i;
                else break;
            }
            H1[0]=S1[0]-'a',H2[0]=S2[0]-'a';
            for(int i=1;i<len;i++)
            {
                H1[i]=(1ll*H1[i-1]*base%mod+(S1[i]-'a'))%mod;
                H2[i]=(1ll*H2[i-1]*base%mod+(S2[i]-'a'))%mod;
            }
            long long ans=0;
            for(int i=max(0,len-1-lcs),j=1;i<len;i++)
            {
                int l,r,L,R;
                L=1,R=n+1;
                while(L<R)
                {
                    int mid=L+R>>1;
                    if(s[mid].s1.size()+len-1-i+lcp>=len)R=mid;
                    else L=mid+1;
                }
                l=L;
                L=0,R=n;
                while(L<R)
                {
                    int mid=L+R+1>>1;
                    if(s[mid].s1.size()<=i+1)L=mid;
                    else R=mid-1;
                }
                r=L;
                if(l<=r)
                {
                    for(int j=l;j<=r;j++)
                    {
                        if(sum(H1,i-(int)s[j].s1.size()+1,i)==s[j].h1&&sum(H2,i-(int)s[j].s2.size()+1,i)==s[j].h2)
                        {
                            ans++;
                        }
                    }
                }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}