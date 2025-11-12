#include<bits/stdc++.h>
using namespace std;
struct f
{
	int x,y,z;
} b[1500010];
bool cmp(f a,f b)
{
	if(a.z!=b.z) return a.z<b.z;
	else if(a.x!=b.x) return a.x<b.x;
	else return a.y<b.y;
}
int n,a[500010],k,t,ans,top,j,l;
bool c[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		t=a[i];
		for(int j=i;j<=n+1;j++)
			if(t==k) 
			{
			b[++top].x=i;
			b[top].y=j;
			b[top].z=j-i+1;
			break;
			}
			else if(i==j) t=a[i];
			else t^=a[j];
	}
	sort(b+1,b+top+1,cmp);
	for(int i=1;i<=top;i++)
	{
		for(j=b[i].x;j<=b[i].y;j++)
			if(c[j]==1) break;
			else c[j]=1;
		if(j==b[i].y+1) ans++;
	}
	cout<<ans;
	return 0;
}
