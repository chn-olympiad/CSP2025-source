#include<bits/stdc++.h>
using namespace std;
int T,n,a[100010][4],ans;
void dfs(int now,int sum,int num1,int num2,int num3){
	if(num1==-1||num2==-1||num3==-1) return;
	if(now==n+1){
		ans=max(ans,sum);
		//cout<<sum<<" ";
		return;
	}
	dfs(now+1,sum+a[now][1],num1-1,num2,num3);
	dfs(now+1,sum+a[now][2],num1,num2-1,num3);
	dfs(now+1,sum+a[now][3],num1,num2,num3-1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		int num1=n/2,num2=n/2,num3=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1,0,num1,num2,num3);
		cout<<ans<<"\n";
	} 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 