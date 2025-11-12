#include <bits/stdc++.h>
using namespace std;
struct sco
{
	int val,ind;
}a[105];
int n,m,k;
bool cmp(sco x,sco y)
{
	return x.val>y.val;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].val;
		a[i].ind=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].ind==1)
		{
			k=i;
		}
	}
	/*for(int i=1;i<=n*m;i++)
	{
		int tmp=(i-1)/n;
		if(tmp%2==0)
		{
			cout<<tmp+1<<" "<<1+(i-1)%n;
		}
		else
		{
			cout<<tmp+1<<" "<<n-(i-1)%n;
		}
		cout<<'\n';
	}*/
	int tmp=(k-1)/n;
	if(tmp%2==0)
	{
		cout<<tmp+1<<" "<<1+(k-1)%n;
	}
	else
	{
		cout<<tmp+1<<" "<<n-(k-1)%n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}