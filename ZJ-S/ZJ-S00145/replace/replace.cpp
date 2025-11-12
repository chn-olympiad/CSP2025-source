#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
const int maxL=5200005;
int read(){
    int ret=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
    while( isdigit(ch)){ret=(ret<<3)+(ret<<1)+(ch&15);ch=getchar();}
    return ret*f;
}
int n,q;
int ans[maxn];
namespace Tree1{
    int tot;
    int tree[maxL][26],res[maxL];
    void add(char s[],int len){
        int now=0;
        for(int i=1;i<=len;++i){
            if(!tree[now][s[i]-'a']) tree[now][s[i]-'a']=++tot;
            now=tree[now][s[i]-'a'];
        }
        res[now]++;
    }
    void del(char s[],int len){
        int now=0;
        for(int i=1;i<=len;++i){
            if(!tree[now][s[i]-'a']) tree[now][s[i]-'a']=++tot;
            now=tree[now][s[i]-'a'];
        }
        res[now]--;
    }
    int query(char s[],int len){
        int now=0,ans=res[0];
        for(int i=1;i<=len;++i){
            if(!tree[now][s[i]-'a']) return ans;
            now=tree[now][s[i]-'a'];
            ans+=res[now];
        }
        return ans;
    }
}
int cnt;
char tmp[maxL],S1[maxL],S2[maxL],T1[maxL],T2[maxL];
char s1[maxL],s2[maxL],t1[maxL],t2[maxL];
int l[maxn],r[maxn],stS[maxn],edS[maxn],rt[maxn],stT[maxn],edT[maxn],L[maxn],R[maxn];
map<pair<pair<int,int>,pair<int,int>>,int> mp;
namespace Tree2{
    int tot;
    int tree[maxL][26],rtt[maxL];
    vector<int> Q[maxL],I[maxL];
    void add(int rt,char s[],int len,int id){
        int now=rt;
        for(int i=1;i<=len;++i){
            if(!tree[now][s[i]-'a']) tree[now][s[i]-'a']=++tot;
            now=tree[now][s[i]-'a'];
        }
        I[now].emplace_back(id);
        return ;
    }
    void adq(int rt,char s[],int len,int id){
        int now=rt;
        for(int i=1;i<=len;++i){
            if(!tree[now][s[i]-'a']){
                Q[now].emplace_back(id);
                return ;
            }
            now=tree[now][s[i]-'a'];
        }
        Q[now].emplace_back(id);
        return ;
    }
    void solve(int rt){
        for(int i:I[rt]) Tree1::add(S1+stS[i]+r[i]-1,edS[i]-stS[i]+1-r[i]);
        for(int i:Q[rt]){
            ans[i]=Tree1::query(T1+stT[i]+R[i]-1,edT[i]-stT[i]+1-R[i]);
        }
        for(int c=0;c<=25;++c){
            if(tree[rt][c]){
                solve(tree[rt][c]);
            }
        }
        for(int i:I[rt]) Tree1::del(S1+stS[i]+r[i]-1,edS[i]-stS[i]+1-r[i]);
    }
}
namespace Hash{
    const int B1=131,T1=998244353;
    const int B2=133,T2=1000000007;
    pair<int,int> calc(char s[],int l,int r){
        int res1=0,res2=0;
        for(int i=l;i<=r;++i){
            res1=(1ll*res1*B1+s[i])%T1;
            res2=(1ll*res2*B2+s[i])%T2;
        }
        return make_pair(res1,res2);
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    n=read(),q=read();
    for(int i=1;i<=n;++i){
        scanf("%s",s1+1);scanf("%s",s2+1);
        int len=strlen(s1+1);
        stS[i]=edS[i-1]+1;edS[i]=stS[i]+len-1;
        for(int t=1;t<=len;++t){
            if(s1[t]!=s2[t]){
                l[i]=t;
                break;
            }
        }
        for(int t=len;t>=1;--t){
            if(s1[t]!=s2[t]){
                r[i]=t;
                break;
            }
        }
        auto v1=Hash::calc(s1,l[i],r[i]),v2=Hash::calc(s2,l[i],r[i]);
        auto v=make_pair(v1,v2);
        if(!mp[v]){
            mp[v]=++cnt;
            rt[cnt]=++Tree2::tot;
        }
        int id=mp[v];
        for(int t=1;t<l[i];++t) tmp[t]=s1[l[i]-t];
        Tree2::add(rt[id],tmp,l[i]-1,i);
        for(int t=1;t<=len;++t) S1[edS[i-1]+t]=s1[t];
        for(int t=1;t<=len;++t) S2[edS[i-1]+t]=s2[t];
    }
    for(int i=1;i<=q;++i){
        scanf("%s",t1+1);scanf("%s",t2+1);
        if(strlen(t1+1)!=strlen(t2+1)){
            edT[i]=edT[i-1];
            stT[i]=stT[i-1];
            continue;
        }
        int len=strlen(t1+1);
        stT[i]=edT[i-1]+1;edT[i]=stT[i]+len-1;
        for(int t=1;t<=len;++t){
            if(t1[t]!=t2[t]){
                L[i]=t;
                break;
            }
        }
        for(int t=len;t>=1;--t){
            if(t1[t]!=t2[t]){
                R[i]=t;
                break;
            }
        }
        auto v1=Hash::calc(t1,L[i],R[i]),v2=Hash::calc(t2,L[i],R[i]);
        auto v=make_pair(v1,v2);
        int id=mp[v];
        if(!id) continue;
        for(int t=1;t<L[i];++t) tmp[t]=t1[L[i]-t];
        Tree2::adq(rt[id],tmp,L[i]-1,i);
        for(int t=1;t<=len;++t) T1[edT[i-1]+t]=t1[t];
        for(int t=1;t<=len;++t) T2[edT[i-1]+t]=t2[t];
    }
    for(int i=1;i<=cnt;++i) Tree2::solve(rt[i]);
    for(int i=1;i<=q;++i){
        printf("%d\n",ans[i]);
    }
    return 0;
}