#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL p1=1e9+7,p2=1e9+9,bs=31;
const int N=5000005,L=400005;
int n,q,st[L],ed[L],cn,tr[N][26],cnt,po1[L],po2[L],dfc,in[N],ot[N],an[L],f[N];LL li[L],hs[L];string s1[L],s2[L];
vector<int>vc[L];
int ad[N],de[N],qu[N],nx[L*2],to[L*2],sm;
void add(int x,int y){for(;x<=dfc;x+=x&-x)f[x]+=y;}
int qr(int x){int y=0;for(;x;x-=x&-x)y+=f[x];return y;}
void dfs(int x){
    in[x]=++dfc;
    for(int i=0;i<26;++i)if(tr[x][i])dfs(tr[x][i]);
    ot[x]=dfc;
}
inline void insad(int x,int y){nx[++sm]=ad[x];ad[x]=sm;to[sm]=y;}
inline void insde(int x,int y){nx[++sm]=de[x];de[x]=sm;to[sm]=y;}
inline void insqu(int x,int y){nx[++sm]=qu[x];qu[x]=sm;to[sm]=y;}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);cin>>n>>q;
    for(int i=1;i<=n+q;++i){
        cin>>s1[i]>>s2[i];
        if(s1[i]!=s2[i]){
            for(int j=0;j<s1[i].size();++j)if(s1[i][j]!=s2[i][j]){st[i]=j;break;}
            for(int j=s1[i].size()-1;j>=0;--j)if(s1[i][j]!=s2[i][j]){ed[i]=j;break;}
            LL u=0,v=0;
            for(int j=st[i];j<=ed[i];++j){
                u=(u*bs+s1[i][j]-'a'+1)%p1;u=(u*bs+s2[i][j]-'a'+1)%p1;
                v=(v*bs+s1[i][j]-'a'+1)%p2;v=(v*bs+s2[i][j]-'a'+1)%p2;
            }
            hs[i]=u*p2+v;li[++cn]=hs[i];
        }
    }
    sort(li+1,li+1+cn);cn=unique(li+1,li+1+cn)-li-1;
    for(int i=1;i<=n+q;++i)if(s1[i]!=s2[i])vc[lower_bound(li+1,li+1+cn,hs[i])-li].push_back(i);
    for(int i=1;i<=cn;++i){
        cnt=1;
        for(auto j:vc[i]){
            int nw=1;
            for(int u=st[j]-1;u>=0;--u){
                int o=s1[j][u]-'a';
                if(!tr[nw][o])tr[nw][o]=++cnt;
                nw=tr[nw][o];
            }
            po1[j]=nw;
            nw=1;
            for(int u=ed[j]+1;u<s1[j].size();++u){
                int o=s1[j][u]-'a';
                if(!tr[nw][o])tr[nw][o]=++cnt;
                nw=tr[nw][o];
            }
            po2[j]=nw;
        }
        dfc=0;dfs(1);
        for(auto j:vc[i])if(j<=n)insad(in[po1[j]],po2[j]),insde(ot[po1[j]],po2[j]);
        else insqu(in[po1[j]],j);
        for(int j=1;j<=dfc;++j){
            for(int o=ad[j],k;o;o=nx[o]){k=to[o],add(in[k],1);if(ot[k]<dfc)add(ot[k]+1,-1);}
            for(int o=qu[j],k;o;o=nx[o])k=to[o],an[k-n]=qr(in[po2[k]]);
            for(int o=de[j],k;o;o=nx[o]){k=to[o],add(in[k],-1);if(ot[k]<dfc)add(ot[k]+1,1);}
        }
        for(int j=1;j<=cnt;++j)memset(tr[j],0,sizeof(tr[j]));cnt=0;
        for(int j=1;j<=dfc;++j)f[j]=ad[j]=de[j]=qu[j]=0;sm=0;
    }
    for(int i=1;i<=q;++i)cout<<an[i]<<endl;
    return 0;
}