#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=0;
int num[20000];
void dfs(int h,int sum,int last_num,int ge){
	if(h==n+1){
		if(sum>num[last_num]*2 && ge>=3)ans+=1; ans%=998244353;
		return ;
	}
	dfs(h+1,sum+num[h],h,ge+1);
	dfs(h+1,sum,last_num,ge);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	std::sort(num+1,num+1+n);
	dfs(1,0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
