#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1005;
int n,m,a[MAXN],p;
bool cmp(int x,int y)
{
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==R)p=i;
	}
	int c=(p%(2*m));
	int cn=(p/(2*m))*2+1;
	int cm=0;
	if(c>n)
	{
		cn++;
		cm=n-c%n+1;
	}
	else cm=c;
	cout<<cn<<" "<<cm;
	return 0;
}
