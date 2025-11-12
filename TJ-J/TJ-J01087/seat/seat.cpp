#include <bits/stdc++.h>
using namespace std;
int cc=0;
bool cmp(int a,int b)
{
	if(a>b)
		return true;
	else
		return false;
}
int db(int yy,int ff,int nn)
{
	int nnn=nn;
	if(yy%2==1)
	{
		int z=ff%nn;
		for(int i=0;i<=z;i++)
		{
			nnn=1+i;
		}
		return nnn;
	}
	if(yy%2==0)
	{
		int z=ff%nn;
		for(int i=0;i<=z;i++)
		{
			nnn=nn-i;
		}
		return nnn;
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	int n,m,f;
	int cg[150];
	cin>>n>>m;
	if(n==1&&m==1)
	{
		cout<<n<<" "<<m;
		return 0;
	}
	for(int i=0;i<n*m;i++)
	{
		cin>>cg[i];
	}
	int a1=cg[0];
	sort(cg,cg+n*m,cmp);
	for(int i=0;i<n*m;i++)
	{
		if(cg[i]==a1)
		{
			f=i;
		}
	}
	int y=f/n+1;
	int x=db(y,f,n);
	cout<<y<<" "<<x;

	fclose(stdin);
	fclose(stdout);
	return 0;
} 
