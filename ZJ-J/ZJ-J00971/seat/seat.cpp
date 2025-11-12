#include<bits/stdc++.h>
using namespace std;
int n,m;
int k,flag;
bool ans[105];
int l=1,p;
void work(int seat)
{
	while(seat>n)
	{
		++l;
		seat-=n;
	}
	if(l%2==1)
	{
		p=seat;
	}
	else
	{
		p=n-seat+1;
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>k;
	ans[k]=true;
	int temp;
	for(int i=1;i<n*m;++i)
	{
		cin>>temp;
		ans[temp]=true;
	}
	for(int i=100;i>k;--i)
	{
		if(ans[i]) 
		{
			++flag;
		}		
	}
	work(flag+1);
	cout<<l<<' '<<p;
	return 0;
}
