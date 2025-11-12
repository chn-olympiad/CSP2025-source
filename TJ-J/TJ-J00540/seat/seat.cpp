#include<iostream> 
#include<algorithm>
using namespace std;
int n,m;
bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[105]={},a1,a1i;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	a1=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==a1)
		{
			a1i=i+1;
			break;
		}
	}
	//cout<<a1i;
	int x=a1i/n;
	x+=(bool)(a1i%n>0);
	int y;
	if(x%2==1)
	{
		y=(a1i-1)%n+1;
	}
	else
	{
		y=n-((a1i-1)%n);
	}
	cout<<x<<' '<<y<<endl;
	return 0;
}
