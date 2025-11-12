#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100005][5];
struct node{
	int val,id,idv;
};
bool cmp(node x,node y){
	return x.val>y.val;
}
int vis[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		for(int i=1;i<=100000;i++)vis[i]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		vector<node>ve;
		for(int i=1;i<=n;i++){
			int xx,yy,zz;
			xx=a[i][1];
			yy=a[i][2];
			zz=a[i][3];
			ve.push_back({xx,i,1});
			ve.push_back({yy,i,2});
			ve.push_back({zz,i,3});
		}
		int cnt[4]={0};
		int ans=0;
		sort(ve.begin(),ve.end(),cmp);
//		for(node t:ve){
//			cout<<t.id<<" "<<t.idv<<" "<<t.val<<endl;
//		}
		for(node t:ve){
			int bumen=t.idv;
			if(vis[t.id]==1)continue;
			if(cnt[bumen]+1<=n/2){
				cnt[bumen]++;
				ans+=t.val;
				vis[t.id]=1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}