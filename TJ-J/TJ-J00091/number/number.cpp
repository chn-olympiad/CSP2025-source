#include <bits/stdc++.h>
using namespace std;
int l[1000005];
bool ans(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string a;
	cin >> a;
	int num = a.size(),cnt = 0;
	for(int i = 0;i < num;i++)
	{
		if(a[i] - '0' >= 0 && a[i] - '0' <= 9)
		{
			l[cnt] = a[i] - '0';
			cnt++;
		}
	}
	sort(l,l + cnt,ans);
	for(int i = 0;i < cnt;i++)
	{
		cout << l[i];
	}
	
	return 0;
}
