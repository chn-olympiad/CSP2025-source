//SN-J00922
#include<bits/stdc++.h>
using namespace std;
int n,m,it;
int a[110],x,ma[15][15];
bool cmp(int a,int b)
{
	return a>b;
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
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
//	cout<<x<<endl;
//	for(int i=1;i<=n*m;i++) cout<<a[i]<<" ";
	it=0;
	bool flag=true;
	for(int i=1;i<=m;i++)//lie
	{
		if(!flag) break;
		if(i%2==1 && flag)//da
		{
			for(int j=1;j<=n;j++)//hang
			{
				it++;
//				cout<<i<<" "<<j<<'\n';//
				if(a[it]==x)
				{
					cout<<i<<" "<<j;
//					cout<<x<<a[it]<<it;
					flag=false;
//					continue;
				}
			}
		}
		if(i%2==0 && flag)
		{
			for(int j=n;j>=1;j--)
			{
				it++;
//				cout<<i<<" "<<j<<'\n';//
				if(a[it]==x) 
				{
					cout<<i<<" "<<j;
					flag=false;
//					continue;
				}
			}
		}
	}
	return 0;
}
