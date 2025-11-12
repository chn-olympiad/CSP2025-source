#include<bits/stdc++.h>
using namespace std;
int n=0;
int a1[150000];
int a2[150000];
int a3[150000];
int vis[150000];
int par[5];//各部门人数 
int ans=-1;
int ans1=0;
int x,y,z;
void dfs(int num){
	if(num>n){
		if(ans1>ans){
			ans=ans1;
//			cout<<"#####"<<endl;
//			for(int i=1;i<=n;i++){
//				cout<<vis[i]<<"  ";
//			}
//			cout<<"####"<<endl;
		}
		return;
	}
	for(int i=1;i<=3;i++){
		if(vis[num]!=0){
			continue;
		}
		if(i==1&&par[1]<(n/2)){
			ans1+=a1[num];
			par[1]++;
			vis[num]=1;
			dfs(num+1);
			vis[num]=0;
			ans1-=a1[num];
			par[1]--;
		}
		else if(i==2&&par[2]<(n/2)){
			ans1+=a2[num];
			par[2]++;
			vis[num]=2;
			dfs(num+1);
			vis[num]=0;
			par[2]--;
			ans1-=a2[num];
		}
		else if(i==3&&par[3]<(n/2)){
			ans1+=a3[num];
			par[3]++;
			vis[num]=3;
			dfs(num+1);
			vis[num]=0;
			par[3]--;
			ans1-=a3[num];
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0;
	cin>>t;
	while(t--){
		cin>>n;
		ans=-1;
		ans1=0;
		for(int i=0;i<=n+1;i++){
			a1[i]=0;
			a2[i]=0;
			a3[i]=0;
			vis[i]=0;
		}
		for(int i=0;i<=5;i++){
			par[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a1[i];
			cin>>a2[i];
			cin>>a3[i];
		}
		dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
}
