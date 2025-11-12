#include<bits/stdc++.h>
using namespace std;
const int N = 510;
const int P = 998244353;
#define OPEN freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
long long n,m,a[N],ans = 1;
string c;
long long A(int n,int m){
	long long s = 1;
	for(int i = 0;i < m;i++) s *= (n - i) % P;
	return s % P;
}
int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	OPEN
	cin >> n >> m >> c;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	int s = 0,s1 = 0;
	for(int i = 1;i <= n;i++){
		if(a[i] == 0) s++,s1++;
		else if(s1 > a[i]) s1++;
	}
	for(int i = 1;i <= n;i++){
		if(a[i] == 0 && a[i + 1] > s1 && a[i + 1] != 0) return cout << A(n,n),0;
	}
	for(int i = 1;i <= n;i++){
		if(a[i] == 0) continue;
		
		for(int j = 0;j <= a[i] - 1;j++){
			ans *= A(s,min(j,s)),ans %= P;
			cout << s << ' ' << min(j,s) << ' ' << A(s,min(j,s)) << "\n";
		} 
		
	}
	cout << 0;
	return 0;
}
