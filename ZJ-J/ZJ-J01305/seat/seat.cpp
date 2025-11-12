#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,stu[1010],R,pa;
	cin>>n>>m;
	int z=n*m;
	for(int i=1;i<=z;i++)
	{
		cin>>stu[i];
		if(i==1)
		{
			R=stu[i];
		}
	}
	sort(stu+1,stu+z+1,cmp);
	for(int i=1;i<=z;i++)
	{
		if(stu[i]==R)
		{
			pa=i;
			break;
		}
	}
//	cout<<pa<<endl;//dubug! pa is correct
	for(int i=n;i<=z;i+=n)
	{
		if(i>=pa)
		{
			int zu=i/n;
			//zu is correct
			if(zu%2==0)
			{
				cout<<zu<<' '<<i-pa+1;
				break;
			}
			else
			{
				cout<<zu<<' '<<pa-(zu-1)*n;
				break;
			}
		}
	}
	return 0;
}
