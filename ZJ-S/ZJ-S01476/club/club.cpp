#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t,n,lmt,ans,cnt[4],mem[100010][4];
void dfs(int dep,int sum);
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int l=1;l<=t;l++){
		cin>>n;lmt=n/2;
		for(int i=1;i<=n;i++){
			cin>>mem[i][1]>>mem[i][2]>>mem[i][3];
		}
		dfs(1,0);
		cout<<ans<<endl;
		ans=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
void dfs(int dep,int sum){
	if(dep==n+1){
		if(ans<sum) ans=sum;
		return;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]+1<=lmt){
			cnt[i]++;
			dfs(dep+1,sum+mem[dep][i]);
			cnt[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}