#include<bits/stdc++.h>
using namespace std;
int n,m,idn,idm,x;
void nxt()
{
	if(idm&1)
	{
		if(idn==n)
		idm++;
		else
		idn++;
	}
	else
	{
		if(idn==1)
		idm++;
		else
		idn--;
	}
	return;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	idn=idm=1;
	cin>>n>>m;
	cin>>x;
	int op;
	for(int i=2;i<=n*m;i++)
	{
		cin>>op;
		if(op>x)
		{
			nxt();
		}
	}
	cout<<idm<<' '<<idn;
	return 0;
}
