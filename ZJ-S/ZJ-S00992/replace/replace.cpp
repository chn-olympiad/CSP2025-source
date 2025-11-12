#include<bits/stdc++.h>
using namespace std;
int n,m,tot=1;
bitset<680> b[2500010];
vector<pair<int,int> > tree[2500010];
char s[5000010],t[5000010];
int a[5000010];
int get_son(int u,int v)
{
    return (*lower_bound(tree[u].begin(),tree[u].end(),make_pair(v,0))).second;
}
int dep[2500010],sum[2500010];
int ins(int* a,int n)
{
    int nowpos=1;
    for(int i=1;i<=n;i++)
    {
        if(!b[nowpos][a[i]])
        {
            tree[nowpos].push_back(make_pair(a[i],++tot));
            int p=tree[nowpos].size()-1;
            while(p>0&&tree[nowpos][p]<tree[nowpos][p-1]) swap(tree[nowpos][p],tree[nowpos][p-1]),p--;
            b[nowpos][a[i]]=1,nowpos=tot;
        }
        else nowpos=get_son(nowpos,a[i]);
        dep[nowpos]=i;
    }
    // printf("nowpos:%d\n",nowpos);
    return nowpos;
}
queue<int> q;
int fail[2500010];
void build_AC()
{
    fail[1]=1;
    for(int i=0;i<tree[1].size();i++) fail[tree[1][i].second]=1,q.push(tree[1][i].second);
    while(!q.empty())
    {
        int u=q.front();
        q.pop(),sum[u]+=sum[fail[u]];
        // printf("u:%d %d\n",u,fail[u]);
        for(int i=0;i<tree[u].size();i++)
        {
            int now=fail[u];
            while(now!=1&&!b[now][tree[u][i].first]) now=fail[now];
            if(b[now][tree[u][i].first]) fail[tree[u][i].second]=get_son(now,tree[u][i].first);
            else fail[tree[u][i].second]=1;
            q.push(tree[u][i].second);
        }
    }
    return ;
}
int fa[24][2500010];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int len;
        scanf("%s",s+1),len=strlen(s+1);
        for(int j=1;j<=len;j++) a[j]=(s[j]-'a')*26;
        scanf("%s",s+1),len=strlen(s+1);
        for(int j=1;j<=len;j++) a[j]+=s[j]-'a';
        sum[ins(a,len)]++;
        // for(int i=1;i<=len;i++) printf("%d ",a[i]);
        // printf("\n");
    }
    build_AC();
    // printf("%d\n",fail[5]);
    for(int i=1;i<=tot;i++) fa[0][i]=fail[i];
    for(int i=1;i<=__lg(tot);i++) for(int j=1;j<=tot;j++) fa[i][j]=fa[i-1][fa[i-1][j]];
    for(int i=1;i<=m;i++)
    {
        int len;
        scanf("%s%s",s+1,t+1);
        if((len=strlen(s+1))!=strlen(t+1))
        {
            printf("0\n");
            continue;
        }
        for(int i=1;i<=len;i++) a[i]=(s[i]-'a')*26+t[i]-'a';
        int l=1,r=len;
        while(l<=len&&s[l]==t[l]) l++;
        while(r&&s[r]==t[r]) r--;
        int nowpos=1;
        long long ans=0;
        for(int i=1;i<=len;i++)
        {
            while(nowpos!=1&&!b[nowpos][a[i]]) nowpos=fail[nowpos];
            if(b[nowpos][a[i]]) nowpos=get_son(nowpos,a[i]);
            if(i>=r)
            {
                // i-dep+1<=l
                // i-l+1<=dep
                if(i-l+1>dep[nowpos]) continue;
                ans+=sum[nowpos];
                int tmp=nowpos;
                for(int j=__lg(dep[tmp]+1);j>=0;j--) if(i-l+1<=dep[fa[j][tmp]]) tmp=fa[j][tmp];
                // printf("%d %d\n",tmp,dep[tmp]);
                tmp=fa[0][tmp];
                ans-=sum[tmp];
            }
            // printf("%d %d %lld\n",a[i],nowpos,ans);
            // for(int i=0;i<tree[nowpos].size();i++) printf("%d ",tree[nowpos][i].second);
            // printf("\n");
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*
2 1
11
1 1
*/