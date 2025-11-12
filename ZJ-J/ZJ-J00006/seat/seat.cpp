#include<bits/stdc++.h>
using namespace std;
int k,a[110],n,m;
int cmp(int a,int b)
{
	return a>b;
}
void dfs(int x,int y,int s)
{
	if(a[s]==k)
	{
		cout<<y<<" "<<x<<endl;
		exit(0);
	}
	if(x==n&&(y%2==1)) dfs(n,y+1,s+1);
      else if(x==1&&(y%2==0)) dfs(1,y+1,s+1);
        else if(y%2==1) dfs(x+1,y,s+1);
          else if(y%2==0) dfs(x-1,y,s+1);
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	dfs(1,1,1);
	return 0;
}