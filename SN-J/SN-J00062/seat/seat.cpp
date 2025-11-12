#include<bits/stdc++.h>
using namespace std;
struct stu
{
	int sco;
	int cnt;
}a[110];
bool cmp(stu a,stu b)
{
	return a.sco>b.sco;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m,num=0;cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].sco;
		a[i].cnt=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].cnt==1)
		{
			int x=i/n;
			if(i%n!=0) x++;
			cout<<x<<" ";
			if(x%2==1)
			{
				if(i%n==0)  cout<<n;
				else  cout<<i%n;
			}
			if(x%2==0)
			{
				if(i%n==0)  cout<<1;
				else  cout<<n-i%n+1;
			}
			return 0;
		}
	}
} 
