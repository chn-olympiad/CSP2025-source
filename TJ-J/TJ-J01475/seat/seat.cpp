#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a,cnt;
	cin>>a;
	for(int i=1;i<n*m;i++)
	{
		int s;
		cin>>s;
		if(s>a)cnt++;
	}
	int x=cnt/n+1,y;
	if(x&1)
		y=(cnt%n)+1;
	else
		y=n-(cnt%n);
	cout<<x<<' '<<y;
	return 0;
}
