#include<bits/stdc++.h>
using namespace std;
int a[10000],n,c;
void dfs(int s,int k,int l)
{
	if(k>=n) return; 
	for(int i=l+1;i<=n;i++) 
	{
		if(k>1&&s>a[i])c++,c%=99844353;  
		dfs(s+a[i],k+1,i);
	}
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+1+n);
	dfs(0,0,0);
	printf("%d",c);
	return 0;
}