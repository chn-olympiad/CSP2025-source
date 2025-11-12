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

string s;
int c[10];
int main()
{
	fopn(number);

	cin >> s;
	iter(i, s) if(isdigit(i)) ++c[i - '0'];
	fbe(i, 9, 0) while(c[i]--) cout << i;

	fcls; return 0;
}

