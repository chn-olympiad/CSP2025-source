#include <bits/stdc++.h>
using namespace std;
string s;
int num;
char a[1000005];
bool cmp(int x,int y)
{
	return x<y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i=0;i<s.size();i++)
	{
		if (s[i]>='0' && s[i]<='9')
		{
			num++;
			a[num]=s[i];
			
		}
	}
	sort(a+1,a+num+1,cmp);
	for (int i=num;i>=1;i--)
	{
		cout << a[i];
	}
	return 0;
}
