#include<bits/stdc++.h>
using namespace std;
int n,m,a[10010],k,p;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1 ; i <= n * m ; i++)
	{
		cin>>a[i];
	}
	k = a[1];
	sort(a+1,a+n*m+1);
	for(int i = 1 ; i <= n * m ; i++)
	{
		if(k == a[i])
		{
			p = n*m-i+1;
			break;
		}
	}

	int q = (p-1) / n + 1;
	cout<<q<<" ";
	p%=n;
	if(p == 0)p = n;
	if(q % 2 == 1)
	{
		cout<<p;
	}
	else
	{
		cout<<n-p+1;
	}

	return 0;
}

