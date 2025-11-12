#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=2e12+9867,bs=125;
const int N=2e5+500,Q=2e5+500,L=5e6+500,A=26;
int n,q,hct;
struct mhsh{ll v;int ln;}hs[N],hi[N];
bool operator==(mhsh a,mhsh b){return a.v==b.v&&a.ln==b.ln;}
bool operator<(mhsh a,mhsh b){return a.v==b.v?a.ln<b.ln:a.v<b.v;}
struct item{string s;int c;}a[N],b[Q];
string s1,s2;
void dvd(item&a,mhsh&hs){
    int sp=L,ed=-1;
    for(int j=0;j<s1.size();j++)
        if(s1[j]!=s2[j])sp=min(sp,j),ed=max(ed,j);
    if(ed<0)hs={mod,-1};
    else{
        for(int i=0;i<sp;i++)a.s+=s1[i];
        for(int i=ed+1;i<s1.size();i++)a.s+=s1[i],a.c++;
        hs={0,(ed-sp+1)*2};
        for(int j=sp;j<=ed;j++)
            hs.v=(hs.v*bs+(s1[j]-'a'+1))%mod;
        for(int j=sp;j<=ed;j++)
            hs.v=(hs.v*bs+(s2[j]-'a'+1))%mod;
    }
}
ll ans[Q];
vector<int>sa[N],sb[N];

int tct,fl[L],ch[L][A],dct,dfn[L],siz[L];
vector<int>cl[L],g[L];
void dfs(int u){
    dfn[u]=++dct,siz[u]=1;
    for(int v:g[u])dfs(v),siz[u]+=siz[v];
}
struct node{int c,i;};
vector<node>md[L],qy[L];
ll tg[L];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2,dvd(a[i],hs[i]);
        // cerr<<i<<":"<<hs[i].v<<' '<<hs[i].ln<<'|'
        //     <<a[i].s<<' '<<a[i].c<<'\n';
        if(hs[i].ln!=-1)hi[++hct]=hs[i];
    }
    sort(hi+1,hi+hct+1),hct=unique(hi+1,hi+hct+1)-hi-1;
    for(int i=1,id;i<=n;i++)if(hs[i].ln!=-1){
        id=lower_bound(hi+1,hi+hct+1,hs[i])-hi;
        sa[id].push_back(i);
        // if(i==3512)cerr<<id<<'\n';
    }
    for(int i=1,id;i<=q;i++){
        cin>>s1>>s2;
        // if(i==461)cerr<<s1<<' '<<s2<<'\n';
        if(s1.size()!=s2.size()){
            // if(i==461){
            //     cerr<<"f1\n";
            // }
            continue;
        }
        mhsh hs;dvd(b[i],hs);
        // cerr<<i<<":"<<hs.v<<' '<<hs.ln<<'|'
        //     <<b[i].s<<' '<<b[i].c<<'\n';
        id=lower_bound(hi+1,hi+hct+1,hs)-hi;
        // if(i==461)cerr<<id<<'\n';
        if(!(hi[id]==hs)){
            // if(i==461){
            //     cerr<<"f2\n";
            // }
            continue;
        }
        // cerr<<"push:"<<i<<' '<<id<<'\n';
        sb[id].push_back(i);
    }
    for(int id=1;id<=hct;id++)if(sb[id].size()){
        memset(fl,0,(tct+5)  *sizeof(int));
        memset(dfn,0,(tct+5) *sizeof(int));
        memset(siz,0,(tct+5) *sizeof(int));
        memset(ch,0,(tct+5)*A*sizeof(int));
        for(int i=0;i<tct+5;i++){
            md[i].clear(),md[i].shrink_to_fit();
            qy[i].clear(),qy[i].shrink_to_fit();
        }
        tct=1,dct=0;
        for(int ai:sa[id]){
            // if(id==126){
            //     cerr<<a[ai].s<<' '<<a[ai].c<<'\n';
            // }
            int u=1;
            for(char c:a[ai].s){
                if(!ch[u][c-='a'])
                    ch[u][c]=++tct;
                u=ch[u][c];
            }cl[u].push_back(a[ai].c);
        }
        // for(int i=0;i<=tct;i++){
        //     cerr<<i<<":";
        //     for(int j=0;j<A;j++)if(ch[i][j]){
        //         cerr<<"{"<<((char)('a'+j))<<','<<ch[i][j]<<"} ";
        //     }cerr<<'\n';
        // }
        queue<int>q;fl[1]=1;
        for(int i=0;i<A;i++){
            if(ch[1][i]){
                q.push(ch[1][i]);
                fl[ch[1][i]]=1;
            }else ch[1][i]=1;
        }
        while(q.size()){
            int u=q.front();q.pop();
            for(int i=0;i<A;i++)
                if(ch[u][i]){
                    fl[ch[u][i]]=ch[fl[u]][i];
                    q.push(ch[u][i]);
                }else ch[u][i]=ch[fl[u]][i];
        }
        // for(int i=0;i<=tct;i++)
        //     cerr<<"fl "<<i<<":"<<fl[i]<<"\n";
        for(int i=2;i<=tct;i++)
            g[fl[i]].push_back(i);
        dfs(1);
        // cerr<<tct<<' '<<dct<<'\n';
        for(int i=0;i<tct+5;i++){
            g[i].clear(),g[i].shrink_to_fit();
        }
        for(int i=1;i<=tct;i++){
            for(int c:cl[i]){
                md[dfn[i]].push_back({c,1});
                md[dfn[i]+siz[i]].push_back({c,-1});
            }cl[i].clear(),cl[i].shrink_to_fit();
        }
        int mx=0;
        for(int bi:sb[id]){
            int u=1;
            if(b[bi].s.size()<=b[bi].c)
                qy[dfn[u]].push_back({b[bi].c-b[bi].s.size(),bi});
            mx=max(mx,(int)(b[bi].s.size()));
            for(int i=0,c,ln;i<b[bi].s.size();i++){
                c=b[bi].s[i]-'a';
                // cerr<<u<<' '<<((char)(c+'a'))<<' '<<ch[u][c]<<'\n';
                // assert(ch[u][c]);
                u=ch[u][c],ln=b[bi].s.size()-i-1;
                if(ln<=b[bi].c){
                    qy[dfn[u]].push_back({b[bi].c-ln,bi});
                }
            }
        }
        // assert(dct==tct);
        memset(tg,0,(mx+5)*sizeof(ll));
        for(int i=1;i<=tct;i++){
            for(node op:md[i])tg[op.c]+=op.i;
            for(node op:qy[i])ans[op.i]+=tg[op.c];
        }
    }
    for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}