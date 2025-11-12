//高浚然 SN-S00796 西安高新第一中学 
#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
const int MAXN=1e5+5;
int n,t,max_ans,tmp;
int a[MAXN][4];
int cnt[4];
void dfs(int x,int ans)
{
	if(x==n+1)
	{
		max_ans=max(ans,max_ans);
		return;
	}
	for(int i=1;i<=3;i++){
		ans+=a[x][i];
		cnt[i]++;
		x++;
		if(cnt[1] <= tmp && cnt[2] <= tmp && cnt[3] <= tmp) {
			dfs(x,ans);
		}
		x--;
		ans-=a[x][i];
		cnt[i]--;
	}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		memset(a,0,sizeof(0));
		memset(cnt,0,sizeof(0));
		max_ans=0;
		cin >> n;
		tmp=n/2;
		for(int i=1;i<=n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		dfs(1,0);
		cout << max_ans << endl;
	}
	return 0;
}
