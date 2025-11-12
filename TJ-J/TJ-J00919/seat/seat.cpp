#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>
#include<map>
#include<deque>
#include<set>
#define ll long long
using namespace std;
const int N=105;
int n,m,hang,lie,a[N],dp,mo,dm,pos,c,r;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	dp=n*m;
	for(int i=1;i<=dp;i++)
	{
		cin>>a[i];
	}
	pos=1;
	for(int i=1;i<dp;i++)
	{
		for(int j=i+1;j<=dp;j++)
		{
			if(a[i]<a[j])
			{
				if(pos==i)
				{
					pos=j;
				}else if(pos==j)
				{
					pos=i;
				}
				swap(a[i],a[j]);
			}
		}
	}
	mo=pos%n;
	dm=pos/n;
	if(mo>0)
	{
		dm++;
	}
	c=dm;
	if(c==1)
	{
		cout<<1<<" "<<pos;
		return 0;
	}
	if(c&1)
	{
		r=mo;
	}else{
		r=n-mo+1;
	}
	cout<<c<<" "<<r;
	return 0;
}

