#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
int a[100005][4],b[4];
void dfs(int t,int ans1){
	if(t>n){
		if(ans1>ans)ans=ans1; 
		return;
	}
	for(int i=1;i<=3;i++){
		b[i]+=1;
		if(b[i]<=n/2){
			
			int c=ans1;
			
			c+=a[t][i];
			dfs(t+1,c);
		}
		b[i]-=1;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		cin>>n;ans=0;
		for(int j=1;j<=n;j++){
			
			for(int z=1;z<=3;z++){
				cin>>a[j][z];	
			}	
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
