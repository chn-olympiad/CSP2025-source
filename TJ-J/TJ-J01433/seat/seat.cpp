#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
	return a<b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,a[10000]; 
	cin>>n>>m;
	for(int i =1;i<=n*m;i++)
	{
		cin>>a[i];//输入的是成绩 
	}
	int ch=a[1];
	sort(a,a+n*m,cmp);
	int p;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==ch)
		{
			p=i;
			break;
		}
	}
	cout<<p;
	
	
	
	
	return 0;
}
