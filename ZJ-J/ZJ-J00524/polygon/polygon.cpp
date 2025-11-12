#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n,a[N],cnt=0;
void check(int x,int p,int u)
{
	if(x>p)
	{
		return ;
	}
	for(int i=x+1;i<=p;i++)
	{
		if(u+a[i]>a[p+1])
		cnt++;
		cnt%=998244353;
		check(i,p,u+a[i]);
	}
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	check(0,i-1,0);
	cout<<cnt<<endl;
	return 0;
}
