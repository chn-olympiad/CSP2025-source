//准考证号：SN-J00393
//姓名：张益舟 
//学校：西安滨河学校 
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k, a[100005];
signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) cin >> a[i];
	printf("%d\n", a[1]);
	return 0;
}
