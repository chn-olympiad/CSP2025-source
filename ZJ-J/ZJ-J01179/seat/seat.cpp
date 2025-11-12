#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,a,b;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i = 2;i <= n*m;i++)
	{
		cin>>b;
		if(b>a)
			cnt++;
	}
	a = cnt/n;
	cnt = cnt%n;
	if(a%2)
		b = n-cnt;
	else
		b = cnt+1;
	cout<<a+1<<' '<<b;
	return 0;
}
