#include<bits/stdc++.h>
using namespace std;
int sum=0;
int a[3]={1,2,3};
struct N{
	int st;
	int ed;
	int my;
	
};
int n,m,k;
N r[1000005];
int m1[1000005];
int main()
{
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>r[i].st>>r[i].ed>>r[i].my;
		m1[i]=r[i].my;
	}
	sort(m1,m1+m);
	sort(a,a+3);
	//cout<<a[0]<<a[1]<<a[2];
	for(int i=m;i>m-n-1;i++)
	{
		sum+=m1[i];
	
	}
	cout<<sum;
	
	return 0;
}
