#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b)
{
	return a>b;
}
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t,ff;
	cin>>n>>m;
	for(int i = 0;i<n*m;i++)
	{
		cin >> a[i];
		t=a[1];
	}
	sort(a,a+(n*m),cmp);
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==t)
		{
			if(i>i/n*n)//ºá×ø±ê 
			{
				ff=(i/n)+1;
				cout << ff+1 << ' ';
			}
			else if(i==((i/n)*n))
			{
				ff=i/n;
				cout <<ff+1 << ' ';
			}
			else
			{
				ff= 1;
				cout <<ff+1<< ' ';
			}
			if(ff%2==0)
			{
				cout << n-((i-1)-((i/n)*n))-1;
			}
			else
			{
				cout << i-((i/n)*n)+1;
			}
			break;
		}
	}
	return 0;
}


