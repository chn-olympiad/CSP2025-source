#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;
int T;
int n,ans;
int a[MAXN][4];
int b[MAXN],cnt[4];
int c[MAXN];
struct node{
	int num,id;
}d[MAXN],e[MAXN],f[MAXN];
bool vis[MAXN];
bool cmp(int x,int y)
{
	return x > y;
}
bool cmp2(node a,node b)
{
	return a.num > b.num;
}
void dfs(int pos,int sum)
{
	if(pos == n+1)
	{
		ans = max(ans,sum);
		return ;
	}
	int tmp[4] = {cnt[0],cnt[1],cnt[2],cnt[3]};
	if(cnt[1]+1 <= n/2)
	{
		cnt[1]++;
		dfs(pos+1,sum+a[pos][1]);
	}
	cnt[0] = tmp[0],cnt[1] = tmp[1],cnt[2] = tmp[2],cnt[3] = tmp[3];
	if(cnt[2]+1 <= n/2)
	{
		cnt[2]++;
		dfs(pos+1,sum+a[pos][2]);
	}
	cnt[0] = tmp[0],cnt[1] = tmp[1],cnt[2] = tmp[2],cnt[3] = tmp[3];
	if(cnt[3]+1 <= n/2)
	{
		cnt[3]++;
		dfs(pos+1,sum+a[pos][3]);
	}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> T;
	while(T--)
	{
		memset(cnt,0,sizeof(cnt));
		memset(b,0,sizeof(b));
		cin >> n;
		bool All2is0 = 1,All3is0 = 1;
		long long sum = 0;
		for(int i = 1;i<=n;i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			sum += a[i][1] + a[i][2] + a[i][3];
			if(a[i][2] != 0) All2is0 = 0;
			if(a[i][3] != 0) All3is0 = 0;
		}
		ans = 0;
		if(n <= 10) dfs(1,0);
		else if(All2is0&&All3is0)
		{
			for(int i = 1;i<=n;i++) c[i] = a[i][1];
			sort(c+1,c+n+1,cmp);
			for(int i = 1;i<=n/2;i++) ans += c[i];
		}
		else if(All3is0)
		{
			for(int i = 1;i<=n;i++) d[i].num=a[i][1]-a[i][2],d[i].id = i;
			sort(d+1,d+n+1,cmp2);
			for(int i = 1;i<=n/2;i++)
			{
				ans += a[d[i].id][1];
			}
			for(int i = n/2+1;i<=n;i++)
			{
				ans += a[d[i].id][2];
			}
		}
		else
		{
			ans = sum;
			//cout << sum << endl;
			for(int i = 1;i<=n;i++)
			{
				d[i].num = -a[i][2]-a[i][3],d[i].id = i;
				e[i].num = -a[i][1]-a[i][3],e[i].id = i;
				f[i].num = -a[i][1]-a[i][2],f[i].id = i;
			}
			sort(d+1,d+n+1,cmp2);
			sort(e+1,e+n+1,cmp2);
			sort(f+1,f+n+1,cmp2);
			int pos1 = 1,pos2 = 1,pos3 = 1;
			int cnt1 = 0,cnt2 = 0,cnt3 = 0;
			for(int i = 1;i<=n;i++)
			{
				while(vis[d[pos1].id]) pos1++;
				while(vis[e[pos2].id]) pos2++;
				while(vis[f[pos3].id]) pos3++;
				//cout << vis[d[pos1].id] << " " << vis[f[pos2].id] << " " << vis[e[pos3].id] << '\n';
				int num1 = d[pos1].num,num2 = e[pos2].num,num3 = f[pos3].num;
				int id1 = d[pos1].id,id2 = e[pos2].id,id3 = f[pos3].id;
				//cout << id1 << " " << num1 << " " << id2 << " " << num2 << " " << id3 << " " << num3 << '\n';
				if(cnt1 >= n/2) num1 = -1e9;
				if(cnt2 >= n/2) num2 = -1e9;
				if(cnt3 >= n/2) num3 = -1e9;
				if(num1 >= num2 && num1 >= num3)
				{
					//cout << id1 << "被选走\n"; 
					ans += num1;
					vis[id1] = 1;
					pos1++;
					cnt1++;
				}
				else if(num2 >= num1 && num2 >= num3)
				{
					//cout << id2 << "被选走\n"; 
					ans += num2;
					vis[id2] = 1;
					pos2++;
					cnt2++; 
				}
				else if(num3 >= num1 && num3 >= num2)
				{
					//cout << id3 << "被选走\n"; 
					ans += num3;
					vis[id3] = 1;
					pos3++;
					cnt3++;
				}
			}
		}
		cout << ans << endl;
	}
    return 0;
}

