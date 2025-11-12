#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int x,y=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>a[1];
	int R=a[1];
	for(int i=2;i<=n*m;i++)
		cin>>a[i];
	sort(a+1,a+n*m+1,greater<int>());
	int op=0;
	for(int i=1;i<=m*n;i++)
	{
		if(op==0) x++;
		else x--;
		if(x>n) x=n,op=!op,y++;
		else if(x<=0) x=1,op=!op,y++;
		if(a[i]==R) break;
	}
	cout<<y<<" "<<x;
	return 0;
}
//mycode
