#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
long long n,q;
string s1[N],s2[N],t1[N],t2[N];
int re(string s1,string s2)
{
	string y,x,z;
	long long sum;
	for (long long i = 1;i <= s1.size();i++)  
	{
		for (int j = 1;j <= )
	}
	return sum;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (long long i = 1;i <= n;i++)
	{
		cin >> s1[i] >> s2[i];
		
	}
	for (long long i = 1;i <= q;i++)
	{
		cin >> t1[i] >> t2[i];
	}
	for (long long i = 1;i <= q;i++)
	{
		cout << re(t1[i],t2[i]) << endl;
	}
	return 0;
}
