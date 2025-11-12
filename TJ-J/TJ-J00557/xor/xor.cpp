#include<bits/stdc++.h>
using namespace std;
#define ll 					long long
#define ull 				unsigned long long
#define MOD					1000000007
#define inf 				0x3f3f3f3f
#define INF  				0x3f3f3f3f3f3f3f3f
#define ff(i, l, r)			for(int i = (l), END##i = (r); i <  END##i; ++i)
#define ffe(i, l, r)		for(int i = (l), END##i = (r); i <= END##i; ++i)
#define fb(i, l, r)			for(int i = (l), END##i = (r); i >  END##i; --i)
#define fbe(i, l, r)		for(int i = (l), END##i = (r); i >= END##i; --i)
#define iter(it, v) 		for(auto it : v)
#define fopn(fn) 			freopen(#fn".in", "r", stdin);freopen(#fn".out", "w", stdout)
#define fcls				fclose(stdin);fclose(stdout)
ll n, k, a[500002][2], r1, r2;
int main()
{
	fopn(xor);
    cin >> n >> k;
    ffe(i, 1, n)
    {
        cin >> a[i][0];
        if(k == a[i][0])  a[i][1] = 0, ++r1;
        a[i][1] = a[i][0] ^ a[i - 1][1];
        if(a[i][1] == k)  a[i][1] = 0, ++r2;
    }
    cout << max(r1, r2);
	fcls; return 0;
}

