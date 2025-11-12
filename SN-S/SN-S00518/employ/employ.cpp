//SN-S00518 王者淳 西安辅轮中学
#include<bits/stdc++.h>
using namespace std;
int n,m,c[500];
const int mod=998244353;
long long ans;
string s;
void dfs(int now,int num,vector<int>v){
	if(num+n-now+1<m)return;
	if(now==n+1){
		if(num>=m)ans++,ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		bool b=1;
		for(int j=0;j<v.size();j++){
			if(v[j]==i)b=0;
		}
		if(b){
			vector<int>vv=v;
			vv.push_back(i);
			if(c[i]>now-num-1&&s[now-1]=='1')dfs(now+1,num+1,vv);
			else dfs(now+1,num,vv);
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	vector<int>v;
	if(n<=18)dfs(1,0,v);
	else {
		ans=1;
		for(int i=1;i<=n;i++){ans*=i;ans%=mod;}
	}
	cout<<ans;
	return 0;
}
