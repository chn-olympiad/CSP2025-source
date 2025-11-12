#include<bits/stdc++.h>
using namespace std;
int n , m , cnt = 0 , ans = 0;
char s[501];
struct point{
	int p , id;
	bool flag;
}a[501];
int main()
{
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	cin >> n >> m;
	cin >> s+1;
	for(int i = 1 ;i <= n ;i ++)
		cin >> a[i].p;
	for(int i = 1 ;i <= n ;i ++)
	{
		cnt = 0;
		a[i].id = 1;
		for(int j = 2 ; j <= n ; j ++)
		{
			a[j].id = j;
			if(s[i] == '1') a[i].flag = 1;
			if(s[i] == '0') a[i].flag = 0;
			if((n - cnt) < a[i].p) a[i].flag = 0;
			if(a[i].flag == 1)
				cnt ++;
			if(cnt >= m)
				ans ++;
		}
	}
	cout << ans << endl;
	return 0;
}
