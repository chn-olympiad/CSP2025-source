#include <bits/stdc++.h>
using namespace std;
int n,m,k,now,sum;
struct stu{
    int u,v,w,c;
    bool is;
}a[1000015];
struct node{
    int id,money;
};
int hs[10015];
int dp[10015];
vector <int> road[10015];
queue <node> q;
int bfs(){
    q.push({1,0});
    dp[1] = 1;
    while (!q.empty()){
        //cout << "do\n";
        int id=q.front().id,money=q.front().money;
        q.pop();
        int cnt=0;
        for (int i=0;i<road[id].size();i++){
            stu r=a[road[id][i]];
            int another;
            if (r.u == id){
                another = r.v;
            }else{
                another = r.u;
            }
            if (another > n){
                money += r.c;
            }
            if (dp[another] == 0 || r.w+money < dp[another]){
                if (another <= n && dp[another] == 0){
                    now--;
                }
                dp[another] = r.w+money;
                q.push({another,r.w+money});
                hs[another] = id;
                //printf("from %d to %d id:%d\n",id,another,road[id][i]);
            }
            if (another > n){
                money -= r.c;
            }
        }
    }
}
int dfs(int id){
    int nid = hs[id];
    if (nid == 0){
        return 0;
    }
    hs[id] = 0;
    //printf("add from %d to %d,money:%d\n",nid,id,dp[id]-dp[nid]);
    return dp[id]-dp[nid]+dfs(nid);
}
int main(){
    /*freopen(".in","r",stdin);
    freopen(".out","w",stdout);

    fclose(stdin);
    fclose(stdout);*/
    cin >> n >> m >> k;
    for (int i=1;i<=m;i++){
        cin >> a[i].u >> a[i].v >> a[i].w;
        if (a[i].u > a[i].v){
            swap(a[i].u,a[i].v);
        }
        road[a[i].u].push_back(i);
        road[a[i].v].push_back(i);
    }
    for (int i=1;i<=k;i++){
        int c;
        cin >> c;
        for (int j=1;j<=n;j++){
            //printf("do%d %d\n",i,j);
            a[++m].u = j;
            a[m].v = n+i;
            cin >> a[m].w;
            a[m].c = c;
            a[m].is = false;
            road[j].push_back(m);
            road[n+i].push_back(m);
        }
    }
    for (int i=1;i<=m;i++){
        //printf("road:from %d to %d,money:%d,id:%d\n",a[i].u,a[i].v,a[i].w,i);
    }
    bfs();
    /*for (int i=1;i<=n+k;i++){
        printf("in hs:from %d to %d\n",hs[i],i);
    }*/
    for (int i=1;i<=n;i++){
        sum += dfs(i);
        //printf("add money:%d\n",sum);
    }
    cout << sum;
    return 0;
}

