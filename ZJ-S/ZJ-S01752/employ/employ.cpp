#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[550],c[550],p[550],vis[550],ans,sum=1;
vector<int>vec;
void dfs(int step,int cnt){
	if(step==vec.size()+1){
		if(cnt>=m){
			ans=(ans+sum)%mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(vec[step-1]-1-cnt>=c[i]){
				dfs(step+1,cnt);
			}
			else{
				dfs(step+1,cnt+1);
			}
			vis[i]=0;
		}
	}
	return ;
}
bool check(){
	for(int i=1;i<=n;i++){
		if(s[i]!=1){
			return false;
		}
	}
	return true;
}
bool Check(){
	for(int i=1;i<=n;i++){
		if(c[i]==0){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		a[i]=ch-'0';
		if(a[i]==1){
			vec.push_back(i);
		}
	}
	if(vec.size()<m){
		cout<<0;
		return 0;
	}
	else if(vec.empty()){
		if(m!=0){
			cout<<0;
			return 0;
		}
		else{
			ans=1;
			for(int i=1;i<=n;i++){
				ans=(ans*i)%mod;
			}
			cout<<ans;
			return 0;
		}
	}
	for(int i=1;i<=n-vec.size();i++){
		sum=(sum*i)%mod;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m!=1){
		if(m==n){
			if(!check()){
				cout<<0;
				return 0;
			}
			else{
				if(!Check()){
					cout<<0;
					return 0;
				}
				else{
					int cnt=1;
					for(int i=1;i<=n;i++){
						cnt=(cnt*i)%mod;
					}
					cout<<cnt;
					return 0;
				}
			}
		}
		else{
			dfs(1,0);
			cout<<ans;
		}
	}
	else{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(c[i]>=vec[0]){
				cnt=(cnt+1)%mod;
			}
		}
		for(int i=1;i<n;i++){
			cnt=(cnt*i)%mod;
		}
		cout<<cnt;
	}
	return 0;
}
