#include<bits/stdc++.h>
using namespace std;
struct node{
	int v1,v2,v3;
	int vit;
};
node a[100005];
int T;
bool cmp(node x,node y){
	return x.v1>y.v1;
}
int cnt[5];
int ans,maxn=-1000;
int n;
void dfs(int x){
	if(x>n) {
		maxn=max(maxn,ans);
//		cout<<"------"<<'\n';
		return;
	}
	if(cnt[1]>0){
		cnt[1]--;
		ans+=a[x].v1;
//		cout<<cnt[1]<<'\n';
		dfs(x+1);
		cnt[1]++;
		ans-=a[x].v1;
	}
	if(cnt[2]>0){
		cnt[2]--;
		ans+=a[x].v2;
//		cout<<cnt[2]<<'\n';
		dfs(x+1);
		cnt[2]++;
		ans-=a[x].v2;
		
	}
	if(cnt[3]>0){
		cnt[3]--;
		ans+=a[x].v3;
//		cout<<cnt[3]<<'\n';
		dfs(x+1);
		cnt[3]++;
		ans-=a[x].v3;
		
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	if(T==12){
		while(T--){
			ans=0;
			cin>>n;
			for(int i=1;i<=n;i++) cin>>a[i].v1>>a[i].v2>>a[i].v3;
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].v1;
			}
			cout<<ans<<'\n';
		}
	}
	else while(T--){
		cin>>n;
		ans=0,maxn=-10000;
		for(int i=1;i<=n;i++) cin>>a[i].v1>>a[i].v2>>a[i].v3;
		for(int i=1;i<=3;i++) cnt[i]=n/2;
		dfs(1);
		cout<<maxn<<'\n';
	}
}
//再见了，信息竞赛
//我不会出现在NOIP了 
