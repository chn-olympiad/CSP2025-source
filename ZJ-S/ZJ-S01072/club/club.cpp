//15:40 55分，尝试优化掉3次sort 
//15:50 每组数据从排序6次优化成排序1次，最大的样例没超时 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[100005][3];
vector<int> club[3];
bool vis[100005][3];
int l;
bool cmp(int x,int y) {
	int la = INT_MAX,lb = INT_MAX;
	if(vis[x][(l+1)%3]==0) {
		la = min(la,a[x][l]-a[x][(l+1)%3]);
	}
	if(vis[x][(l+2)%3]==0) {
		la = min(la,a[x][l]-a[x][(l+2)%3]);
	}
	if(vis[y][(l+1)%3]==0) {
		lb = min(lb,a[y][l]-a[y][(l+1)%3]);
	}
	if(vis[y][(l+2)%3]==0) {
		lb = min(lb,a[y][l]-a[y][(l+2)%3]);
	}
	return la>lb;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		cin>>n;
		memset(vis,0,sizeof(vis));
		club[0].clear();
		club[1].clear();
		club[2].clear();
		for(int i = 1; i<=n; i++) {
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]) {
				club[0].push_back(i);
			} else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]) {
				club[1].push_back(i);
			} else {
				club[2].push_back(i);
			}
		}
//		for(int i = 0;i<3;i++){
//			for(int j = 0;j<club[i].size();j++){
//				cout<<club[i][j]<<" ";
//			}
//			cout<<endl;
//		}
			for(l = 0; l<3; l++) {
				if(club[l].size()<=n/2){
					continue;
				}
				sort(club[l].begin(),club[l].end(),cmp);
//				for(int i = 0;i<club[l].size();i++){
//					cout<<club[l][i]<<" ";
//				}
//				cout<<endl;
				for(int i = club[l].size()-1; i>=n/2; i--) {
					int la = INT_MAX,lb = INT_MAX;
					if(vis[club[l][i]][(l+1)%3]==0){
						la = a[club[l][i]][l]-a[club[l][i]][(l+1)%3];
					}
					if(vis[club[l][i]][(l+2)%3]==0){
						lb = a[club[l][i]][l]-a[club[l][i]][(l+2)%3];
					}
					vis[club[l][i]][l] = 1;
					if(la>lb){
						club[(l+2)%3].push_back(club[l][i]);
						club[l].pop_back();
					}
					else{
						club[(l+1)%3].push_back(club[l][i]);
						club[l].pop_back();
					}
				}
			}
		ll sum = 0;
//		cout<<endl;
		for(int i = 0;i<3;i++){
			for(int j = 0;j<club[i].size();j++){
//				cout<<club[i][j]<<" ";
				sum += a[club[i][j]][i];
			}
//			cout<<endl;
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
