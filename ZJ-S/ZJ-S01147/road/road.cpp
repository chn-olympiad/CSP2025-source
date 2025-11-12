#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e4+10;
using ll = long long;
int n, m, k;
struct CtPath
{
    int needCt; // 需要的乡村，若为 0 则不需要乡村
    ll value;   // 权值
};
unordered_map<int, int> graph[MAXN];
unordered_map<int, unordered_map<int, int>> county;
unordered_map<int, unordered_map<int, vector<CtPath>>> cg;
unordered_map<int, int> cityFrom; // 如果 cityFrom[x] 中的值为 0 则代表不需要城市化
unordered_map<int, int> father;
const int s = 1;
int cnt = 0; // 被重建的tree集节点数量
ll ans = 0;  // 答案
int find_parent(int x)
{
    if (father[x] == x)
        return x;
    return father[x] = find_parent(father[x]);
}
void add(int x)
{
    int tx = find_parent(x);
    int ty = 1;
    if (tx == ty)
        return;
    if (x <= n)
    {
        cnt++;
    }

    father[tx] = ty;
}
bool in(int x)
{
    return find_parent(x) == s;
}
void prim()
{
    struct Node
    {
        int id;     // 到达的点
        ll value;   // 所需权值
        int needCt; // 需要的村庄
        bool operator<(const Node &o) const
        {
            return value < o.value;
        }
        bool operator>(const Node &o) const
        {
            return value > o.value;
        }
    };
    // 从 1 开始
    // 我们维护一个集合，是从当前节点连接到下一个节点的最短距离，每次取最短距离。
    // 每次链接最短距离时，我们考虑是否有乡村可以更快的链接到这个点
    priority_queue<Node, vector<Node>, greater<Node>> q;
    // 先载入 1 的所有可能的路径，乡村使用另一个 q 因为权值可能会更改。如果乡村的 c 为 0，则直接载入
    // ok我知道怎么写这个动态变更了。先传入无c的值，然后比较+c后的值和q中top的值，如果还是小就做，否则不行。

    // 先写城市的转移
    for (auto i : graph[s])
    {
        q.push(Node{i.first, i.second, 0});
    }
    // 再写乡村的转移
    for (auto i : cg[s])
    {
        for (auto j : i.second)
        {
            auto needCt = j.needCt;
            if (cityFrom[needCt] == 0)
                needCt = 0;
            q.push(Node{i.first, j.value, needCt});
        }
    }

    auto checkIsCt = [&](Node &head)
    {
        return head.needCt != 0 && cityFrom[head.needCt] != 0;
    };

    cnt = 1;

    while (cnt != n)
    {
        auto head = q.top();
        q.pop();
        // 如果上一层还是从未被建设的乡村转移过来的，一直加入一个p队列直到有不是从乡村转移的
        // 因为乡村有可能实际权值偏小
        if (checkIsCt(head))
        {
            priority_queue<Node, vector<Node>, greater<Node>> qq;
            head.value += cityFrom[head.needCt];
            qq.push(head);
            while (q.size() && checkIsCt(head))
            {
                head = q.top();
                q.pop();
                if (checkIsCt(head))
                {
                    head.value += cityFrom[head.needCt];
                }
                qq.push(head);
            }
            head = qq.top();
            qq.pop();
            // 放回去防止少答案
            while (qq.size())
            {
                q.push(qq.top());
                qq.pop();
            }
        }
        if (in(head.id))
        {
            continue;
        }
        add(head.id);
        ans += head.value;
        if (checkIsCt(head))
        {
            cityFrom[head.needCt] = 0;
        }

        // 城市转移
        for (auto i : graph[head.id])
        {
            q.push(Node{i.first, i.second, 0});
        }
        // 乡村的转移
        for (auto i : cg[head.id])
        {
            for (auto j : i.second)
            {
                auto needCt = j.needCt;
                if (cityFrom[needCt] == 0)
                    needCt = 0;
                q.push(Node{i.first, j.value, needCt});
            }
        }
    }
}
void prim_AF()
{
    // for (auto i : cg)
    // {
    //     for (auto j : i.second)
    //     {
    //         for (auto k : j.second)
    //         {
    //             graph[i.first][j.first] = min((int)k.value, graph[i.first][j.first]);
    //         }
    //     }
    // }
    struct Node
    {
        int v;
        int dis;
        bool operator<(const Node &o) const
        {
            return dis < o.dis;
        }
        bool operator>(const Node &o) const
        {
            return dis > o.dis;
        }
    };
    priority_queue<Node, vector<Node>, greater<Node>> q;
    for (auto i : graph[s])
    {
        q.push(Node{i.first, i.second});
    }
    cnt = 1;
    while (cnt != n)
    {
        auto head = q.top();
        q.pop();
        if (in(head.v))
        {
            continue;
        }
        add(head.v);
        ans += head.dis;
        for (auto i : graph[head.v])
        {
            q.push(Node{i.first, i.second});
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    bool AF_flag = true;
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n + k; i++)
    {
        father[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x][y] = min(graph[x][y]!=0?graph[x][y]:INT_MAX, w);
        graph[y][x] = min(graph[x][y]!=0?graph[x][y]:INT_MAX, w);
    }
    // 农村的编号是 n+i(1<=i<=k)
    for (int i = 1; i <= k; i++)
    {
        int c;
        cin >> c;
        cityFrom[n + i] = c;
        if (c != 0)
            AF_flag = false;
        for (int u = 1; u <= n; u++)
        {
            int w;
            cin >> w;
            county[n + i][u] = w;
            county[u][n + i] = w;
        }
    }
    if (AF_flag)
    {
        
        for (int i = 1; i <= k; i++)
        {
            for (auto x : county[n + i])
            {
                for (auto y : county[n + i])
                {
                    if (x.first != y.first)
                    {
                        graph[x.first][y.first] = min(graph[x.first][y.first]!=0?graph[x.first][y.first]:INT_MAX, x.second + y.second);
                    }
                }
            }
        }
        prim_AF();
    }
    else
    {
        for (int i = 1; i <= k; i++)
        {
            for (auto x : county[n + i])
            {
                for (auto y : county[n + i])
                {
                    if (x.first != y.first)
                    {
                        cg[x.first][y.first].push_back(CtPath{n + i, x.second + y.second});
                    }
                }
            }
        }
        prim();
    }
    cout << ans << endl;
    return 0;
}
// 我们可以通过最小生成树来解决这个问题，将每个被破坏的道路的权值设为 w_i
// 同时将每个农村的链接每个城市的道路权值也一起设置，跑一遍最小生成树即可
// 我们将每个农村的编号设置为 j+n。
// 同时，如果某个农村没有被进行城市化改造，那么到达农村的dis就会加上改造的费用，改造后减去费
// 尝试预处理乡村的所有路径，也就是由 x -> t -> y 点假设 t 已经被改造的费用。