#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define x first
#define y second
#define ll long long
#define ull unsigned long long
#define forr(a, b, c) for (int i = (a); i <= (b); i += (c))
using namespace std;
const int N = 1e5 + 10;
struct node{
	int a, b, c;
	int mm;
	int id;
}op[N];
int f[N][4];
void into(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
}
void solve();
bool cmp(node x, node y)
{
	return x.mm > y.mm;
}
bool cmp1(node x, node y){
	return x.a > y.a;
}
bool cmp2(node x, node y){
	return x.b > y.b;
}
bool cmp3(node x, node y){
	return x.c > y.c;
}
int main()
{
	into();
	IOS;
	int T;
	cin >> T;
	while(T--)
	{
		solve();
	}
}
void solve()
{
	int n;
	cin >> n;
	memset(f, 0, sizeof f);
	for (int i = 1; i <= n; i++)
	{
		cin >> op[i].a >> op[i].b >> op[i].c;
		op[i].mm = max({op[i].a, op[i].b, op[i].c});
		int q = op[i].mm;
		if(q == op[i].a) op[i].id = 1;
		if(q == op[i].b) op[i].id = 2;
		if(q == op[i].c) op[i].id = 3;
	}
	int cc1, cc2, cc3;
	cc1 = cc2 = cc3 = 0;
	sort(op + 1, op + 1 + n, cmp);
	int ans = 0;
	int flag = 0;
	int idx;
	for (int i = 1; i <= n; i++)
	{
		idx = i;
		ans += op[i].mm;
		if(op[i].id  == 1) cc1++;
		if(op[i].id  == 2) cc2++;
		if(op[i].id  == 3) cc3++;
		if(cc1 == n / 2) {
			flag = 1;
			break;
		}
		if(cc2 == n / 2){
			flag = 2;
			break;
		}
		if(cc3 == n / 2){
			flag = 3;
			break;
		}
	}
	sort(op + 1, op + 1 + n, cmp1);
	for (int i = 1; i <= n / 2; i++) f[i][1] = f[i - 1][1] + op[i].a;
	for (int i = n / 2 + 1; i <= n; i++) f[i][1] = f[i - 1][1] + max(op[i].b, op[i].c);
	sort(op + 1, op + 1 + n, cmp2);
	for (int i = 1; i <= n / 2; i++) f[i][2] = f[i - 1][2] + op[i].b;
	for (int i = n / 2 + 1; i <= n; i++) f[i][2] = f[i - 1][2] + max(op[i].a, op[i].c);
	sort(op + 1, op + 1 + n, cmp3);
	for (int i = 1; i <= n / 2; i++) f[i][3] = f[i - 1][3] + op[i].c;
	for (int i = n / 2 + 1; i <= n; i++) f[i][3] = f[i - 1][3] + max(op[i].a, op[i].b);
	if(flag == 1) for (int i = idx + 1; i <= n; i++) ans += max(op[i].b, op[i].c);
	if(flag == 2) for (int i = idx + 1; i <= n; i++) ans += max(op[i].a, op[i].c);
	if(flag == 3) for (int i = idx + 1; i <= n; i++) ans += max(op[i].a, op[i].b);
	for (int i = 1; i <= 3; i++) {
		ans = max(ans, f[n][i]);
	}
	cout << ans << '\n';
}

