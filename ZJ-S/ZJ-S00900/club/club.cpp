/*
重点是n/2意味着最多有1个是不满足要求的，而其余两个不管怎么变都不会超出要求，所以只需要对这一个部门进行修改，那就先倾定所有人都选最大的，然后挑出若干个改变后减少的满意度最少的以满足要求
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int T,n,a[maxn][3],q[3][maxn],til[3],op,ans;
priority_queue<int>que;
int rd(){
    int res=0,y=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') y=-y;ch=getchar();}
    while(isdigit(ch)) res=(res<<1)+(res<<3)+(ch&15),ch=getchar();
    return res*y;
}
int getsec(int x,int y,int z){
    int Max=max(x,max(y,z)),Min=min(x,min(y,z)),sum=x+y+z;
    return sum-Max-Min;
}
int getsec(int id){
    return getsec(a[id][0],a[id][1],a[id][2]);
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    T=rd();
    while(T--){
        til[0]=til[1]=til[2]=0;ans=0;op=0;
        n=rd();
        for(int i=1;i<=n;i++){
            a[i][0]=rd();a[i][1]=rd();a[i][2]=rd();
            int Max=max(a[i][0],max(a[i][1],a[i][2]));
            if(Max==a[i][0]) q[0][++til[0]]=i;
            else if(Max==a[i][1]) q[1][++til[1]]=i;
            else q[2][++til[2]]=i;
            ans+=Max;
        }
        for(int i=0;i<3;i++)
          if(til[i]>til[op]) op=i;
        // printf("test:%d %d %d %d\ncheck:%d %d %d\n",ans,op,til[op],n,til[0],til[1],til[2]);
        if(til[op]<=n/2){printf("%d\n",ans);continue;}
        for(int i=1;i<=til[op];i++) que.push(getsec(q[op][i])-a[q[op][i]][op]);
        int num=til[op]-n/2;
        while(num) ans+=que.top(),que.pop(),num--;
        while(!que.empty()) que.pop();
        printf("%d\n",ans);
    }
    return 0;
}