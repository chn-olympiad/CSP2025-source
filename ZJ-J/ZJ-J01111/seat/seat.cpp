#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node
{
	int id,num;
}a[10001];
bool cmp(node A,node B)
{
	return A.num>B.num;
}
bool opt;
int nowr=0,nowl=1,cnt;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i].num,a[i].id=i;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		cnt++;
		if(opt)nowr--;
		else nowr++;
		if(nowr<1)nowr=1,nowl++,opt=0;
		if(nowr>n)nowr=n,nowl++,opt=1;
		if(a[cnt].id==1)
		{
			cout<<nowl<<" "<<nowr;
			return 0;
		}
	}
	return 0;
}

