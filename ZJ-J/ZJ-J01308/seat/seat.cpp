#include<bits/stdc++.h>
using namespace std;
int a[105],cnt;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])
			cnt++;
	}
	cnt++;
	cout<<(cnt+n-1)/n<<" ";
	if(cnt%(2*n)>n)
	{
		cout<<n-((cnt-1)%n)<<endl;
	}
	else
	{
		cout<<(cnt-1)%n+1<<endl;
	}
	return 0;
}

