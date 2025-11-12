#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int T;
int n;
struct Node{
	int val[4];
	int oth_max;
}a[N];
vector<int> id[4];
signed main(){
#ifndef DEBUG
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
#endif
//	freopen("club\\club5.in","r",stdin);
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	for (cin>>T;T--;){
		cin>>n;
		for (int i=1;i<=3;i++) id[i].clear();
		for (int i=1;i<=n;i++)
			for (int j=1;j<=3;j++)
				cin>>a[i].val[j];
		for (int i=1;i<=n;i++){
			int mx=0;
			for (int j=1;j<=3;j++)
				mx=max(mx,a[i].val[j]);
			for (int j=1;j<=3;j++)
				if (mx==a[i].val[j]){
					id[j].push_back(i);
					break;
				}
		}
//		for (int i=1;i<=3;i++){
//			cerr<<i<<": ";
//			for (const int&x:id[i]) cerr<<x<<" ";
//			cerr<<" Debug\n";
//		}
		for (int i=1;i<=3;i++){
			if ((int)id[i].size()>(n>>1)){
				for (const int &x:id[i]){
					a[x].oth_max=0;
					for (int j=1;j<=3;j++)
						if (i!=j)
							a[x].oth_max=max(a[x].oth_max,a[x].val[j]);
				}
				sort(id[i].begin(),id[i].end(),[&](int x,int y){
					return a[x].val[i]-a[x].oth_max>a[y].val[i]-a[y].oth_max;
				});
				while ((int)id[i].size()>(n>>1)){
					int x=id[i].back();
					id[i].pop_back();
					for (int j=1;j<=3;j++)
						if (i!=j)
							if (a[x].val[j]==a[x].oth_max){
								id[j].push_back(x);
								break;
							}
				}
			}
		}
		int res=0;
		for (int i=1;i<=3;i++){
			for (const int &x:id[i])
				res+=a[x].val[i];
		}
		cout<<res<<"\n";
	}
}
/*
555 我的贪心对吗

补药假啊

求你了给我点分吧
*/