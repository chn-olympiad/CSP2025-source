/*
StarLight_Yuran_ovo
Never gonna give you up
cryout
JROI 2023~无限
Starlight OI 2024~无限
RP++
648647291436
*/
#include<bits/stdc++.h>
using namespace std;
const int N=114;
int n,m;
int a[N];
int x;
int nowx=1,nowy=1;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==x)
		{
			cout<<nowy<<' '<<nowx;
			return 0;
		}
		if(nowy%2==1)
		{
			nowx++;
			if(nowx>n)
			{
				nowx=n;
				nowy++;
			}
		}
		else if(nowy%2==0)
		{
			nowx--;
			if(nowx<1)
			{
				nowx=1;
				nowy++;
			}
		}
	}
	return 0;
}
