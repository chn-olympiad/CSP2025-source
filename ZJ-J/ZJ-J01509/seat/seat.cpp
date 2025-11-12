#include <bits/stdc++.h>
using namespace std;
#define For(i,j,k) for(int i=j;i<=k;i++)
#define dFor(i,j,k) for(int i=j;i>=k;i--)
#define ll long long

int n,m;
int a[105];
int len;
int cheng;
int wei;

bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	len=n*m;
	For(i,1,len)
	{
		cin>>a[i];	
	}
	cheng=a[1];
	sort(a+1,a+len+1,cmp);
	For(i,1,len)
	{
		if(a[i] == cheng)
		{
			wei=i;
			break;
		}
	}
	int x=wei/n;
	if(wei%n!=0) x++;
	int y=wei%n;
	if(y==0) y=n;
	if(x%2==0) //xia -> shang
	{
		cout<<x<<" "<<(n+1-y)<<endl;
	}
	else // shang -> xia
	{
		cout<<x<<" "<<y<<endl;
	}
	return 0;
}
