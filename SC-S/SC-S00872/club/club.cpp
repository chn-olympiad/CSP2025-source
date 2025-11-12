#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int n;
struct Node
{
    int w, id;

    friend bool operator < (Node a, Node b)
    {
        a.w > b.w;
    }
}t[maxn][4];
int ans, cnt1, cnt2, cnt3;

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int T;
    scanf("%d", &T);
    while(T--)
    {
        ans = cnt1 = cnt2 = cnt3 = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &t[i][1].w, &t[i][2].w, &t[i][3].w);
            t[i][1].id = t[i][2].id = t[i][3].id = i;
        }
        priority_queue<Node> q1, q2, q3;

        for(int i = 1; i <= n; i++)
        {
            int w1 = t[i][1].w, w2 = t[i][2].w, w3 = t[i][3].w;
            if(w1 > w2 && w1 > w3)
            {
                if(cnt1 + 1 <= n / 2)
                {
                    cnt1++;
                    q1.push(t[i][1]);
                    ans += w1;
                }
                else if(cnt1 + 1 > n / 2)
                {
                    Node tmp = q1.top();
                    int idx = tmp.id, W = tmp.w;
                    int omax = max(t[idx][2].w, t[idx][3].w);
                    int maxid = t[idx][2].w == omax ? 2 : 3;
                    if(ans - W + omax + w1 > ans)
                    {
                        q1.pop();
                        q1.push(t[i][1]);
                        if(maxid == 2)
                        {
                            q2.push(t[idx][2]);
                            cnt2++;
                        }
                        else
                        {
                            q3.push(t[idx][3]);
                            cnt3++;
                        }
                        ans = ans - W + omax + t[i][1].w;
                    }
                }
            }
            else if(w2 > w1 && w2 > w3)
            {
                if(cnt2 + 1 <= n / 2)
                {
                    cnt2++;
                    q2.push(t[i][2]);
                    ans += w2;
                }
                else if(cnt2 + 1 > n / 2)
                {
                    Node tmp = q2.top();
                    int idx = tmp.id, W = tmp.w;
                    int omax = max(t[idx][1].w, t[idx][3].w);
                    int maxid = omax == t[idx][1].w ? 1 : 3;
                    if(ans - W + omax + w2 > ans)
                    {
                        ans = ans - W + omax + t[i][2].w;
                        q2.pop();
                        q2.push(t[i][2]);
                        if(maxid == 1)
                        {
                            q1.push(t[idx][1]);
                            cnt1++;
                        }
                        else
                        {
                            q3.push(t[idx][3]);
                            cnt3++;
                        }
                    }
                }
            }
            else if(w3 > w1 && w3 > w2)
            {
                if(cnt3 + 1 <= n / 2)
                {
                    q3.push(t[i][3]);
                    cnt3++;
                    ans += w3;
                }
                else
                {
                    Node tmp = q3.top();
                    int idx = tmp.id, W = tmp.w;
                    int omax = max(t[idx][1].w, t[idx][2].w);
                    int maxid = omax == t[idx][1].w ? 1 : 2;
                    if(ans - W + omax + w3 > ans)
                    {
                        q3.pop();
                        q3.push(t[i][3]);
                        if(maxid == 1)
                        {
                            q1.push(t[idx][1]);
                            cnt1++;
                        }
                        else
                        {
                            q2.push(t[idx][2]);
                            cnt2++;
                        }
                    }
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
