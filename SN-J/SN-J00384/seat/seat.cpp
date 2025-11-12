//SN-J00384  张溪诺  西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
int pp,qq;
struct node{
	int num,id;
}a[1010];
bool cmp(node a,node b)
{
	return a.num>b.num;
}
void cheak(int x)
{
	pp=(x+n-1)/n;
	int op=x%n;
	if(op==0)op=n;
	if(pp%2==0)qq=n-op+1;
	else qq=op;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		a[i].id=i;
		cin>>a[i].num;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].id==1)
		{
			cheak(i);
			break;
		}
	}
	cout<<pp<<" "<<qq;
	return 0;
}

