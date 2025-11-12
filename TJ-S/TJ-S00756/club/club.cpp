#include<bits/stdc++.h>
using namespace std;
namespace Main{
namespace Brute{
using lnt=long long;
const int N=210;const lnt INF=0x3f3f3f3f3f3f3f3f;
int T,n,lim;lnt seq[N][3],dp[N][N][N],hasmem[N][N][N];
vector<int>choose[N][N][N];
void init(){
    for(int i=0;i<=n;i++){
        for(int a=0;a<=n;a++){
            for(int b=0;b<=n;b++){
                hasmem[i][a][b]=false;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++)
            scanf("%d",&seq[i][j]);
    }lim=n>>1;
}
lnt get(int i,int a,int b){
    int c=i-a-b;
    if(a>lim || b>lim || c>lim)return -INF;
    if(i>n){return 0;}
    if(hasmem[i][a][b])return dp[i][a][b];
    dp[i][a][b]=max({get(i+1,a+1,b)+seq[i][0],get(i+1,a,b+1)+seq[i][1],get(i+1,a,b)+seq[i][2]});
    hasmem[i][a][b]=true;return dp[i][a][b];
}
void main(int rd){
    n=rd;//cerr<<clock()<<'\n';
    init();
    printf("%lld\n",get(0,0,0));
    //cerr<<clock()<<'\n';
}
}
using lnt=long long;
const int N=1e5+10;
int T,n;lnt seq[N][3],ans;
struct replace_obj{lnt val,id;};
bool operator<(replace_obj a,replace_obj b){return a.val>b.val || (a.val==b.val && a.id<b.id);}
set<replace_obj>B,C;int choose[N];
void init(){

    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++)scanf("%d",&seq[i][j]);
        //cerr<<"accept A:"<<seq[i][0]<<' '<<ans<<'\n';
    }
}
lnt proc(){lnt ans=0;B.clear();C.clear();
    for(int i=1;i<=n;i++){
        B.insert({seq[i][1]-seq[i][0],i});
        ans+=seq[i][0];
    }
    for(int i=0;i<(n>>1);i++){
        replace_obj p=*B.begin();B.erase(B.begin());
        ans+=p.val;C.insert({seq[p.id][2]-seq[p.id][1],p.id});
        choose[p.id]=1;
        //cerr<<"accept B:"<<p.val<<' '<<p.id<<' '<<ans<<'\n';
    }
    for(int i=(n>>1);i<n;i++){
        replace_obj p=*B.begin();B.erase(B.begin());
        C.insert({seq[p.id][2]-seq[p.id][0],p.id});
    }//assert(B.empty());
    for(int i=0;i<(n>>1);i++){
        replace_obj p=*C.begin();C.erase(C.begin());
        if(p.val>0){
            ans+=p.val;
            choose[p.id]=2;
            //cerr<<"accept C:"<<p.val<<' '<<p.id<<' '<<ans<<'\n';
        }else break;
    }
    return ans;
}
void main(){
    scanf("%d",&T);//cerr<<clock();
    for(int i=1;i<=T;i++){
        scanf("%d",&n);//cerr<<clock();
        if(n<210){
            Brute::main(n);
            continue;
        }
        init();lnt ans1,ans2,ans3;
        ans1=proc();
        for(int i=1;i<=n;i++)swap(seq[i][2],seq[i][0]);
        ans2=proc();
        for(int i=1;i<=n;i++)swap(seq[i][1],seq[i][2]);
        ans3=proc();
        printf("%lld\n",max({ans1,ans2,ans3}));
    }
}
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    Main::main();
    return 0;
}
