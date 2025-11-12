#include <bits/stdc++.h>
using namespace std;
long long n,m,s,ranks;
long long a[110],rank[110],t;
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
	{
		cin>>a[i];
	}
	if(n*m==1)
	{
		cout<<1<<' '<<1<<endl;
		return 0;
	}
	s=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		rank[a[i]]=i;
	}
	ranks=rank[s];
	t=1LL*ranks/n;
	if(ranks%n==0 and t%2==0)
		cout<<t<<' '<<1<<endl;
	else if(ranks%n==0 and t%2==1)
		cout<<t<<' '<<n<<endl;
	else if(t%2==0)
		cout<<t+1<<' '<<ranks-(t*n)<<endl;
	else if(t%2==1)
		cout<<t+1<<' '<<n-(ranks-(t*n))+1<<endl;
	return 0;
}
