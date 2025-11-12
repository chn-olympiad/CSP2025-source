#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int c=a*b;
	int d[c];
	for(int i=0;i<c;i++)
	{
		cin>>d[i];
	}
	int e=d[0];
	sort(d,d+c);
	for(int i=0;i<c;i++)
	{
		if(d[i]==e) 
		{
			e=c-i;
			break;
		}
	}
	c=a*2;
	int p=e%c;
	if(p==0)
		p++;
	int q=e/a;
	if(q==0)
		q++;
	if(p>a)
		cout<<q+1<<' '<<c-e+1;
	else
		cout<<q<<' '<<p;
	return 0;
}
