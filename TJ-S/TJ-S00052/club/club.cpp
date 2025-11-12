#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int N=1e5+5;
int a[N][4];
int n;
int in(){
    int f=0,d=0;
    char c=getchar();
    while(c<'0'||c>'9'){
        c=getchar();
    }
    while('0'<=c&&c<='9'){
        d=d*10+c-'0';
        c=getchar();
    }
    return d;
}/*
namespace BL{
    int cho[N];
    int ans=0;
    void dfs(int now,int c1,int c2,int c3){
        if(c1*2>n||c2*2>n||c3*2>n)  return;
        if(now>n){
            int res=0;
            for(int i=1;i<=n;++i)
                res+=a[i][cho[i]];
            ans=max(ans,res);
            return ;
        }
        cho[now]=1;
        dfs(now+1,c1+1,c2,c3);
        cho[now]=2;
        dfs(now+1,c1,c2+1,c3);
        cho[now]=3;
        dfs(now+1,c1,c2,c3+1);
    }
    void main(){
        memset(cho,0,sizeof cho);
        ans=0;
        dfs(1,0,0,0);
        printf("%d\n",ans);
    }
}*/
int n2;
namespace BL2{
    int dfs(int now,int c1,int c2,int c3){
        if(c1*2>n||c2*2>n||c3*2>n)  return 0;
        if(now>n){
            return 0;
        }
        int res=0;
        if(c1+1<=n2)
        res=max(res,dfs(now+1,c1+1,c2,c3)+a[now][1]);
        if(c2+1<=n2)
        res=max(res,dfs(now+1,c1,c2+1,c3)+a[now][2]);
        if(c3+1<=n2)
        res=max(res,dfs(now+1,c1,c2,c3+1)+a[now][3]);
        return res;
    }
    void main(){
        printf("%d\n",dfs(1,0,0,0));
    }
}
namespace BL3{
    bool hasmem[205][105][105];
    LL mem[205][105][105];
    int dfs(int now,int c1,int c2,int c3){
        if(hasmem[now][c1][c2]) return mem[now][c1][c2];
        if(c1*2>n||c2*2>n||c3*2>n)  return 0;
        if(now>n){
            return 0;
        }
        LL res=0;
        if(c1+1<=n2)
        res=max(res,dfs(now+1,c1+1,c2,c3)+(LL)a[now][1]);
        if(c2+1<=n2)
        res=max(res,dfs(now+1,c1,c2+1,c3)+(LL)a[now][2]);
        if(c3+1<=n2)
        res=max(res,dfs(now+1,c1,c2,c3+1)+(LL)a[now][3]);
        hasmem[now][c1][c2]=1;
        mem[now][c1][c2]=res;
        return res;
    }
    void main(){
        memset(hasmem,0,sizeof hasmem);
        printf("%d\n",dfs(1,0,0,0));
    }
}
namespace TA{
    int ha[N];
    bool cmp(int a,int b){
        return a>b;
    }
    void main(){
        for(int i=1;i<=n;++i)   ha[i]=a[i][1];
        sort(ha+1,ha+1+n,cmp);
        LL res=0;
        for(int i=1;i<=n2;++i)  res+=ha[i];
        printf("%d\n",res);
    }
}
namespace TX{
    bool cho[N];
    struct DS{
        int who,w;
        bool operator<(const DS& o)const{
            return w<o.w;
        }
    };
    priority_queue<DS>q1,q2,q3;

    void main(){
            LL ans=0;
        memset(cho,0,sizeof cho);
        while(!q1.empty())  q1.pop();
        while(!q2.empty())  q2.pop();
        while(!q3.empty())  q3.pop();
        ans=0;
        for(int i=1;i<=n;++i){
            q1.push({i,a[i][1]}),q2.push({i,a[i][2]}),q3.push({i,a[i][3]});
        }
        int p=0;
        int c1=0,c2=0,c3=0;
        while(1){
            int ma=0;
            if((c1+1)*2<=n) ma=max(ma,q1.top().w);
            if((c2+1)*2<=n) ma=max(ma,q2.top().w);
            if((c3+1)*2<=n) ma=max(ma,q3.top().w);
            if((c1+1)*2<=n&&ma==q1.top().w){
                if(cho[q1.top().who])   q1.pop();
                else
                    cho[q1.top().who]=1, ++p,ans+=ma,++c1;
            }
            else if((c2+1)*2<=n&&ma==q2.top().w){
                if(cho[q2.top().who])   q2.pop();
                else
                    cho[q2.top().who]=1, ++p,ans+=ma,++c2;
            }
            else if((c3+1)*2<=n&&ma==q3.top().w){
                if(cho[q3.top().who])   q3.pop();
                else
                    cho[q2.top().who]=1, ++p,ans+=ma,++c3;
            }
            if(p==n)    break;
        }
        printf("%d\n",ans);
    }
}
namespace TB{
    struct Peo{
        int a,b;
    }ps[N];
    bool cmp(Peo u,Peo v){
        return u.a-u.b>v.a-v.b;
    }
    void main(){
        for(int i=1;i<=n;++i)   ps[i].a=a[i][1],ps[i].b=a[i][2];
        sort(ps+1,ps+1+n,cmp);
        int res=0;
        int c1=0;
        for(int i=1;i<=n;++i){
            if(((c1+1)<<1)<=n)   res+=ps[i].a,++c1;
            else    res+=ps[i].b;
        }
        printf("%d\n",res);
    }
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=in();
    while(T--){
        bool fa=1,fb=1;
        n=in();
        n2=n/2;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=3;++j)   a[i][j]=in();
            if(a[i][2]!=0||a[i][3]!=0)  fa=0;
            if(a[i][3]!=0)  fb=0;
        }
        if(fa)  TA::main();
        else if(n<100000)   BL3::main();
        else if(fb) TB::main();
        else    TX::main();
    }
    return 0;
}
