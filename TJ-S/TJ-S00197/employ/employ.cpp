#include<iostream>
using namespace std;
int m,n,a[100005],sum=0,vis[100005],cnt[100005];
string s;
void dfs(int x){
	if(x>n){
		int ans=0,p=0; 
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0')p++;
			else if(a[cnt[i]]<=p)p++;
			else ans++; 
		}
		if(ans>=m){
			sum++;
			//for(int i=1;i<=n;i++)cout<<cnt[i]<<" ";
			//cout<<endl;
			sum%=998244353;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1)continue;
		cnt[x]=i;
		vis[i]=1;
		dfs(x+1);
		vis[i]=0;
		cnt[x]=0;
	}
}
long long l(int x){
	long long ans=1;
	for(int i=1;i<=x;i++){
		ans*=i;
		ans%=998244353;
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin); 
	freopen("employ.out","w",stdout);  
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			if(a[i]==0||s[i-1]==0)cout<<"0";
			else cout<<l(n)<<endl;
		}
		return 0;
	}
	dfs(1);
	cout<<sum<<endl;
	return 0;
}
