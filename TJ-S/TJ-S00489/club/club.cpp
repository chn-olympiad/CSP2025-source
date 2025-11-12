#include<bits/stdc++.h>
using namespace std;
int a[20005][5];
struct node
{
	int val,id,part;
};
struct node s[60005];
int v_part[5];
int v_id[20005];
bool cmp(node x,node y)
{
	return x.val > y.val;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,cnt = 0;
	cin>>t;
	for(int i = 1;i <= t;i++)
	{
		int n,cnt = 0;
		cin>>n;
		for(int j = 1;j <= n;j++)
		{
			for(int k = 1;k <= 3;k++)
			{
				cin>>a[j][k];
				s[++cnt] = {a[j][k],j,k};
			}
		}
		sort(s + 1,s + (3 * n) + 1,cmp);
		int visit = 1,into = 0,ans = 0;
		memset(v_part,0,sizeof(v_part));
		memset(v_id,0,sizeof(v_id));
		while(into < n && visit <= cnt)
		{
			while(v_part[s[visit].part] >= (n / 2) || v_id[s[visit].id] == 1)
			{
				visit++;
			}
			ans += s[visit].val;
			into++;
			v_part[s[visit].part]++;
			v_id[s[visit].id] = 1;
			visit++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
