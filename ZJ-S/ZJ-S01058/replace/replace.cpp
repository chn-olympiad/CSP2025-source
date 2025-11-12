#include<bits/stdc++.h>
using namespace std;
const int sz=5000005,N=200005;
int n,q;
struct acam{
    int tr[sz][27],cnt;
    int in[sz],out[sz],dfncnt=0;
    int fail[sz];
    int insert(char *ch){
        int len=strlen(ch+1);
        int nw=0;
        for(int i=1;i<=len;i++){
            int way=ch[i]-'a';
            if(!tr[nw][way]) tr[nw][way]=++cnt;
            nw=tr[nw][way];
        }
        return nw;
    }
    queue<int> q;
    vector<int> ft[sz];
    void getdfn(int x){
        in[x]=++dfncnt;
        for(int y:ft[x]){
            getdfn(y);
        }
        out[x]=dfncnt;
    }
    void build(){
        // printf("cnt %d\n",cnt);
        for(int i=0;i<26;i++) if(tr[0][i]) q.push(tr[0][i]);
        while(q.size()){
            int u=q.front();q.pop();
            // printf("ADDE %d %d\n",fail[u],u);
            ft[fail[u]].push_back(u);
            for(int i=0;i<26;i++){
                if(tr[u][i]) fail[tr[u][i]]=tr[fail[u]][i],q.push(tr[u][i]);
                else tr[u][i]=tr[fail[u]][i];
            }
        } 
        getdfn(0);
    }
}al,ar;
struct bit{
    #define lowbit(x) ((x)&-(x))
    int V;
    int c[sz];
    void add(int x,int val){
        while(x<=V) c[x]+=val,x+=lowbit(x);
    }
    int query(int x){
        int sum=0;
        while(x) sum+=c[x],x-=lowbit(x);
        return sum;
    }
}bt;
char cl[sz],cr[sz];
int el[N],er[N];
int ans[N];
vector<pair<int,int> > sad[sz];//op pos
vector<pair<int,pair<int,int> > > sq[sz];//op pos id
main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%s",cl+1);
        el[i]=al.insert(cl);
        scanf("%s",cr+1);
        er[i]=ar.insert(cr);
        // printf("EL ER %d %d\n",el[i],er[i]);
        // printf("endof %d\n",i);
    }
    al.build();//puts("BEL");
    ar.build();//puts("BER");
    // puts("afterbuild");
    bt.V=ar.cnt+1;
    for(int i=1;i<=n;i++){
        int ll=al.in[el[i]],lr=al.out[el[i]];
        int rl=ar.in[er[i]],rr=ar.out[er[i]];
        // printf("%d %d %d\n",el[i],ll,lr);
        // printf("%d %d %d\n",er[i],rl,rr);
        sad[ll].push_back({1,rl});sad[ll].push_back({-1,rr+1});
        sad[lr+1].push_back({-1,rl});sad[lr+1].push_back({1,rr+1});
    }
    for(int id=1;id<=q;id++){
        scanf("%s",cl+1);
        scanf("%s",cr+1);
        int len=strlen(cl+1);
        int fl=1,fr=len;
        while(fl<=len&&cl[fl]==cr[fl]) fl++;
        while(fr&&cl[fr]==cr[fr]) fr--;
        int nl=0,nr=0;
        for(int i=1;i<fr;i++){
            nl=al.tr[nl][cl[i]-'a'];
            nr=ar.tr[nr][cr[i]-'a'];
        }
        for(int i=fr;i<=len;i++){
            nl=al.tr[nl][cl[i]-'a'];
            nr=ar.tr[nr][cr[i]-'a'];
            // printf("nl nr %d %d\n",nl,nr);
            // printf("QR %d %d %d 1\n",id,al.in[nl],ar.in[nr]);
            sq[al.in[nl]].push_back({1,{ar.in[nr],id}});
        }
        nl=0,nr=0;
        for(int i=fl+1;i<fr;i++){
            nl=al.tr[nl][cl[i]-'a'];
            nr=ar.tr[nr][cr[i]-'a'];
        }
        for(int i=max(fl+1,fr);i<=len;i++){
            nl=al.tr[nl][cl[i]-'a'];
            nr=ar.tr[nr][cr[i]-'a'];
            // printf("dnl %d %d\n",nl,nr);
            // printf("QR %d %d %d -1\n",id,al.in[nl],ar.in[nr]);
            sq[al.in[nl]].push_back({-1,{ar.in[nr],id}});
        }
    }
    // puts("ED");
    for(int i=1;i<=al.cnt+1;i++){
        for(pair<int,int> nw:sad[i]){
            bt.add(nw.second,nw.first);
            // printf("add %d %d %d\n",i,nw.second,nw.first);
        }
        for(pair<int,pair<int,int> > nw:sq[i]){
            // printf("qr %d %d %d %d %d\n",nw.first,nw.second.second,i,nw.second.first,bt.query(nw.second.first));
            ans[nw.second.second]+=bt.query(nw.second.first)*nw.first;
        }
    }
    for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
}