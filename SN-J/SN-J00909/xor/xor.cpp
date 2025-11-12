//SN-J00909  臧家乐  西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,p;
int a[N];
int sum[N];
int num1,num0;
int cnt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);		cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==p)
			cnt++;
		if(a[i]==1)
			num1++;
		if(a[i]==0)
			num0++;
	}
	if(p==0 && num1==n)
	{
		cout<<n/2;
		return 0;
	}
	if(p<=1 && num1+num0==n)
	{
		if(p==1)
			cout<<num1;
		else
			cout<<num0;
		return 0;
	}
	cout<<cnt;
	return 0;
}
