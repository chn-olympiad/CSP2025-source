#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n , m , c[500] ,cnt , cnt2;
long long a[505] , mod = 998244353 , ans;
string s;
bool f1 = 1;
void init()
{
	a[1] = 1;
	for (int i = 1;i <= n;i ++)
	{
		a[i] = (a[i - 1] * i) % mod;
	} 
}
int main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	init();
	cin >> n >> m >> s;
	for (int i = 1;i <= n;i ++)
	{
		cin >> c[i];
		if  (!c[i]) ++ cnt;
	}
	cnt2 = n - cnt;
	if  (cnt2 < m)
	{
		cout << 0;
		return 0;
	}
	for (int i = 0;i < n;i ++)
		if  (s[i] == '0') f1 = 0;
	if  (f1)
	{
		cout << c[n];
	}
	return 0; 
} 
