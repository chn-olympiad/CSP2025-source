#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int n;
const int maxn=1e5+7;
int a[maxn][3];
//struct node{
//	int x,y,z;
//	int id;
//}p[maxn];
//bool cmp(node i,node j){
//	if(i.x!=j.x) return i.x>j.x;
//	if(i.y!=j.y) return i.y>j.y;
//	return i.z>j.z;
//}
int cnt[3];
ll ans;
void dfs(int x,ll sum,int n){
	if(x>n){
		ans=max(ans,sum);
		return;
	}
	for(int j=0;j<3;j++){
		if(cnt[j]<n/2){
			cnt[j]++;
			dfs(x+1,sum+a[x][j],n);
			cnt[j]--;
		}
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n;
		bool f1=1,f2=1;
		for(int i=1; i<=n; i++){
			for(int j=0;j<3;j++) cin>>a[i][j];
			if(a[i][1]!=0) f1=0;
			if(a[i][2]!=0) f2=0;
//			p[i].x=a[i][0];
//			p[i].y=a[i][1];
//			p[i].z=a[i][2];
//			p[i].id=i;
		}
		ans=0;
		if(n<=30){
			dfs(1,0,n);
		}else if(f1 && f2){
			vector<int> t;
			for(int i=1;i<=n;i++) t.push_back(a[i][0]);
			sort(t.begin(),t.end());
			for(int i=0;i<n/2;i++) ans+=t[i];
		}else if(f2){
			vector< pair<int,int> > t;
			for(int i=1;i<=n;i++)
				t.push_back({abs(a[i][1]-a[i][0]),i});
			sort(t.begin(),t.end());
			for(int i=n-1;i>=0;i--){
				int id=t[i].second;
				if(a[id][1]>a[id][0]){
					if(cnt[1]<n/2){
						cnt[1]++;
						ans+=a[id][1];
					}else{
						cnt[0]++;
						ans+=a[id][0];
					}
				}else{
					if(cnt[0]<n/2){
						cnt[0]++;
						ans+=a[id][0];
					}else{
						cnt[1]++;
						ans+=a[id][1];
					}
				}
			}
		}else{
			for(int i=1;i<=n;i++)
				ans+=max(ans,max(a[i][0],max(a[i][1],a[i][2])));
		}
		cout<<ans<<endl;
	//	sort(p+1,p+1+n,cmp);
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
