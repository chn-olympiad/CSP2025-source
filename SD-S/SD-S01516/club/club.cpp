#include<bits/stdc++.h>
using namespace std;
#define int long long
bool startmb;
constexpr int N=1e5+5;
int _,n,a[N][5],x[N];
int frm[N],b[N];
int cnt[5];
bool endmb;
main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cerr<<((&endmb-&startmb)/1024.0/1024)<<'\n';
	cin.tie(0)->sync_with_stdio(false);
	double starttime=clock();
	cin>>_;
	while(_--)
	{
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3],ans+=(x[i]=max({a[i][1],a[i][2],a[i][3]}));
		for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) if(x[i]==a[i][j]){frm[i]=j;cnt[j]++;break;}
		if(cnt[1]>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(frm[i]==1) b[i]=max(a[i][2]-a[i][1],a[i][3]-a[i][1]);
				else b[i]=LLONG_MIN;
			}
			sort(b+1,b+n+1,[](auto a,auto b){return a>b;});
			for(int i=1;i<=cnt[1]-n/2;i++) ans+=b[i];
		}
		if(cnt[2]>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(frm[i]==2) b[i]=max(a[i][3]-a[i][2],a[i][1]-a[i][2]);
				else b[i]=LLONG_MIN;
			}
			sort(b+1,b+n+1,[](auto a,auto b){return a>b;});
			for(int i=1;i<=cnt[2]-n/2;i++) ans+=b[i];
		}
		if(cnt[3]>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(frm[i]==3) b[i]=max(a[i][2]-a[i][3],a[i][1]-a[i][3]);
				else b[i]=LLONG_MIN;
			}
			sort(b+1,b+n+1,[](auto a,auto b){return a>b;});
			for(int i=1;i<=cnt[3]-n/2;i++) ans+=b[i];
		}
		cout<<ans<<'\n';
		cnt[1]=cnt[2]=cnt[3]=0;
	}
	cerr<<((clock()-starttime)/CLOCKS_PER_SEC)<<'\n';
	return 0;
}
/*
1
12
29346 7783 22590
24734 9539 6971
18746 14584 13157
20529 23037 9587
12222 28963 9170
19619 5675 17077
10566 16054 21726
8325 14983 8767
811 19841 30906
25172 13736 8605
22000 30947 15640
20524 11084 28521
*/
//多测要清空
//测极端数据
//注意数组大小
//注意保留小数位数
