#include <bits/stdc++.h>
using namespace std;
vector<long long> x;
int vis[100005]={};
long long n,k,ans=0;
int s(int st,int ed){
	int num=x[st];
	for (int i=st+1;i<=ed;i++){
		num^=x[i];
	}
	return num;
}
void dfs(int step,int viscnt){
	if (step==n){
		return;
	}else{
		int index=step;
		for (int i=1;i<=n-step;i++){
			if (vis[viscnt]==0){
				if (s(index,index+i)==k){
					ans++;
				}
				vis[viscnt]=i;
				dfs(step+i,viscnt+1);
				vis[viscnt]=0;
			}
		}
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	x.resize(n+1);
	x[0]=0;
	for (int i=1;i<=n;i++){
		cin>>x[i];
	}
	dfs(1,1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
