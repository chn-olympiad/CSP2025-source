#include<cstdio>
#include<map>
#include<utility>
#define N 5000005
int n,q,ln;
unsigned long long hash_base[N],hashs[N],hasht[N],nhs[N],nht[N];
char s[N],t[N];
int len[N],ll1[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    hash_base[0]=1;
    for(int i=1;i<N;i++)hash_base[i]=251*hash_base[i-1];
    scanf("%d%d",&n,&q);
    for(int tt=1;tt<=n;tt++){
        scanf("%s%s",s+1,t+1);
        for(int i=1;s[i];i++)len[tt]=i;
        for(int i=1;i<=len[tt];i++)hashs[tt]=hashs[tt]*251+s[i]-'a';
        for(int i=1;i<=len[tt];i++)hasht[tt]=hasht[tt]*251+t[i]-'a';
        ll1[tt]=1;
        for(int i=len[tt];i;i--)if(s[i]-t[i])ll1[tt]=i;
    }
    for(int tt=1;tt<=q;tt++){
        scanf("%s%s",s+1,t+1);
        int lenn=1,ll11=1,lent=1;
        for(int i=1;s[i];i++)lenn=i;
        for(int i=1;t[i];i++)lent=i;
        if(lenn-lent){puts("0");continue;}//puts("*");
        int cnt=0;
        for(int i=lenn;i;i--)if(s[i]-t[i])ll11=i;
        for(int i=1;i<=lenn;i++)nhs[i]=nhs[i-1]*251+s[i]-'a';
        for(int i=1;i<=lenn;i++)nht[i]=nht[i-1]*251+t[i]-'a';
        for(int i=i;i<=n;i++)if(ll11>=ll1[i]&&len[i]<=lenn-ll11+1){
            int nnhashs=nhs[ll11+len[i]-ll1[i]+1]-hash_base[len[i]]*nhs[ll11-ll1[i]];
            int nnhasht=nht[ll11+len[i]-ll1[i]+1]-hash_base[len[i]]*nht[ll11-ll1[i]];
            if(nnhashs==hashs[i]&&nnhasht==hasht[i])cnt++;
        }
        printf("%d\n",cnt);
    }
}
// #include<cstdio>
// #include<algorithm>
// #include<map>
// #include<vector>
// #include<utility>
// #define N 5000005
// #define S (N*32)
// #define mid (l+r>>1)
// int n,q,ans[N];
// struct _sgt{
//     int root[N],lc[S],rc[S],t[S],cnt;
//     void build(int x){return root[x]=++cnt,void();}
//     void add(int x,int v,int o,int l=1,int r=N-1){
//         t[o]+=v;
//         if(l==r)return;
//         if(x<=mid){
//             if(!lc[o])lc[o]=++cnt;
//             add(x,v,lc[o],l,mid);
//         }
//         else{
//             if(!rc[o])rc[o]=++cnt;
//             add(x,v,rc[o],mid+1,r);
//         }
//     }
//     int qu(int x,int o,int l=1,int r=N-1){
//         if(l==r)return t[o];
//         if(x<=mid&&lc[o])return qu(x,lc[o],l,mid);
//         if(x>mid&&rc[o])return qu(x,rc[o],mid+1,r);
//         return 0;
//     }
//     void mer(int o,int o2,int l=1,int r=N-1){
//         t[o]+=t[o2];
//         if(l==r)return;
//         if(lc[o]&&lc[o2])mer(lc[o],lc[o2],l,mid);
//         else if(lc[o2])lc[o]=lc[o2];
//         if(rc[o]&&rc[o2])mer(rc[o],rc[o2],mid+1,r);
//         else if(rc[o2])rc[o]=rc[o2];
//     }
// }sgt;
// struct _big_trie{
//     int cnt;
//     std::map<int,int>to[N];
//     void init(){cnt=1;}
//     int add(char c1[],char c2[],int ll,int rr,int o=1){
//         if(ll>rr)return o;
//         int xx=1000*c1[ll]+c2[ll];
//         if(!to[o][xx])to[o][xx]=++cnt;
//         return add(c1,c2,ll+1,rr,to[o][xx]);
//     }
//     int qu(char c1[],char c2[],int ll,int rr,int o=1){
//         if(!o)return 0;
//         if(ll>rr)return o;
//         int xx=1000*c1[ll]+c2[ll];
//         return qu(c1,c2,ll+1,rr,to[o][xx]);
//     }
// }bt;
// std::vector<int>cur;
// struct _triel{
//     int root[N],to[N][26],cnt;
//     int init(int x){
//         if(!root[x])root[x]=++cnt;
//         return cnt;
//     }
//     int add(char c[],int ll,int rr,int o){
//         if(ll>rr)return o;
//         int xx=c[rr]-'a';
//         if(!to[o][xx])to[o][xx]=++cnt;
//         return add(c,ll,rr-1,to[o][xx]);
//     }
//     void qu(char c[],int ll,int rr,int o){
//         if(!o)return;
//         cur.push_back(o);
//         if(ll>rr)return;
//         int xx=c[rr]-'a';
//         qu(c,ll,rr-1,to[o][xx]);
//     }
// }triel;
// struct _trier{
//     int root[N],to[N][26],cnt,p[N];
//     std::vector<int>jia[N];
//     std::vector<std::pair<int,int> >adda[N],dela[N];
//     int init(int x){
//         if(!root[x])root[x]=++cnt;
//         return cnt;
//     }
//     void add(char c[],int v,int ll,int rr,int o){
//         if(ll>rr)return jia[o].push_back(v),void();
//         int xx=c[ll]-'a';
//         if(!to[o][xx])to[o][xx]=++cnt,p[cnt]=o;
//         add(c,v,ll+1,rr,to[o][xx]);
//     }
//     void qu(char c[],int x,int ll,int rr,int o){
//         if(ll>rr){
//             for(int i:cur)dela[o].push_back({x,i});
//             return;
//         }
//         int xx=c[ll]-'a';
//         if(to[o][xx])qu(c,x,ll+1,rr,to[o][xx]);
//         else for(int i:cur)dela[o].push_back({x,i});
//     }
//     void qu_(char c[],int x,int ll,int rr,int o){
//         for(int i:cur)adda[o].push_back({x,i});
//         qu(c,x,ll,rr,o);
//         cur.clear();
//     }
//     void duel(){
//         for(int i=1;i<=cnt;i++)sgt.build(i);
//         for(int i=cnt;i;i--){
//             for(std::pair<int,int>j:dela[i])ans[j.first]-=sgt.qu(j.second,sgt.root[i]);
//             for(int j:jia[i])sgt.add(j,1,sgt.root[i]);
//             if(p[i])sgt.mer(sgt.root[p[i]],sgt.root[i]);
//             else for(std::pair<int,int>j:adda[i])ans[j.first]+=sgt.qu(j.second,sgt.root[i]);
//         }
//     }
// }trier;
// char c[N],s[N],len1,len2;
// int main(){
//     bt.init();
//     scanf("%d%d",&n,&q);
//     for(int i=1;i<=n;i++){
//         scanf("%s%s",c+1,s+1);
//         int ll=1e9,rr=-1;
//         for(int j=1;c[j];j++)len1=j;
//         for(int j=1;j<=len1;j++)if(c[j]-s[j])rr=j;
//         for(int j=len1;j;j--)if(c[j]-s[j])ll=j;
//         if(ll>rr)continue;
//         int x=bt.add(c,s,ll,rr);
//         int y=triel.init(x);triel.add(c,1,ll-1,y);
//         int z=trier.init(y);trier.add(c,1,rr+1,len1,z);
//     }
//     for(int i=1;i<=q;i++){
//         scanf("%s%s",c+1,s+1);
//         int ll=1e9,rr=-1;
//         for(int j=1;c[j];j++)len1=j;
//         for(int j=1;s[j];j++)len2=j;
//         if(len1-len2)continue;
//         for(int j=1;j<=len1;j++)if(c[j]-s[j])rr=j;
//         for(int j=len1;j;j--)if(c[j]-s[j])ll=j;
//         int x=bt.qu(c,s,ll,rr);
//         if(!x)continue;
//         int y=triel.root[x];
//         if(y)triel.qu(c,1,ll-1,y);
//         int z=trier.root[x];
//         if(z)trier.qu(c,i,rr+1,len1,z);
//     }
//     trier.duel();
//     for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
// }