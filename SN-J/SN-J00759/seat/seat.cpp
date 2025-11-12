#include<bits/stdc++.h>
using namespace std;
int x,y;
int a[1005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y;
	int ans=x*y;
	for(int i=1;i<=ans;i++)
	{
		cin>>a[i];
	}
	int s=a[1];
	sort(a+1,a+ans+1);
	int num;
	for(int i=ans;i>=1;i--)
	{
		if(a[i]==s)
		{
			num=i;
			break;
		}
	}
	num=ans-num+1;
	int l,h;
	if(num%x==0)
	{
		l=num/x;
		h=x;
	}
	else
	{
		l=num/x+1;
		h=num%x;
	}
	cout<<l<<" ";
	if(l%2==0)
	{
		h=x-h+1;
	}
	cout<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
