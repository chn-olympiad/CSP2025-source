#include<bits/stdc++.h>
using namespace std;
int n,m,u,v,k,a[500005];
struct s
{
	int x,y;
}t[50000005];
bool f(s a,s b)
{
	if(a.y==b.y)return a.x>b.x;
	return a.y<b.y;
}
int main()
{
	freopen("xor.in","r",stdin),freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],a[i]^=a[i-1];
	for(int i=0;i<n;i++)for(int j=i+1;j<=n;j++)if((a[i]^a[j])==m)k++,t[k].x=i,t[k].y=j;
	sort(t+1,t+k+1,f);
	for(int i=1;i<=k;i++)if(t[i].x>=v)u++,v=t[i].y;
	cout<<u;
	return 0;
}
