//李心恒 SN-S00339 西安铁一中滨河高级中学
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int n;
int a[N][5];
int num[5];
int v[N];
pair<int ,pair<int ,int > >b[N*5];
int ans;
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	int T;cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			b[i]={a[i][1]-max(a[i][2],a[i][3]),{i,1}};
			b[i+n]={a[i][2]-max(a[i][1],a[i][3]),{i,2}};
			b[i+2*n]={a[i][3]-max(a[i][2],a[i][1]),{i,3}};
		}
		sort(b+1,b+3*n+1);
		for(int i=3*n;i>=1;i--){
//			cout<<i<<'\n';
//			cout<<b[i].first<<'\n';
			int per=b[i].second.first;
			int zu=b[i].second.second;
			if(v[per]) continue;
			if(num[zu]==(n/2)) continue;
			v[per]=1;
			num[zu]++;
			ans+=a[per][zu];
//			cout<<per<<' '<<zu<<'\n';
		}
		cout<<ans<<'\n';
		for(int i=1;i<=3;i++) num[i]=0;
		for(int i=1;i<=n;i++) v[i]=0;
	}
	return 0;
}
/*
1
10
6839 5455 15586
11767 12919 2643
13775 8904 19938
13717 11997 15170
13707 2404 17497
3471 2462 8073
18467 14346 18663
13582 4839 15785
11875 7476 12308
8568 3134 18522


*/
