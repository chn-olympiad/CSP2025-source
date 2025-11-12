
// 张瑞轩 
//SN-J00391 
//高新第一学校 

#include <bits/stdc++.h>
using namespace std;
int n,a[5010],ans;
void dfs(int p,int ma,int sum,int last)
{
	if(p>=3&&sum>2*ma)
        ans++;
    if(last==n)
        return;
    for(int i = last+1;i<=n;i++)
    	dfs(p+1;max(ma,a[i],sum+a[i]),i)
}
int main()
{
	freopen("polygon.in","r",stdin)
	freopen("polygon.out","w",stdout)
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(0,0,0,0);
	cout<<ans
	return 0;
}
