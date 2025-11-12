#include <bits/stdc++.h>
using namespace std;
int n, m, c[502];
string s;

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(int i=1; i<=n; i++) scanf("%d", &c[i]);
	int cnt=0;
	for(int i=1; i<=n; i++)
		if(c[i])
		{
			cnt++;
		}
	long long ans=1;
	for(int i=cnt-m+1; i<=cnt; i++){
		cout << i << " " << ans << endl;
		ans = (ans*i) % 998244353;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
