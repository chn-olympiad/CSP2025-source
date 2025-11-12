#include<bits/stdc++.h>
using namespace std;
int n, a[5005], b, l, ans;
bool f;
//vector<int> x;
void dfs_(int m, int k, int ind)
{
    if(k-1 == m)
    {
        //for(int i:x) cout<<i<<' ';
        if(b-l > l)
        {
            ++ans;
            ans %= 998244353;
            //cout << "ok";
        }
        else f = 1;
        //cout << "  "<< b << ' ' << l;
        //cout << endl;
    }
    else
    {
    	f = 0;
        for(int i=ind; i<=n-(m-k); ++i)
        {
            l = a[i];
            b += a[i];
            //x.push_back(a[i]);
            dfs_(m, k+1, i+1);
            //x.pop_back();
            b -= a[i];
            if(f)
            {
                f=0;
                break;
            }
        }
    }
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    sort(a+1, a+n+1);
    for(int i=3; i<=n; ++i) dfs_(i, 1, 1);
    cout << ans;
    return 0;
}
