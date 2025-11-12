#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 +50;
int t = 0,n = 0,ans = 0,cnt1 = 0,cnt2 = 0,cnt3 = 0;
int app[N][4];
int vis[N];
struct node
{
    int g1,g2,g3; // g means group; 
    int id,prime,chose,change;
}a[N];
bool cmp(node c,node d){ return c.change > d.change;}
void dfs(int x,int sum)
{
    if(cnt1 > (n / 2) || cnt2 > (n / 2) || cnt3 > (n / 2)) return;
    if(x == n + 1)
    {
        ans = max(ans,sum);
        return;
    }
    cnt1 += 1;
    dfs(x + 1,sum + app[x][1]);
    cnt1 -= 1;

    cnt2 += 1;
    dfs(x + 1,sum + app[x][2]);
    cnt2 -= 1;

    cnt3 += 1;
    dfs(x + 1,sum + app[x][3]);
    cnt3 -= 1;
    return;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n <= 10)
        {
            ans = cnt1 = cnt2 = cnt3 = 0;
            for(int i = 1;i <= n;i++)
            {
                scanf("%d%d%d",&app[i][1],&app[i][2],&app[i][3]);
            }
            dfs(1,0);
            cout << ans << " \n";
        }
        else
        {
        	ans = 0;
            cnt1 = 0,cnt2 = 0,cnt3 = 0; // 每组分别选了几个
            for(int i = 1;i <= n;i++)
            {
                scanf("%d%d%d",&a[i].g1,&a[i].g2,&a[i].g3);
                vis[i] = 0;
                a[i].id = i;
                if(a[i].g1 >= a[i].g2)
                {
                    ans += a[i].g1;
                    a[i].prime = 1;// 原先选了哪一个
                    cnt1++;
                }
                else
                {
                    ans += a[i].g2;
                    a[i].prime = 2;
                    cnt2++;
                }
            // 这里不考虑 《 （n/2）的限制，直接选较大的，是为了保证后续1，2交换不会更新答案
            }
            //cout << ans << " " << endl;
            if(cnt1 < cnt2)
            {
                swap(cnt1,cnt2);
                for(int i = 1;i <= n;i++) swap(a[i].g1,a[i].g2);
                for(int i = 1;i <= n;i++)
                {
                    if(a[i].prime == 1) a[i].prime = 2;
                    else a[i].prime = 1;
                }
            }  // 考虑到1，2组等价 这里可以直接交换
            if(true)
            {
                // 用2 或 3 替换 1
                for(int i = 1;i <= n;i++)
                {
                    if(a[i].g2 > a[i].g3)
                    {
                        a[i].chose = 2;  //如果要替换，选哪个替换
                        a[i].change = a[i].g2 - a[i].g1; //选择替换对答案的影响 
                    }
                    else
                    {
                        a[i].chose = 3;
                        a[i].change = a[i].g3 - a[i].g1;
                    }
                }
                sort(a + 1,a + n + 1,cmp);
                int cnt = cnt1 - (n / 2),k = 0; // cnt 表示要替换多少个 1
                //cout << cnt << endl;
                for(int i = 1;i <= n;i++)
                {
                    if(a[i].prime == 1) // 优先保证合法  答案不可能由1，2 交换而更新的情况下答案
                    {
                        k++;
                        if(a[i].chose == 2)  cnt2++;
                        else  cnt3++;
                        ans += a[i].change;
                        vis[a[i].id] = 1;
                    }
                    if(k == cnt) break;
                }
                for(int i = 1;i <= n;i++)
                {
                    if(vis[a[i].id])
                    {
                        a[i].change = 0;
                        continue;
                    }
                    if(a[i].prime == 1) a[i].change = a[i].g3 - a[i].g1;
                    else a[i].change = a[i].g3 - a[i].g2;
                    // 怎么换
                }
            
            
                // 由1，3 或 1，2 交换对答案产生的影响    
                sort(a + 1,a + n + 1,cmp);
                for(int i = 1;i <= n;i++) // 保证答案合法时 保证不会因1，3 或 2，3 交换而更新
                {
                    //cout << i << " ans:" << ans << endl;
                    if(vis[a[i].id]) continue;
                    if(a[i].change > 0)
                    {
                        ans += a[i].change;
                        cnt3++;
                    } 
                    if(cnt3 >= (n / 2)) break;
                }
            }
            //cout << "1:" << cnt1 << " 2:" << cnt2 << " 3:" << cnt3 << endl;
            cout << ans << endl;
        }
    }
    return 0;
}