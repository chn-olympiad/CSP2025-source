#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#define LL long long
using namespace std;
const int N=1e5+10;
struct node
{
    LL a,b,c;
    LL maxn;
}p[N];
LL n;
bool cmpA(node x,node y){
    return x.a>y.a;
}
void solveA(){
    LL ans=0;
    sort(p+1,p+1+n,cmpA);
    for(int i=1;i<=n/2;i++)
        ans+=p[i].a;
    cout<<ans<<'\n';
    return ;
}
bool cmpqa(int x,int y){
    return (p[x].a-p[x].b)>(p[y].a-p[y].b);
}
bool cmpqb(int x,int y){
    return (p[x].b-p[x].a)>(p[y].b-p[y].a);
}
void solveB(){
    LL ans=0;
    vector<int> qa,qb;
    for(int i=1;i<=n;i++){
        if(p[i].a>p[i].b) qa.push_back(i);
        else if(p[i].a<p[i].b) qb.push_back(i);
        else ans+=p[i].a;
    }
    sort(qa.begin(),qa.end(),cmpqa);
    sort(qb.begin(),qb.end(),cmpqb);
    for(int i=0;i<qa.size();i++){
        if(i+1<=n/2) ans+=p[qa[i]].a;
        else ans+=p[qa[i]].b;
    }
    for(int i=0;i<qb.size();i++){
        if(i+1<=n/2) ans+=p[qb[i]].b;
        else ans+=p[qb[i]].a;
    }
    cout<<ans<<'\n';
    return ;
}
bool cmppqa(int x,int y){
    if((p[x].a-max(p[x].b,p[x].c))==(p[y].a-max(p[y].b,p[y].c)))
        return max(p[x].b,p[x].c)<max(p[y].b,p[y].c);
    else return (p[x].a-max(p[x].b,p[x].c))>(p[y].a-max(p[y].b,p[y].c));
}
bool cmppqb(int x,int y){
    if((p[x].b-max(p[x].a,p[x].c))==(p[y].b-max(p[y].a,p[y].c)))
        return max(p[x].a,p[x].c)<max(p[y].a,p[y].c);
    else return (p[x].b-max(p[x].a,p[x].c))>(p[y].b-max(p[y].a,p[y].c));
}
bool cmppqc(int x,int y){
    if((p[x].c-max(p[x].b,p[x].a))==(p[y].c-max(p[y].b,p[y].a)))
        return max(p[x].a,p[x].b)<max(p[y].a,p[y].b);
    else return (p[x].c-max(p[x].b,p[x].a))>(p[y].c-max(p[y].b,p[y].a));
}
void solve(){
    bool flagb=1,flagc=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].a>>p[i].b>>p[i].c;
        if(p[i].b!=0) flagb=0;
        if(p[i].c!=0) flagc=0;
        p[i].maxn=max(max(p[i].a,p[i].b),p[i].c);
    }
    if(flagb&&flagc){
        solveA();
        return ;
    }
    if(flagc){
        solveB();
        return ;
    }
    vector<int> qa,qb,qc;
    for(int i=1;i<=n;i++){
        if(p[i].maxn==p[i].a) qa.push_back(i);
        else if(p[i].maxn==p[i].b) qb.push_back(i);
        else qc.push_back(i);
    }
    sort(qa.begin(),qa.end(),cmppqa);
    sort(qb.begin(),qb.end(),cmppqb);
    sort(qc.begin(),qc.end(),cmppqc);
    LL ans=0;
    for(int i=0;i<qa.size();i++){
        if(i+1<=n/2) ans+=p[qa[i]].a;
        else ans+=max(p[qa[i]].b,p[qa[i]].c);
    }
    for(int i=0;i<qb.size();i++){
        if(i+1<=n/2) ans+=p[qb[i]].b;
        else ans+=max(p[qb[i]].a,p[qb[i]].c);
    }
    for(int i=0;i<qc.size();i++){
        if(i+1<=n/2) ans+=p[qc[i]].c;
        else ans+=max(p[qc[i]].a,p[qc[i]].b);
    }
    cout<<ans<<'\n';
    for(int i=1;i<=n;i++)
        p[i]={0,0,0,0};
    return ;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}