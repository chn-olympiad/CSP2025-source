#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,ad;
};
node a[105];
bool cmp(const node &a,const node &b)
{
	return a.v>b.v;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) {
		cin>>a[i].v;
		a[i].ad=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int f=0;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				f++;
				if(a[f].ad==1) 
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}	
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				f++;
				if(a[f].ad==1) {
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
