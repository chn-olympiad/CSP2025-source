//SN-J01220 龚西贝 西安建筑科技大学附属中学
#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> l;
int logan(int all,int h_n,int j)
{
	all=all+l[j];
	long long cnt=0;
	if(h_n==1)
	{
		if(2*l[j]<all)
		{
//			cout<<all<<' ';
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if(h_n>=2)
	{
		for(int i=j+1;i<n;i++)
		{
			cnt+=logan(all,h_n-1,i);
			cnt=cnt%998244353;
		}
//		cout<<cnt<<endl;
		return cnt;
	}
}
int main()
{
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	cin>>n;
	int c=0;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		l.push_back(x);
	}
	if(n<=3)
	{
		if(n<=2)
		{
			cout<<0;
		}
		else
		{
			if(max(l[0],max(l[1],l[2]))<(l[0]+l[1]+l[2]))
			{
				cout<<1;
			}
		}
	}
//	for(int ii=3;ii<=n;ii++)
//	{
//		c+=logan(0,ii,0);
//		c=c%998244353;
//	}
//	cout<<c;
	return 0;
}
