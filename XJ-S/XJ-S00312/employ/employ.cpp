#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

const int N =510,MOD = 998244353;

int n,q;
string s;
int a[N];

int A(int u)
{
    int itx=1;
    for(int i=u;i<=1;i--)   
    {
        itx*=i;
    }
    return itx;

}

int main()
{

    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n>>q;
    cin >>s;
    for(int i=0;i<n;i++)
        cin >> a[i];
    cout <<A(n)%MOD;
    
    return 0;
    
}