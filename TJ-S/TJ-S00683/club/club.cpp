#include<iostream>
using namespace std;
int t,n,m;
int v[4]={0},lis[100005][4]={0};
void dfs(int a,int b)
{
	if(a>n)
	{
		m=max(m,b);
		return;
	}
	if(v[1]<n/2)
	{
		v[1]++;
		dfs(a+1,b+lis[a][1]);
		v[1]--;
	}
	if(v[2]<n/2)
	{
		v[2]++;
		dfs(a+1,b+lis[a][2]);
		v[2]--;
	}
	if(v[3]<n/2)
	{
		v[3]++;
		dfs(a+1,b+lis[a][3]);
		v[3]--;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		v[1]=v[2]=v[3]=m=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>lis[i][1]>>lis[i][2]>>lis[i][3];
		dfs(1,0);
		cout<<m<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
