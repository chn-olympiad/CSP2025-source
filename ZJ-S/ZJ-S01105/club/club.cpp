#include<bits/stdc++.h>
using namespace std;
int xxx,mx,n,sm;
int a[100005][4];
int vis[4];
void dfs(int d,int sum){
	for(int i=1;i<=3;i++){
		vis[i]+=1;
		sm=sum+a[d][i];
		if(d==n&&sm>mx&&vis[1]<=n/2&&vis[2]<=n/2&&vis[3]<=n/2) mx=sm;
		else if(vis[1]<=n/2&&vis[2]<=n/2&&vis[3]<=n/2) dfs(d+1,sm);
		vis[i]-=1;	
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>xxx;
	for(int i=1;i<=xxx;i++){
		cin>>n;
		bool s=false;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0){
				s=true;
			}
		}
		if(s==true){
			dfs(1,0);
		}else{
			int b[100005];
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+n+1);
			for(int i=n;i>=(n/2)+1;i--){
				mx=mx+b[i];
			}
		}
		cout<<mx<<endl;	
		mx=0;
		for(int i=1;i<=3;i++){
			vis[i]=0;
		}
		for(int i=1;i<=n;i++){
			a[i][1]=0;
			a[i][2]=0;
			a[i][3]=0;
		}
		
	}
	return 0;
}
