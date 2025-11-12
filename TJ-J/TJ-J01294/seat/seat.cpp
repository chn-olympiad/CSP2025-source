#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>
using namespace std;
struct node
{
	int s,id;
};
struct xy
{
	int x,y;
};
bool cmp(node x,node y)
{
	if(x.s!=y.s) return x.s<y.s;
	return x.id>y.id ;
}
node a[110];
node ans[20][20];
int x[110][1110];
int y[110][1110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i].s);
		a[i].id = i;
	}
	node a1 = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m/2;i++)
	{
		swap(a[i],a[n*m-i+1]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			ans[i][j] = a[(i-1)*n+j];
			x[ans[i][j].s][ans[i][j].id] = i;
			y[ans[i][j].s][ans[i][j].id] = j;
		}
		i++;
		if(i>n) break;
		for(int j=m;j>=1;j--)
		{
			ans[i][j] = a[(i-1)*n+(m-j+1)];
			x[ans[i][j].s][ans[i][j].id] = i;
			y[ans[i][j].s][ans[i][j].id] = j;
		}
	}
//	
//	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cout << ans[i][j].s << " ";
//		}
//		cout << endl;
//	}
	printf("%d %d",x[a1.s][a1.id],y[a1.s][a1.id]);
	return 0;		
}
