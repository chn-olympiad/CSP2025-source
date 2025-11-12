#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[505],b[505],ans,p,num;
string s;
bool vis[505];
void dfs(int k){
	if(p>n-m)return ;
	if(k>n){
		num++;
		num%=mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			bool flag=false;
			vis[i]=true;
			b[k]=i;
			if(s[k-1]=='0')p++,flag=true;
			else if(a[i]<=p)p++,flag=true;
			dfs(k+1);
			vis[i]=false;
			if(flag)p--;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	dfs(1);
	cout<<num;
	return 0;
}
