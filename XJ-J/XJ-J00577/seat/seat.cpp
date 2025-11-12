#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int n,m,num[N];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>num[i];
	int a=num[1],b;
	sort(num+1,num+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(num[i]==a)
		{
			b=i;
			break;
		}
	int x,y;
	if(b%n==0)
		x=b/n,y=n;
	else
		x=b/n+1,y=b%n;
	if(x%2==1)
		cout<<x<<' '<<y;
	else
		cout<<x<<' '<<n-y+1;
	return 0;
}
