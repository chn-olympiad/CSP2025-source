#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=1e6+5;
int n,m,s,a,cnt=1,c,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a;
		if(i==1) s=a;
		if(a>s) cnt++;
	}
	if(cnt%n==0)
	{
		c=cnt/n;
		if(c%2==0) r=1;
		else r=n;
		cout<<c<<' '<<r<<endl;
		return 0;
	}
	else c=cnt/n+1;
	if(c%2==0) r=n-cnt%n+1;
	else r=cnt%n;
	cout<<c<<' '<<r<<endl;
	return 0;
}
