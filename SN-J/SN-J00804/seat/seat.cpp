#include<bits/stdc++.h>
#define inf 105;
using namespace std;
int n,m;
int a;
int seat;
int seat_wei=1;
int hang,lie;
int main()
{
	//求进迷惑行为大赏 
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>seat;
	for(int i=2;i<=n*m;i++)
	{
		cin>>a;
		if(a>seat) seat_wei++;
	}
	hang=seat_wei/m;
	if(seat_wei%m!=0) hang++;
	if(seat_wei%m==0) lie=n;
	else if(hang%2==0) lie=n+1-(seat_wei%m);
	else lie=seat_wei%m;
	cout<<hang<<" "<<lie;
	return 0;
}
