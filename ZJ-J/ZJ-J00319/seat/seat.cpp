#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k,f;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(k==a[i])
		{
			f=n*m-i+1;
			break;
		}
	}
//	cout<<f<<endl;
	int x,y;
	y=f/n+1;
	x=f%n;
	if(x==0)
	{
		x=n;
		y--;
	}
	if(y%2==1)
	{
		cout<<y<<" "<<x;
	}
	if(y%2==0)
	{
		cout<<y<<" "<<n-x+1;
	}
	/*
		What can I say?
		Hhahahahaha...
		Man!
		The Germany in KARDS will be cut more.I think 1939's parents is died.It's because I have used many siliver cards and
		gold cards in Germany that I feel so angry and my face turn to red.If anyone read what I writted,please shout to 1939
		with me:"f*** your m*****!"
	*/
	return 0;
}

