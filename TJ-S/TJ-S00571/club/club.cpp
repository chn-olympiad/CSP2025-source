#include<bits/stdc++.h>
using namespace std;
int n,a1[100005],a2[100005],a3[100005],b[3];
bool cmp(int x,int y){
	return x>y;
}
int dfs(int x,int ans){
	if(x==n+1) return ans;
	int ans1=0,ans2=0,ans3=0;
	if(b[0]<(n/2)) b[0]++,ans1=dfs(x+1,ans+a1[x]),b[0]--;
	if(b[1]<(n/2)) b[1]++,ans2=dfs(x+1,ans+a2[x]),b[1]--;
	if(b[2]<(n/2)) b[2]++,ans3=dfs(x+1,ans+a3[x]),b[2]--;
	return max(ans1,max(ans2,ans3));
}
int mian(){
	cin>>n;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a1[i]>>a2[i]>>a3[i];
		if(a3[i]) f=0;
	}
	if(f){
		int m=0;
		sort(a1+1,a1+n+2,cmp);
		for(int i=1;i<=n/2;i++) m+=a1[i];
		cout<<m<<'\n';
	}else{
		cout<<dfs(1,0)<<'\n';
	}
	return 0;
}
int main(){ 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		mian();
	}
	return 0;
} 
