#include<bits/stdc++.h>
using namespace std;
int n,m;
struct xx{
	int kao;
	int nums;
}a[105];
int now_ans=1;
bool flag=true;
bool cmp(xx a,xx b)
{
	return a.kao>b.kao;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].kao;
		a[i].nums=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(flag==true)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[now_ans].nums==1)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				now_ans++;
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				if(a[now_ans].nums==1)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				now_ans++;
			}
		}
		flag=!flag;
	}
	
	return 0;
}
