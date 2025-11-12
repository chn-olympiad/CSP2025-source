#include <bits/stdc++.h>
using namespace std;
int a[100005][5],s[5][100005],cnt[5],n,ans;
bool cmp1(int x,int y)
{
	return a[x][1]-max(a[x][2],a[x][3])<a[y][1]-max(a[y][2],a[y][3]);
}
bool cmp2(int x,int y)
{
	return a[x][2]-max(a[x][1],a[x][3])<a[y][2]-max(a[y][1],a[y][3]);
} 
bool cmp3(int x,int y)
{
	return a[x][3]-max(a[x][1],a[x][2])<a[y][3]-max(a[y][1],a[y][2]);
}
void solve()
{
	int i,j;
	memset(cnt,0,sizeof(cnt));
	ans=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		int maxn=-1,pos;
		for(j=1;j<=3;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]>maxn) maxn=a[i][j],pos=j;
		}
		cnt[pos]++;
		s[pos][cnt[pos]]=i;
	}
	//1
	sort(s[1]+1,s[1]+cnt[1]+1,cmp1);
	for(i=1;i<=cnt[1]-n/2;i++)
	{
		ans+=max(a[s[1][i]][2],a[s[1][i]][3]);
	}
	for(i=max(cnt[1]-n/2+1,1);i<=cnt[1];i++)
	{
		ans+=a[s[1][i]][1];
	}
	//2
	sort(s[2]+1,s[2]+cnt[2]+1,cmp2);
	for(i=1;i<=cnt[2]-n/2;i++)
	{
		ans+=max(a[s[2][i]][1],a[s[2][i]][3]);
	}
	for(i=cnt[2]-n/2+1;i<=cnt[2];i++)
	{
		ans+=a[s[2][i]][2];
	}
	//3
	sort(s[3]+1,s[3]+cnt[3]+1,cmp3);
	for(i=1;i<=cnt[3]-n/2;i++)
	{
		ans+=max(a[s[3][i]][2],a[s[3][i]][1]);
	}
	for(i=cnt[3]-n/2+1;i<=cnt[3];i++)
	{
		ans+=a[s[3][i]][3];
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
} 
