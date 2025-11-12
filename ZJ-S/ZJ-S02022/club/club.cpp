#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][3];
int t;
int n;
int sum;
int cnt[3];
void dfs(int s,int ans){
	if(s==n+1){
		sum=max(sum,ans);
		return;
	}
	for(int i=0;i<3;i++){
		if(cnt[i]<n/2){
			cnt[i]+=1;
			dfs(s+1,ans+a[s][i]);
			cnt[i]-=1;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n;
		sum=0;
		cnt[0]=cnt[1]=cnt[2]=0;
		for(int i=1;i<=n;i++)
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		dfs(1,0);
		cout<<sum<<endl;	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//AFO
