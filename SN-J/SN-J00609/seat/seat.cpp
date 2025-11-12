//西安高新二中  杨嘉乐  SN-J00609 
#include<bits/stdc++.h>
using namespace std;
int a[105],b[105],n,m,s,num,l,h;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==s)
		{
			num=n*m-i+1;
		}
	}
		l=(num-1)/n+1;
		cout<<l<<" ";
		if((l%2)==1)
		{
			h=num-(l-1)*n;
			cout<<h;
		}
		else if((l%2)==0)
		{
			h=n-(num-(l-1)*n)+1;
			cout<<h;
		}
	
	return 0;
}
