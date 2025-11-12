#include<bits/stdc++.h>
using namespace std;
char a[1000010];
int ans[1000010], tot;
bool mycmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a + 1;
	for(int i = 1; i <= strlen(a + 1); i++)
		if(a[i] >= 0 && a[i] <= '9')
			ans[++tot] = a[i] - '0';
	sort(ans + 1, ans + 1 + tot, mycmp);
	for(int i = 1; i <= tot; i++)
		cout << ans[i];
	return 0;
}
