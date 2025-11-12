#include<iostream>
using namespace std;
int n,m,R,tmp,rank,c,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>R;
	for(int i=2;i<=n*m;i++)
	{
		cin>>tmp;
		if(tmp>R)rank++;
	}
	c=rank/n;
	r=rank%n;
	if(rank%(2*n)>=n)r=n-r-1;
	cout<<c+1<<" "<<r+1;
	return 0;
}
