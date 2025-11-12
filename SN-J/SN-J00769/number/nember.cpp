#include<bits/stdc++.h>
using namespace std;


int main()
{
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	string a;
	int n,q;
	int m=1;
	int b=0;
	cin >> a;
	int p=0;
	while(true)
	{
		if(a[p] == a[-1])
		{
			break;
		}
		p++;
	}
	int x[p];
	for(int i=0;i < p;i++)
	{
		if(a[i]>=0 && a[i]<=9)
		{
			x[b] = a[i];
			b++;
		}
	}
	if(b == 0)
	{
		cout << x[0] << endl;
		return 0;
	}
	for(int i=0;i<b;i++)
	{
		for(int j=0;i<b;j++)
		{
			if(x[j] < x[j+1]);x[j],x[j+1] = x[j+1],x[j];
		}
	}
	for(int i=0;i<b;i++)
	{
		for(int j=b;j>=i;j--)
		{
			m *= 10;
		}
		q += x[i]*m;
		m = 0;
	}
	cout << q << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
