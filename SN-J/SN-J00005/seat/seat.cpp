#include<bits/stdc++.h>
using namespace std;
int a[400],n,m,ma[105],b[400];
bool f(int x,int y)
{
	return x<y;
}
struct se
{
	int l,h;	
}ans;
se seat(int x)
{
	int t=x/n+1;
	int h=x%n;
	if(h==0)
	{
		t--;
		h=n;
	}
	if(t%2==0)
	{
		ans.l=t;
		ans.h=n-h+1;
	}
	else
	{
		ans.l=t;
		ans.h=h;
	}
	
	return ans;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int r;
	int c=n*m;
	for(int i=1;i<=c;i++)
	{
		cin>>a[i];
		if(i==1)
			r=a[i];
	}

	for(int i=1;i<=c;i++)
	{
		ma[a[i]]++;
	}
	int z=0;
	int k=0;
	for(int i=100;i>=0;i--)
	{
		if(ma[i]>0)
		{
			z++;
			b[z]=i;
			if(i==r)k=z;
		}
	}
	//for(int i=1;i<=c;i++)cout<<b[i]<<" ";
	//cout<<endl;
	se ans=seat(k);
	//cout<<k<<endl;
	cout<<ans.l<<" "<<ans.h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2 2
98 99 100 97
3 3
94 95 96 97 98 99 100 93 92
*/
