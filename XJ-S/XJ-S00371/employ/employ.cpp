#include<bits/stdc++.h>
using namespace std;
struct node
{
	int s,c,bh;
}a[505];
bool cmp(node x,node y)
{
	return x.s>y.s;
}
int q[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		a[i].s=s[i]-'0';
	}
	for(int i=0;i<n;i++)
		cin>>a[i].c;
	sort(a,a+n,cmp);
	int flag=1;
	for(int i=0;i<n;i++)
		if(a[i].s==0)
			flag=0;
	q[1]=1;
	for(int i=2;i<=n;i++)
	{
		q[i]=q[i-1]*i;
	}
	if(n==m&&flag==1)
	{
		cout<<q[n];
		return 0;
	}
	
	return 0;
}
