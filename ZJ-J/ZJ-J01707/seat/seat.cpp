#include <bits/stdc++.h>
using namespace std;
int n , m , ans;
struct student
{
    int score;
}p[400];
bool cmp(student a , student b)
{
    return a.score > b.score;
}
int main()
{
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    memset(p , 0 , sizeof(p));
    cin >> n >> m;
    for(int i = 1 ; i <= n * m ; i++)
    {
        cin >> p[i].score;
    }
    int t = p[1].score;
    sort(p + 1 , p + n * m + 1 , cmp);
    for(int i = 1 ; i <= n * m ; i++)
    {
        if(p[i].score == t)
        {
            ans = i;
        }
    }
    if(ans % n == 0)
    {
        if((ans / n) % 2 == 0)
        {
            cout << ans / n << " " << 1;
        }
        else
        {
            cout << ans / n << " " << n;
        }
    }
    else
    {
        if((ans/ n) % 2 == 0)
        {
            cout << ans / n + 1 << " " << ans % n;
        }
        else
        {
            int s = n + 1 - (ans % n);
            cout << ans / n + 1 << " " << s;
        }
    }
    return 0;
}
