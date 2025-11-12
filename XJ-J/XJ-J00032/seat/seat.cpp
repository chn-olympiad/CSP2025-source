#include<bits/stdc++.h>
using namespace std;
long long int n,m,i,xiaoei,a[500],jishu;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	cin>>a[i];
	xiaoei=a[1];
	sort(a+1,a+1+n*m);
	for(i=n*m;i>0;i--)
	{
		jishu++;
		if(a[i]==xiaoei)
		{
			xiaoei=jishu;
			break;//3ci
	 	}
	}
	if(xiaoei<=n)
	{
		cout<<1<<" "<<xiaoei;
		return 0; 
	}
	if((xiaoei/n+1)%2==0)
	{
		cout<<xiaoei/n+1<<" "<<n-xiaoei%n+1;
		return 0;
	}
	cout<<xiaoei/n+1<<" "<<xiaoei%n;
	return 0;
}
