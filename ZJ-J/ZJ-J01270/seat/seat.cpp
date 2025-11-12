#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[107];
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
	}
	int k = a[1];
	sort(a+1,a+n*m+1,cmp);
	int c;
	for(int i = 1;i <= n*m;i++)
	{
		if(a[i] == k)
		{
			c = i;
			break;
		}
	}
	int x = (c-1)/m+1,y = (c-1)%m+1;
	if(x % 2 == 0)y = m-y+1;
	printf("%d %d",x,y);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
