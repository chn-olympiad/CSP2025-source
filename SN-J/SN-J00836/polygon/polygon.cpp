#include<bits/stdc++.h>
using namespace std;
int n,arr[5007],ans=0;
const int Mod=998244353;
set<string>now;
void dfs(int nowid,int sum,int maxn,string chs){
	if(sum>maxn*2 && now.find(chs)==now.end()){
		ans=(ans+1)%Mod;
		now.insert(chs);
	}
	for(int i=nowid;i<=n;i++){
		if(sum>maxn*2)dfs(i+1,sum,maxn,chs);
		dfs(i+1,sum+arr[i],max(maxn,arr[i]),chs+to_string(i));
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	string null="";
	cin>>n;
	for(int i=1;i<=n;i++)cin>>arr[i];
	dfs(1,0,1,null);
	cout<<ans;
	return 0;
}
