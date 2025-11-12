#include<bits/stdc++.h>
using namespace std;
struct qiu
{
	int zhi,x;
};
qiu a[1000005];
int n,m,hang=0,lie=1,f=false;
bool cmp(qiu x,qiu y)
{
	return x.zhi>y.zhi;
}
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
		cin>>a[i].zhi;
		a[i].x=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(f==false)
		{
			hang++;
			if(hang<=n&&a[i].x==1)
			{
				cout<<lie<<" "<<hang;
				return 0;
			}
			else if(hang>n)
			{
				hang-=1;
				lie++;
				if(hang<=n&&a[i].x==1)
				{
					cout<<lie<<" "<<hang;
					return 0;
				}
				f=true;
			}
		}
		else if(f==true)
		{
			hang--;
			if(hang>=1&&a[i].x==1)
			{
				cout<<lie<<" "<<hang;
				return 0;
			}
			else if(hang<=0)
			{
				lie++;
				hang+=1;
				if(hang>=1&&a[i].x==1)
				{
					cout<<lie<<" "<<hang;
					return 0;
				}
				f=false;
			}
		}
	}
	return 0;
}