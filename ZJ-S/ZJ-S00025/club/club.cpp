#include<bits/stdc++.h>
using namespace std;
int maxn,n;
int aa[100005][4];
void dfs(int a,int b,int c,int jia,int now)
{
	if(jia>maxn) maxn=jia;
	if(now>n) return;
	if(a<n/2) dfs(a+1,b,c,jia+aa[now][1],now+1);
	if(b<n/2) dfs(a,b+1,c,jia+aa[now][2],now+1);
	if(c<n/2) dfs(a,b,c+1,jia+aa[now][3],now+1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t; cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>aa[i][1]>>aa[i][2]>>aa[i][3];
		}
		maxn=-1;
		dfs(1,0,0,aa[1][1],2);
		dfs(0,1,0,aa[1][2],2);
		dfs(0,0,1,aa[1][3],2);			
		cout<<maxn<<endl;
	}
	return 0;
}
