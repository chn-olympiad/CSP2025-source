#include<bits/stdc++.h>
//#define int long long
//#define pqg priority_queue<int,vector<int>,greater>
//#define pql priority_queue<int,vector<int> >
using namespace std;
int n,m;
int sp,c,r;
struct cg
{
	int z,id;
}a[1000];
bool cmp(cg x,cg y)
{
	return x.z>y.z;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].z;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)if(a[i].id==1)sp=i;
	c=sp/n;
	if(sp%n!=0)c++;
	if(c%2==1)r=sp%n;
	else r=n*c-sp+1;
	if(r==0)r=n;
	cout<<c<<" "<<r;
	return 0;
}
