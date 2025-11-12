#include<bits/stdc++.h>
using namespace std;
string s;
short a[1000010];
int len;
bool cmp(short x,short y)
{
	return x > y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s.c_str());
	for(int i = 0;i < s.size();i++) if(s[i] >= '0' && s[i] <= '9') a[++len] = s[i] - '0';
	sort(a + 1,a + len + 1,cmp);
	for(int i = 1;i <= len;i++) cout << a[i];
	return 0;
}
