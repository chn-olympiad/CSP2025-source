#include <bits/stdc++.h>
using namespace std;
int n , a[5005] , ans;
const long long MOD = 998244353;
bool dbx(int b[] , int j)
{
    int sum = 0;
    sort(b + 1 , b + j + 1);
    for(int i = 1 ; i <= j ; i++)
    {
        sum += b[i];
    }
    if(sum > 2 * b[j])
    {
        return true;
    }
    return false;
}
int main()
{
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
    cin >> n;
    if(n < 3)
    {
        cout << 0;
        return 0;
    }
    if(n == 3 && dbx(a , 3))
    {
        cout << 1;
        return 0;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    for(int i = 3 ; i <= n ; i++)
    {
        int sum = ans;
        do
        {
            if(dbx(a , i))
            {
                ans = (ans + 1) % MOD;
            }
        }while(next_permutation(a + 1 , a + i + 1));
        ans -= sum;
        ans = ans / i;
        ans = ans / (i - 1);
        ans += sum;
    }
    cout << ans + 1;
    return 0;
}
