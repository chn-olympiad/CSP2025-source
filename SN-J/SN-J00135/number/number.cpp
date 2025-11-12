#include<bits/stdc++.h>

using namespace std;

#define int long long

char s;
int num[1000010];
int cnt;

signed main()
{
	//一定不要忘记删啊 
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	//一定不要忘记删啊 
	
	int i;
	
	cnt = 0;
	while(cin >> s)
	{
		if(s >= '0' && s <= '9')
		{
			num[cnt] = s - '0';
			cnt++;
		}
	}
	sort(num, num + cnt, greater<int>());
	for(i = 0; i < cnt; i++)
	{
		cout << num[i];
	}
}
