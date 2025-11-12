#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int ans[5010];
int s;
void check(int x,int k,int sum)
{
	if(sum>a[k])s++;
	s%=998244353;
	for(int i=x;i<k;i++)
		check(i+1,k,sum+a[i]);
}
int main()
{	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3)cout<<0;
	else
	{
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+1+n);
		if(n==3)
		{
			if(a[1]+a[2]>a[3])cout<<1;
			else cout<<0;
		}
		for(int i=3;i<=n;i++)
		{
			check(1,i,0);
		}
		cout<<s;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
