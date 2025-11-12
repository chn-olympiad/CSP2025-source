#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	int mb=a[1];
	sort(a+1,a+1+n*m,cmp);
	for (int i=1;i<=n*m;i++)
		if (a[i]==mb)
		{
			mb=i;
			break;
		}
	int h=0,l=1;
	for (int i=1;i<=mb;i++)
	{
		if (l%2==1) h++;
		else h--;
		if (h>n) h=n,l++;
		if (h<1) h=1,l++;
	}
	cout << l << " " << h;
	return 0;
}
