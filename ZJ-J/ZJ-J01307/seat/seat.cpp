#include<bits/stdc++.h>
using namespace std;
int n,m,b[200],k;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>b[i];
	k=b[1];
	sort(b+1,b+n*m+1);
	int c;
	for(int i=1;i<=n*m;i++)
		if(b[i]==k)
			c=i;
	int t=n*m-c+1;
	int _y,_x,f;
	if(t/n==t*1.0/n)
		_y=t/n;
	else
		_y=floor(t*1.0/n)+1;
	if(_y==1)
	{
		printf("%d %d",_y,t);
		return 0;
	}
	f=t-(_y-1)*n;
//	cout<<f<<endl;
	if(_y%2==0)
		_x=n-f+1;
	if(_y%2==1)
		_x=f;
	printf("%d %d",_y,_x);
	return 0;
}
