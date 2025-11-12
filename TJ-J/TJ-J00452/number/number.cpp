#include <bits/stdc++.h>
using namespace std;
int cmp(int x,int y)
{
	return x>y;
}
string a;
int main ()
{
	freopen("number.in","r","stdin");
	freopen("number.out","w","stdout");
	cin >> a;
	char c[100000];
	int n=a.length(),b=0;
	for (int i=0;i<n;i++)
	{
		if(a[i]>='0' && a[i]<='9')
		{
			b++;
			c[b]=a[i];
		}
	}
	sort(c+1,c+b+1,cmp);
	for (int i=1;i<=b;i++)
		cout << c[i];
	return 0;
}
