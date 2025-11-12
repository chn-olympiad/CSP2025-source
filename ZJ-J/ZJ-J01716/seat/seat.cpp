#include<bits/stdc++.h>
using namespace std;
long long n,m,l,hang,lie,r;
struct node
{
	int val,num;
};
node a[1010];
bool cmp(node x,node y)
{
	return x.val>y.val;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	l=n*m;
	for(int i=1;i<=l;i++)
	{
		cin>>a[i].val;
		a[i].num=i;
	}
	sort(a+1,a+1+l,cmp);
	for(int i=1;i<=l;i++)
	{
		if(i%n==0)	
		{
			lie=i/n;
		}	
		else if(i%n!=0)
		{
			lie=i/n+1;
		}
		r=i%(2*n);
		if(r==0) r=2*n;
		if(r<=n)
		{
			hang=r;
		}
		else
		{
			hang=2*n-r+1;
		}
		if(a[i].num==1)
		{
			cout<<lie<<" "<<hang<<endl;
			return 0;
		}
	}		
}//100pts 已检查
//2 2
//98 99 100 97
//2 2

//3 3
//94 95 96 97 98 99 100 93 92
//3 1