#include <bits/stdc++.h>
using namespace std;
int a[1000005],j=0;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[j]=int(s[i]-'0');
			j++;
		}
	}
	sort(a,a+j,cmp);
	for(int i=0;i<j;i++) cout <<a[i];
	cout <<endl;
	return 0;
}
