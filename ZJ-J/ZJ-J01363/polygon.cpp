#include <bits/stdc++.h>
using namespace std;
int n,c[5005],ans;
bool pd(int sum,int maxn,int li)
{
	if(sum>2*maxn&&li>=3)
		return true;
	return false;
}
void bfs(int a,int b,int d)
{
	if(pd(a,b,d))
	{
		ans=(ans+1)%998224353;
		return;	
	}
	int e=a,f=b;
	for(int i=d;i<=n;i++)
	{
		e += c[i];
		f = max(f,c[i]);
		bfs(e,f,d+1);
		e = a;
		f = b;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	bfs(0,0,1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}