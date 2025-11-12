//bqq miaomiaomiao
//100
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,id;
}a[110];
bool cmp(node x,node y)
{
	return x.x>y.x;
}
int main()
{
 	freopen("seat.in","r",stdin);
 	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].x,a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].id==1)
		{ 
			cout<<(i-1)/n+1<<" "<<(((i-1)/n+1)&1?(i-1)%n+1:n-((i-1)%n+1)+1)<<endl;
			break;
		}
	}
	return 0;
}