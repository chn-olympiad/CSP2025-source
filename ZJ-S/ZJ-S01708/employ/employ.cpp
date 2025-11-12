#include <iostream>
#include<cstdio>
#include <string>
using namespace std;
typedef long long ll;
const int N = 1000;
const int p = 998244353;
int n, m;
string s;
int bear[N];

ll function(int n)
{
    ll res = 1;
    for(int i=1; i<=n; i++)
    {
        res = res * i % p;
    }
    return res;
}

int main()
{
	freopen("employ3.in", "r", stdin);
//	freopen("employ3.out", "w", stdout);
    scanf("%d %d", &n, &m);
    scanf("%s", &s);
    for(int i=1; i<=n; i++){
    	scanf("%d", &bear[i]);
	}
    cout << function(n);
    return 0;
}
