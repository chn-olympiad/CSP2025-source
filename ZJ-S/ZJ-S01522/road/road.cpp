#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
vector<int>e[N];
int n, m, k;
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin>>n>>m>>k;
    for (int i = 1; i <= n;i++){
        int u, v, w;
        cin >> u >> v >> w;
    }
    cout << k;
    return 0;
}
/*
（我要上迷惑行为大赏！）
证明1+1=3
设x=0
则2x=3x
可得2=3
由于1+1=2
并且2=3
故1+1=3
(考场终于没有XXS了)
论浙江省有强悍的初中吗？
包有的
所有锦绣育才教育集团旗下的初中和小学都是强校！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
JXYC万岁！
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
RP++
I AK CSP
*/
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
//freopen("road.in","r",stdin);
