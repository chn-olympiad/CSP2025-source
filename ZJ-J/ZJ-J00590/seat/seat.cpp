#include <bits/stdc++.h>
using namespace std;
struct node
{
	int val,id;
} a[110];
bool cmp(node x,node y)
{
	return x.val > y.val;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	int len = n * m;
	for(int i = 1;i <= len;i++)
	{
		scanf("%d",&a[i].val);
		a[i].id = i;
//		printf("%d:%d\n",a[i].id,a[i].val);
	}
	sort(a + 1,a + 1 + len,cmp);
	int w = 1;
//	printf("\n\n");
	for(int i = 1;i <= len;i++)
	{
		if(a[i].id == 1)
		{
			w = i;
			break;
		}
//		printf("%d:%d\n",a[i].id,a[i].val);
	}
//	printf("%d",w);
	int t1 = 1,t2 = 1;
	t1 = (w + n - 1) / n;
//	printf("lie:%d\n",t1);
	if(t1 % 2 == 1)
	{
		if(w % n == 0)
		{
			t2 = n;
		}
		else
		{
			t2 = w % n;
		}
	}
	else
	{
		if(w % n == 0)
		{
			t2 = 1;
		}
		else
		{
			t2 = n - (w % n) + 1;
		}
	}
	printf("%d %d",t1,t2);
	return 0;
}
