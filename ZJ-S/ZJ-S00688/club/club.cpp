#include<bits/stdc++.h>
using namespace std;
const int N=200010;
struct node{
	vector<pair<int,int>> c;
	int mn;
}pe[N];
bool cmp(node a,node b){
	return a.mn>b.mn;
}
bool cmp2(pair<int,int> a,pair<int,int> b){
	return a.second>b.second;
}
int vis[N],d[N];
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int ans=0,cnt[4];
		memset(cnt,0,sizeof(cnt));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
			pe[i].c.clear();
		int maxn=n/2;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			pe[i].c.push_back({1,x});
			pe[i].c.push_back({2,y});
			pe[i].c.push_back({3,z});
			sort(pe[i].c.begin(),pe[i].c.end(),cmp2);
			pe[i].mn=pe[i].c[0].second-pe[i].c[1].second;
		}
		sort(pe+1,pe+n+1,cmp);
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				int v=pe[i].c[j].second,ver=pe[i].c[j].first;
				if(cnt[ver]==maxn){
					continue;
					pe[i].mn=pe[i].c[j].second-pe[i].c[j-1].second;
					sort(pe+1,pe+n+1,cmp);
				}
				ans+=v;
				cnt[ver]++;
				d[ver]=j;
				vis[ver]=true;
				break;
			}
		}

		cout<<ans<<'\n';
	}
	return 0;
}