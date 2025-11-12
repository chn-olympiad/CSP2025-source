/*
T2 road.cpp
ZJ-S00219 shicj
56pts~100pts
16:44
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans=LLONG_MAX;
struct Edge{
    int u,v,w;
};
bool cmp(Edge x,Edge y){
    return x.w<y.w;
}
Edge G[2000006];
Edge H[2000006];
int es;
int c[20];
int v[20][200005];
vector<int>fs;
int fa[200005];
string bin(int x){
    string ans="";
    for(int i=1;i<=k;i++){
        if(((x>>(i-1))&1)==1){
            ans+="1";
        }
        else{
            ans+="0";
        }
    }
    return ans;
}
inline Edge makeE(int u,int v,int w){
    Edge tmp;
    tmp.u=u;
    tmp.v=v;
    tmp.w=w;
    return tmp;
}
inline int find(int x){
    if(fa[x]!=x){
        fa[x]=find(fa[x]);
    }
    return fa[x];
}
inline int merge(int x,int y){
    int fx=find(x);
    int fy=find(y);
    if(fx==fy){
        return 0;
    }
    fa[fx]=fy;
    return 1;
}
inline void init(int x){
    for(int i=1;i<=n+k;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        H[i]=G[i];
    }
    es=m;
    for(int i=1;i<=k;i++){
        if(((x>>(i-1))&1)==1){
            for(int j=1;j<=n;j++){
                H[++es]=makeE(n+i,j,v[i][j]);
            }
        }
    }
}
int getsum(int x){
    int tot=0;
    for(int i=1;i<=k;i++){
        if(((x>>(i-1))&1)==1){
            tot+=c[i];
        }
    }
    return tot;
}
int getnum(int x){
    int tot=0;
    for(int i=1;i<=k;i++){
        if(((x>>(i-1))&1)==1){
            tot+=1;
        }
    }
    return tot;
}
bool check(int x){
    for(int i=1;i<=k;i++){
        if((((x>>(i-1))&1)==0)&&c[i]==0){
            return false;
        }
    }
    return true;
}
//int TEST_TOT=0,FIRST_ANS=0;
void solve(int x){
//    TEST_TOT++;
    init(x);
    int num=0,tot=0,xnum=getnum(x);
    sort(H+1,H+es+1,cmp);
    for(int i=1;i<=es;i++){
        if(merge(H[i].u,H[i].v)){
//            cerr<<"Link "<<H[i].u<<"&"<<H[i].v<<" cost "<<H[i].w<<endl;
            num++;
            tot+=H[i].w;
        }
        if(num==n+xnum-1){
            break;
        }
    }
//    if(ans>=getsum(x)+tot){
//        FIRST_ANS=TEST_TOT;
//    }
    ans=min(ans,getsum(x)+tot);
//    cerr<<"solve "<<x<<" ("<<bin(x)<<") "<<getsum(x)<<" "<<tot<<" "<<getsum(x)+tot<<endl;
}
bool cmpfs(int x,int y){
    return getsum(x)<=getsum(y);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    int starti=clock();
	scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&G[i].u,&G[i].v,&G[i].w);
    }
    for(int i=1;i<=k;i++){
        scanf("%lld",&c[i]);
        for(int j=1;j<=n;j++){
            scanf("%lld",&v[i][j]);
        }
    }
    for(int i=0;i<(1<<k);i++){
        if(check(i)){
            fs.push_back(i);
        }
    }
    sort(fs.begin(),fs.end(),cmpfs);
    for(auto i:fs){
        solve(i);
        if(clock()-starti>=0.95*CLOCKS_PER_SEC){
            //rp++
            break;
        }
    }
    printf("%lld\n",ans);
//    cerr<<"Find answer at try #"<<FIRST_ANS<<endl;
	return 0;
}