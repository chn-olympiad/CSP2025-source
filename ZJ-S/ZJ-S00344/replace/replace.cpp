#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,ULL>PIL;
typedef pair<int,int>PII;
const int N=2e5+5;
const int M=5e6+5;
const int base1=131;
const int base2=1331;
const int mod=1e9+7;
const int B=5e6;
int n,m;
char s1[M],s2[M];
int len[N];
vector<PIL>h1[N],h2[N];
PIL q1[M],q2[M];
LL pw1[M],pw2[M];
char t1[M],t2[M];
int cnt;
PIL get(int l,int r,vector<PIL>&h){
    return make_pair((h[r].first-h[l-1].first*pw1[r-l+1]%mod+mod)%mod,
                        (h[r].second-h[l-1].second*pw2[r-l+1]%mod+mod)%mod);
}
PIL get(int l,int r,PIL h[]){
    return make_pair((h[r].first-h[l-1].first*pw1[r-l+1]%mod+mod)%mod,
                        (h[r].second-h[l-1].second*pw2[r-l+1]%mod+mod)%mod);
}
void calc(){
    scanf("%s%s",t1+1,t2+1);
    int L=0,R=0;
    int Len=strlen(t1+1);
    for(int i=Len;i;i--) if(t1[i]!=t2[i]) L=i;
    for(int i=1;i<=Len;i++) if(t1[i]!=t2[i]) R=i;
    PIL w1=make_pair(0,0),w2=make_pair(0,0);
    for(int i=L;i<=R;i++){
        w1=make_pair((w1.first*base1+t1[i])%mod,(w1.second*base2+t1[i])%mod);
        w2=make_pair((w2.first*base1+t2[i])%mod,(w2.second*base2+t2[i])%mod);
    }
    for(int i=1;i<=Len;i++){
        q1[i]=make_pair((q1[i-1].first*base1+t1[i])%mod,(q1[i-1].second*base2+t1[i])%mod);
        q2[i]=make_pair((q2[i-1].first*base1+t2[i])%mod,(q2[i-1].second*base2+t2[i])%mod);
    }
    // cerr<<"("<<Len<<endl;
    int Ln=R-L+1;
    // cerr<<"!"<<L<<" "<<R<<endl;
    // cerr<<"#"<<w1<<" "<<w2<<endl;
    // cerr<<"$"<<get(1,2,h1[3])<<" "<<get(1,2,h2[3])<<endl;
    // cerr<<q1[Len]<<" "<<h1[i].back()<<endl;
    int ans=0;
    // Case++;
    // if(Case==101){

    for(int i=1;i<=n;i++)
        for(int j=1;j<=len[i]-Ln+1;j++)
            if(get(j,j+Ln-1,h1[i])==w1 && get(j,j+Ln-1,h2[i])==w2){
                // cerr<<"@"<<i<<" "<<j<<endl;
                int ql=L-j+1,qr=R+len[i]-(j+Ln-1);
                if(ql>=1 && qr<=Len){
                    // cerr<<"$"<<ql<<" "<<qr<<endl;
                    // cerr<<"@"<<get(ql,qr,q1)<<"  "<<h1[i][len[i]]<<endl;
                    if(get(ql,qr,q1)==h1[i][len[i]] && get(ql,qr,q2)==h2[i][len[i]])
                        ans++;
                }
            }
    printf("%d\n",ans);

    // }
    // if(Case==101) exit(0);
    return;
}
struct Node{
    int l,r,id;
};
vector<Node>v[M*2];
int cmp(Node x,Node y){
    if(x.l!=y.l) return x.l<y.l;
    return x.id<y.id;
}
int tr[M];
int lowbit(int x){
    return x&(-x);
}
void add(int x,int s){
    // cerr<<x<<endl;
    x++;
    for(int i=x;i<=B;i+=lowbit(i))
        tr[i]+=s;
    return;
}
int query(int x){
    x++;
    int res=0;
    for(int i=x;i;i-=lowbit(i)) res+=tr[i];
    return res;
}
namespace stk{
    int ans[N];
    void main(){
        for(int id=1;id<=m;id++){
            scanf("%s%s",t1+1,t2+1);
            int L=0,R=0;
            int Len=strlen(t1+1);
            for(int j=1;j<=Len;j++) if(t1[j]=='b') L=j;
            for(int j=1;j<=Len;j++) if(t2[j]=='b') R=j;
            // cerr<<L<<" "<<R<<endl;
            v[R-L+B].push_back({min(L,R)-1,Len-max(L,R),id});
        }
        // cerr<<"@"<<endl;
        for(int id=1;id<=2*B;id++){
            if(!v[id].size()) continue;
            sort(v[id].begin(),v[id].end(),cmp);
            // cerr<<id<<endl;
            int si=v[id].size();
            for(int i=0;i<si;i++){
                if(v[id][i].id==0) add(v[id][i].r,1);
                else ans[v[id][i].id]+=query(v[id][i].r);
            }
            for(int i=0;i<si;i++)
                if(v[id][i].id==0)
                    add(v[id][i].r,-1);
        }
        // cerr<<"!"<<m<<endl;
        for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
        return;
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&m);
    pw1[0]=pw2[0]=1;
    for(int i=1;i<M;i++){
        pw1[i]=pw1[i-1]*base1%mod;
        pw2[i]=pw2[i-1]*base2%mod;
    }
    for(int i=1;i<=n;i++){
        scanf("%s%s",s1+1,s2+1);
        len[i]=strlen(s1+1);
        h1[i].resize(len[i]+2);
        h2[i].resize(len[i]+2);
        h1[i][0]=h2[i][0]=make_pair(0,0);
        for(int j=1;j<=len[i];j++)
            h1[i][j]=make_pair(((h1[i][j-1].first*base1+s1[j])%mod),((h1[i][j-1].second*base2+s1[j])%mod));
        for(int j=1;j<=len[i];j++)
            h2[i][j]=make_pair(((h2[i][j-1].first*base1+s2[j])%mod),((h2[i][j-1].second*base2+s2[j])%mod));
        cnt+=len[i];
        int L=0,R=0;
        for(int j=1;j<=len[i];j++) if(s1[j]=='b') L=j;
        for(int j=1;j<=len[i];j++) if(s2[j]=='b') R=j;
        // cerr<<L<<" "<<R<<endl;
        // cerr<<n-max(L,R)<<endl;
        v[R-L+B].push_back({min(L,R)-1,len[i]-max(L,R),0});
    }
    // cerr<<m<<" "<<cnt<<endl;
    if((LL)m*cnt<=2e6){
        while(m--) calc();
    }
    else{
        // cerr<<"!"<<endl;
        stk::main();
    }
    return 0;
}//g++ replace.cpp -o a -O2

/*
2 2
aba aab
aab aba
aabaa aaaba
abaaa aaaab
*/