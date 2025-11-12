#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[n*m];
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	int s=0;
	for(int i=0;i<n*m;i++)
	{
		if(a[0]<a[i])
		{
			s++;
		}
	}
	if(s<n)
	{
		cout<<"1"<<" "<<1+s;
	}
	else if(s==n)
	{
		cout<<"2"<<" "<<n;
	}
	else
	{
		if((((s+1)/n)+1)%2==0)
		{
			cout<<(s+1)/n+1<<" "<<n-((s+1)%n)-1;
		}
		else
		{
			cout<<(s+1)/n+1<<" "<<(s+1)%n;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
