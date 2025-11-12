#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a,b;
}b[10000005];
long long int i,n,j,k;
bool cmp(node a,node b)
{
	return a.a<b.a;
}
string a;
int main()
{
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>a;
	n=a.size();
	for(i=0;i<n;i++)
	{
		if(a[i]>=48&&a[i]<=57)
		{
			b[++k].a=a[i]-'0';
		}
	}
	sort(b+1,b+1+k,cmp);
	if(b[k].a==0)
	{
		cout<<'0';
		return 0;
	}
	for(i=k;i>=1;i--)
	{
		cout<<b[i].a;
	}
	return 0;
}
