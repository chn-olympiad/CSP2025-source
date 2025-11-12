#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int a[N],n,k;
int dis[N*4],t[N*4],ans[N],cnt,vis[N];
vector<int> G[N*4];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dis[i]=(dis[i-1]^a[i]);
		t[dis[i]]++;
		G[dis[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		int p=(dis[i-1]^k);
		if(k==a[i]){
			ans[i]=i;
			continue;
		}
		if(t[p]==0){
			ans[i]=0;
			continue;
		}
		int sz=G[p].size();
		int l=0,r=sz-1,ds;
		while(l<=r){
			int mid=(l+r)/2;
			if(G[p][mid]<i) l=mid+1;
			else r=mid-1,ds=mid;
		}
		if(ds>=sz||ds<0||G[p][ds]<i) ans[i]=0;
		else ans[i]=G[p][ds];
		t[a[i]]--;
	}
	for(int i=1;i<=n;i++)
		if(ans[i]==0) vis[i]=-1;
	int l=1,r=1;
	while(vis[l]==-1&&l<=n) l++;
	r=l+1;
	while(vis[r]==-1&&r<=n) r++;
	while(l<=n&&r<=n){
		if(l>r) swap(l,r);
		if(ans[l]>=ans[r]){
			vis[l]=-1;
			l++;
			while(vis[l]==-1&&l<=n) l++;
			if(l==r){
				r++;
				while(vis[r]==-1&&r<=n) r++;
			}
		}
		else if(ans[l]<ans[r]&&ans[l]>=r){
			vis[r]=-1;
			r++;
			while(vis[r]==-1&&r<=n) r++;
		}
		else if(ans[l]<r){
			r++,l++;
			while(vis[l]==-1&&l<=n) l++;
			r=l+1;
			while(vis[r]==-1&&r<=n) r++;
		}
	}
	for(int i=1;i<=n;i++)
		if(vis[i]==0) cnt++;
	cout<<cnt;
	return 0;
}