#include <bits/stdc++.h>
using namespace std;
int n,m,pos;
int a[1010];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>a[1];
	pos=a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+m*n+1,greater<int>());
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==pos)
		{
			pos=i;
			break;
		}
	}
	//cout<<pos;
	if(pos%n==0)
	{
		if(pos/n%2==1) cout<<pos/n<<' '<<n;
		else if(pos/n%2==0) cout<<pos/2<<" "<<1;
		return 0;
	}
	else
	{
		//cout<<"56666";
		int cnt=pos/n;
		if(cnt%2==0)
		{
			cout<<cnt+1<<" "<<pos%n;
		}
		else if(cnt%2==1)
		{
			cout<<cnt+1<<" "<<n-pos%n+1;
		}
	}
	return 0;
}