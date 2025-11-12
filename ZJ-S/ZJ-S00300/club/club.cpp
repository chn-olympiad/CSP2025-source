// 贪心策略有问题貌似

# include <bits/stdc++.h>
using namespace std;
# define int long long

const int N = 1e5 + 5;

struct Node{
    int w, id, bel;
    bool operator <(const Node& other) const {
        return w < other.w;
    }
};

int a[N][4];
int vis[N][4];
int cnt[4];

int read(){
    int x = 0, f = 1;
    char ch = getchar_unlocked();
    while(ch < '0' || ch > '9'){
        if (ch == '-') f = -1;
        ch = getchar_unlocked();
    }
    while(ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar_unlocked();
    }
    return x * f;
}

void write(int x){
    if (x < 0){
        putchar_unlocked('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar_unlocked(x % 10 + '0');
}

void solve(){
    memset(a,0,sizeof(a));
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    int n, ans = 0; n = read();
    priority_queue<Node, vector<Node>, less<Node>> pq;
    for (int i = 1; i <= n; i++){
        int maxa = 0, maxbel = 0;
        cin >> a[i][1]>> a[i][2] >> a[i][3];
        for (int j : {1,2,3}){
            if (a[i][j] >= maxa) maxa = a[i][j], maxbel = j;
        }
        pq.push({maxa,i,maxbel});
        vis[i][maxbel] = true;
    }
    while (!pq.empty()){
        Node t = pq.top(); pq.pop();
        int w, id, bel;
        w = t.w, id = t.id, bel = t.bel;
        if (cnt[bel] + 1 <= n / 2){
            cnt[bel]++;
            vis[id][bel] = true;
            ans+=w;
        }else{
            int maxa = 0, maxbel = 0;
            for(int j : {1,2,3}){
                if (vis[id][j]) continue;
                if (a[id][j] >= maxa) maxa = a[id][j], maxbel = j;
            }
            pq.push({maxa,id,maxbel});
            vis[id][maxbel] = true;
        }
    }
    cout << ans << '\n';
}

signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T; T = read();
    while (T--) solve();
    return 0;
}
