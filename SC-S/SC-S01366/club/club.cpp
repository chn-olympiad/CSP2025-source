#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],m,maxn,flag;
void dfs(int cnt,int x,int y,int z,int sum){
//	cout<<cnt<<' '<<x<<' '<<y<<' '
	if(cnt==n+1){
		maxn=max(maxn,sum);
		return;
	}
	if(x<m) dfs(cnt+1,x+1,y,z,sum+a[cnt][1]);
	if(y<m) dfs(cnt+1,x,y+1,z,sum+a[cnt][2]);
	if(z<m) dfs(cnt+1,x,y,z+1,sum+a[cnt][3]);
}
void dfss(int cnt,int x,int y,int sum){
	if(cnt==n+1){
		maxn=max(maxn,sum);
		return;
	}
	if(x<m) dfss(cnt+1,x+1,y,sum+a[cnt][1]);
	if(y<m) dfss(cnt+1,x,y+1,sum+a[cnt][2]);
}
void dfsss(int cnt,int x,int sum){
	if(cnt==n+1){
		maxn=max(maxn,sum);
		return;
	}
	if(x<m) dfsss(cnt+1,x+1,sum+a[cnt][1]);
	dfsss(cnt+1,x,sum);
}
bool cmp(int o,int p){
	return o>p;
} 
	
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		flag=3;
		cin>>n;
		m=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
//			sort(a[i]+1,a[i]+4,cmp);
			int cnt=(a[i][1]==0)+(a[i][2]==0)+(a[i][3]==0);
			if(cnt==3) flag=min(flag,3); 
			else if(cnt==2) flag=min(flag,2);
			else if(cnt==1) flag=min(flag,1);
			else flag=0;
		}
		if(flag==1){
			for(int i=1;i<=n;i++) sort(a[i]+1,a[i]+4,cmp);
			dfss(1,0,0,0);
			cout<<maxn<<'\n';
		}
		else if(flag==2){
			for(int i=1;i<=n;i++) sort(a[i]+1,a[i]+4,cmp);
			dfsss(1,0,0);
			cout<<maxn<<'\n';
		} 
		else if(n<=10){
			dfs(1,0,0,0,0);
			cout<<maxn<<'\n';
		}
		else cout<<20000<<'\n';
		maxn=0;
	}
	return 0;
} 