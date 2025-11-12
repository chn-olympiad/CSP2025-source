#include<bits/stdc++.h>
using namespace std;

int t,n;
int a[100005][5];
int b[100005];
long long ans;

bool a2(){
	for(int i=1;i<=n;i++){
		if(a[i][2]!=0){
			return false;
		}
	}
	return true;
}

bool a3(){
	for(int i=1;i<=n;i++){
		if(a[i][3]!=0){
			return false;
		}
	}
	return true;
}

void dfs(int x,int y,int z,long long tot,int k){
	if(k==n+1){
		ans=max(ans,tot);
		return;
	}
	if(!(x==n/2)){
		dfs(x+1,y,z,tot+a[k][1],k+1);
	}
	if(!(y==n/2)){
		dfs(x,y+1,z,tot+a[k][2],k+1);
	}
	if(!(z==n/2)){
		dfs(x,y,z+1,tot+a[k][3],k+1);
	}
}

void dfs2(int x,int y,long long tot,int k){
	if(k==n+1){
		ans=max(ans,tot);
		return;
	}
	if(!(x==n/2)){
		dfs2(x+1,y,tot+a[k][1],k+1);
	}
	if(!(y==n/2)){
		dfs2(x,y+1,tot+a[k][2],k+1);
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}	
		if(a3()&&a2()){
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+n+1);
			for(int i=n;i>=n/2+1;i--){
				ans+=b[i];
			}
		}
		else if(a3()){
			dfs2(0,0,0,1);
		}
		else{
			dfs(0,0,0,0,1);
		}
		cout<<ans;
		if(t!=1){
			cout<<endl;
		}
	}
	return 0;
}