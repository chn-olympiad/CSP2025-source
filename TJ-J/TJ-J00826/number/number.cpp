#include <bits/stdc++.h>
using namespace std;
int cmp(int a,int b);
{
	if (a<b)
	{
		int x=a;
		a=b;
		b=x;
	}
	return a,b;
}
int a[1000005];
string n;
int main ()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>n;
	for (int i=0;i<=n.lengh();i++)
	{
		if(n[i]>='0'&&n[i]<='9')
		{
			a[i]=n[i];
		}	
	}
	sort(a,a+n,cmp);
	for (int i=0;i<=n.lengh();i++)
	{
		cout <<(int)a[i];
	}
	return 0;
}
