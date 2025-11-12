#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n , m;
    int x , y;
    cin >> n >> m;
    int square = n * m; 
    int scores[square + 1] , littleR;
    for(int i = 0;i <= n * m;i ++)
    {
        cin >> scores[i];
        if(i == 0)
        {
            scores[0] == littleR;
        }
    }
    std::sort(scores[0],scores[square + 1]);
    int weishu;
    for(int i = n * m; i >= 0;i --)
    {
        if(scores[i] == littleR)
        {
            weishu = i;
        }
    }
    if(weishu > n)
    {
        x = ceil(weishu / n);
        if((x % 2 == 0) && (weishu % n != 0))
        {
            y = n + 1 - (weishu % n);
        }
        else if(weishu % n == 0)
        {
            y = 1;
        }
        else if((x % 2 != 0))
        {
            y = weishu % n;
        }
    }
    else
    {
        x = 1;
        y = weishu;
    }
    cout << x << " " << y;
    return 0;
}
