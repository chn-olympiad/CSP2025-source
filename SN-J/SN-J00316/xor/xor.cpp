//MS Attached to NWPU SN-J00316 Zhang Yuanhao
#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500003];
struct node
{
	int l,r;
}ok[1000003];
bool cmp(node a,node b)
{
	return a.l<b.l;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> k;bool flg=1;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]!=0&&a[i]!=1)
			flg=0; 
	}
	if(k==1&&flg)
	{
		int _=0;
		for(int i=1;i<=n;i++)
			if(a[i]==1) _++;
		cout << _;
		return 0;
	}
	if(k==0&&flg)
	{
		cout << n/2;
		return 0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int yhs=a[i];
			for(int k=i+1;k<=j;k++)
			{
				yhs^=a[k];
			}
			if(yhs==k) 
			{
				ok[++cnt].l=i;
				ok[cnt].r=j;
			}
		}
	}
	sort(ok+1,ok+cnt+1,cmp);
	int nowl=ok[1].l,minn=100000000,ans=0;
	for(int i=1;i<=cnt;)
	{
		while(ok[i].l<=nowl)
		{
			if(ok[i].r>minn)
				minn=ok[i].r;
			i++;
			if(i>cnt) break;
		}
		nowl=minn+1;
		ans++;
	}
	cout << ans;
	return 0;
}
//9:21 bu hui xie,QwQ
//9:24 kan le hui da yang li,
//     xian ba special ABC luan gao chu lai ba UwU
//9:28 wo yao xie dfs bao sou!!!!!!!!!!!!!!!!!!OwO
//9:31 tril zhu wo!!!!!!!!!!!QvQ
//9:34 Geopelia help me plz..........
//9:35 kan T4 qu le /fn
//11:01 I'm back!
//11:04 eat the 3rd pack of chocolate bar
//11:43 bao li xie fei le QwQwQwQwQwQwQwQ 
