#include<bits/stdc++.h>
#define N 100005
using namespace std;
int t,n,res,b[N][3],vis[3],ans;
struct Node{
	int num,idx,mexn;
}v[N];
void dfs(int x,int sum){
	if(x>n){
		ans=max(ans,sum);
		return;
	}
	if(vis[2]<n/2){
		vis[2]++;
		dfs(x+1,sum+b[x][2]);
		vis[2]--;
	}
	if(vis[1]<n/2){
		vis[1]++;
		dfs(x+1,sum+b[x][1]);
		vis[1]--;
	}
	if(vis[0]<n/2){
		vis[0]++;
		dfs(x+1,sum+b[x][0]);
		vis[0]--;
	}
}
bool cmp1(Node a,Node b){
	return a.num>b.num;
}
bool cmp2(Node a,Node b){
	return a.num>b.num||a.num==b.num&&a.mexn<b.mexn;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>b[i][0]>>b[i][1]>>b[i][2],vis[i]=0;
		//sort(b+1,b+1+n,cmp)
		ans=0;
		if(n<=10){
			
			dfs(1,0);
			cout<<ans<<"\n";
		}
		else{
			int flag=1;
			for(int i=1;i<=n;i++){
				if(b[i][1])flag=2;
				if(b[i][2])flag=3;
			}
			if(flag==1||flag==2){
				for(int i=1;i<=n;i++){
					v[i].idx=i;
					v[i].num=max(b[i][0],b[i][1]);
					v[i].mexn=min(b[i][0],b[i][1]);
				}
				if(flag==1){
					sort(v+1,v+1+n,cmp1);
					for(int i=1;i<=n/2;i++)ans+=v[i].num;
					cout<<ans<<"\n";
				}
				if(flag==2){
					sort(v+1,v+1+n,cmp2);
					for(int i=1;i<=n;i++){
						if(b[v[i].idx][0]==v[i].num){
							if(vis[0]<n/2)vis[0]++,ans+=v[i].num;
							else vis[1]++,ans+=v[i].mexn;
						}else{
							if(vis[1]<n/2)vis[1]++,ans+=v[i].num;
							else vis[0]++,ans+=v[i].mexn;
						}
					}
					cout<<ans<<"\n";
				}
			}
		}
	}
	
	return 0;
}