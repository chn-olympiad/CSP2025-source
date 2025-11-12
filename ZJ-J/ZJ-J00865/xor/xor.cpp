#include <iostream>
using namespace std;
int n,k,ans;
int a[500010];
int xo(int x, int y);
void dfs(int l,int r,int s,int cnt);
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&a[i]);
	}
	dfs(1,1,0,a[1]);
	cout << ans << endl;
	return 0;
}
void dfs(int l,int r,int s,int cnt)
{
	if(l > n)
	{
		ans = max(ans,s);
		return;
	}
	if(r>n)
	{
		ans = max(ans,s);
		dfs(l+1,l+1,0,a[l+1]);
		return;
	}
//	int now = a[l];
//	for(int i = l+1; i <= r; i++)
//	{
//		now = xo(now,a[i]);
//	}
	if(cnt == k)
		dfs(r+1,r+1,s+1,a[r+1]);
	else dfs(l,r+1,s,xo(cnt,a[r+1]));
}
int xo(int x, int y)
{
	int sum[30];
	int ansn = 0;
	int i = 0;
	while(x!=0||y!=0)
	{
		i++;
//		cout << x << " " << y << endl;
		if(x%2==y%2)
			sum[i]=0;
		else sum[i]=1;
		x=x>>1;
		y=y>>1;
	}
//	cout << sum << endl;
//	for(int j = 1; j <= i; j++)
//	    cout << sum[j];
	for(int j = i; j >= 1; j--)
	    ansn = ansn*2+sum[j];
	return ansn;
}
//#Shang4Shan3Ruo6Shui4
//xor
/*
4 3
2 1 0 3
4 0
2 1 0 3

*/
