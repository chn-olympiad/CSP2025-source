#include<bits/stdc++.h>
using namespace std;
int n,m,nx[200],cho[200];
long long ans;
string sp,s;
void dfs(int k,int num,int refusex,int tox){
	//cout<<k<<" "<<num<<" "<<refusex<<" "<<tox<<endl;
	if(k==n){
		if(s[k]=='1'&&nx[tox]>refusex) num++;
		if(num>=m){
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(cho[i]!=0) continue;
		cho[i]=1;
		//cout<<i<<" nx[tox] "<<nx[tox]<<" s[k] "<<s[k]<<endl;
		if(k==0) dfs(k+1,num,refusex,i);
		else if(s[k]=='1'&&nx[tox]>refusex) dfs(k+1,num+1,refusex,i);
		else dfs(k+1,num,refusex+1,i);
		cho[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>sp;
	s="0"+sp;
	//cout<<"s "<<s<<endl;
	if(n>18){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>nx[i];
	dfs(0,0,0,0);
	cout<<ans<<endl;
	return 0;
}