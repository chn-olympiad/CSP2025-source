#include<bits/stdc++.h>
using namespace std;
int n,m,t,tp;
int a[400];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);   cin.tie(0);
	cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
    	cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==t)
		{
			tp=i;
		}
	}
	if(tp<=n)
	{
		cout<<1<<' '<<tp;
		return 0;
	}
	else if((tp/n+1)%2==1)
	{
	    cout<<(tp/n)+1<<' '<<tp%n;	
	}
	else
	{
		cout<<(tp/n)+1<<' '<<n-(tp%n)+1;
	}
	return 0;
} 
