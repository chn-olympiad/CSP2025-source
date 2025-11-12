#include<bits/stdc++.h>
using namespace std;
#define int long long
#define const constexpr
#define endl '\n'
const int N=109;
int x[N][N];
int32_t main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,z;
    cin >> n >> m;
    vector<int> a(n*m+1,0);
    for(int i=1;i<=n*m;i++)
    {
        cin >> a[i];
    }
    z=a[1];
    sort(a.rbegin(),a.rend()-1);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==z)
        {
            if(i%n==0)
            {
                cout << i/2 << " " <<  n <<endl;
            }
            else if(i%n==1&&i/2!=1)
            {
                cout << i/2 << " " << i/n << endl;
            }
            else
            {
                cout << n << " " << m << endl;
            }
            return 0;
        }
    }
    return 0;
}