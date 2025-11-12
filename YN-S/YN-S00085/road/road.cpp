//by haotian,sun
//面积luogu联系 @fkxr(uid=995934)
#include<bits/stdc++.h>
#define endl cerr<<"I love Olympiad in Informatics!\n"
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#ifdef __linux__
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc getchar
#define pc putchar
#endif
namespace FastIO{
    void r(int &a){
        a=0;bool ok=0;char ch=gc();
        for(;ch>'9'||ch<'0';ch=gc())ok^=(ch=='-');
        for(;ch>='0'&&ch<='9';ch=gc())
            a=(a<<3)+(a<<1)+ch-'0';
        if(ok)a=-a;
    }
    void w(int a){
        if(a==0){pc('0');return;}
        int till=0;char ch[25];
        if(a<0){
            pc('-');
            for(;a;a/=10)ch[till++]=-(a%10);
        }else for(;a;a/=10)ch[till++]=a%10;
        for(;till;)pc(ch[--till]+'0');
    }
    struct FIstream{
        FIstream operator>>(int &x){r(x);return {};}
    }in;
    struct FOstream{
        FOstream operator<<(int x){w(x);return {};}
        FOstream operator<<(char ch){pc(ch);return {};}
        FOstream operator<<(string s){for(auto ch:s)pc(ch);return {};}
    }out;
}using FastIO::in;using FastIO::out;
namespace code{
    void Freopen(string s){
        freopen((s+".in").c_str(),"r",stdin);
        freopen((s+".out").c_str(),"w",stdout);
    }
    struct node{
        int u,v,w;
        friend bool operator<(node a,node b){
            return a.w<b.w;
        }
    };
    int fa[10050];
    int find(int x){
        return fa[x]==x?x:fa[x]=fa[fa[x]]=fa[fa[fa[x]]]=find(fa[fa[fa[x]]]);
    }
#define reset for(int i=1;i<=n+15;i++)fa[i]=i
    vector<node>g,e;int n,m,k;
    int ans=0;
    vector<node>a[15];
    int c[15];
    void dfs(int x,int cnt,vector<node>e,int ansnw){
        if(x==k){
            reset;
            for(auto i:e){
                if(find(i.u)!=find(i.v)){
                    ansnw+=i.w,--cnt;
                    fa[fa[i.u]]=i.v;
                }
                if(!cnt)break;
            }
            ans=min(ans,ansnw);
            return;
        }
        dfs(x+1,cnt,e,ansnw);
        vector<node>tmp;
        int lst=0;
        for(auto i:a[x]){
            for(;lst<e.size()&&e[lst]<i;++lst)
                tmp.push_back(e[lst]);
            tmp.push_back(i);
        }
        for(;lst<e.size();++lst)tmp.push_back(e[lst]);
        dfs(x+1,cnt+1,tmp,ansnw+c[x]);
    }
    void Main(){
        Freopen("road");
        //auto timea=clock();
        in>>n>>m>>k;
        for(int i=1;i<=m;i++){
            int x,y,z;in>>x>>y>>z;
            g.push_back({x,y,z});
        }
        sort(all(g));reset;
        int cnt=0;
        for(auto i:g){
            if(find(i.u)!=find(i.v)){
                ans+=i.w,++cnt,
                fa[fa[i.u]]=i.v,
                e.push_back(i);
                if(cnt==n-1)break;
            }
        }
        //kelusikaer
        /*priority_queue<pair<int,pair<int,int>>>q;
        q.push({0,{1,-1}});memset(dis,0x3f,sizeof(dis));
        dis[1]=0;
        for(;!q.empty();){
            auto t=q.top();q.pop();
            int x=t.second.first,frm=t.second.second;
            if(dis[x]!=-t.first)continue;
            if(frm!=-1)e.push_back(g[frm]);
            for(auto i:es[x]){
                assert(i<m);
                int v=(g[i].u^g[i].v^x),w=g[i].w;
                if(dis[v]>dis[x]+w){
                    dis[v]=dis[x]+w;
                    q.push({-dis[v],{v,i}});
                }
            }
        }*/
        /*for(int i=1;i<=n;i++)out<<find(i)<<" ";
        endl;*/
        //out<<ans<<"\n";endl;
        for(int i=0;i<k;i++){
            in>>c[i];
            for(int j=1;j<=n;j++){
                int x;in>>x;
                a[i].push_back({j,n+i+1,x});
            }
            sort(all(a[i]));
        }
        //cerr<<clock()-timea<<"\n";
        dfs(0,n-1,e,0);
        out<<ans<<"\n";
        //cerr<<clock()-timea<<"\n";
    }
}
signed main(){
    code::Main();
    return 0;
}