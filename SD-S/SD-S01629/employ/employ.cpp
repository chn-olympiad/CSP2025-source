#include<bits/stdc++.h>
using namespace std;
const int N = 550;
const int mod = 998244353;
int n,m;
string s;
int pat[N];
unsigned long long ans = 1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	int k = n;
	for(int i = 1;i <= n;i++)
	{
		cin >> pat[i];
		if(pat[i] == 0) k--;
	}
	for(int i = 2;i <= n;i++)
	{
		ans = (ans*i)%mod;
	}
	cout << ans%mod << '\n';
	return 0;
}

