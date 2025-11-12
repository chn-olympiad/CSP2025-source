#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=0,a;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m >> a;
    for(int i = 1;i < n*m;i++)
    {
        int b;
        cin >> b;
        cnt += (b > a);
    }
    int c=cnt/n+1;
    int r=cnt%n+1;
    r=((c%2)?r:n+1-r);
    cout << c << ' ' << r;
    return 0;
}