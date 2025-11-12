#include<bits/stdc++.h>
using namespace std;
int n,m,sum=0,num=0,p=1,k=0,l,kk=0;
long long ans=1;
string s;
int a[505],b[105],vis[505];
int check(){
	for(int i=1;i<=n;i++){
		if(b[i]>num&&s[i-1]=='1'){
			sum++;
		}
		else{
			num++;
		}
	}
	num=0;
	if(sum>=m){
		sum=0;
		return 1;
	}
	else{
		sum=0;
		return 0;
	}
}
void dfs(int x){
	if(x>n){
		if(check()==1){
			ans++;
			if(ans>=998244353) ans=0;
		}
		return;
	}
	else{
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				vis[i]=1;
				b[x]=a[i];
				dfs(x+1);
				vis[i]=0;
			}
		}
		return;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]=='0'){
			kk++;
			p=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			k++;
		}
	}
	if((n-max(k,kk))<m){
	    cout<<0;
		return 0;
	}
	if(p==1){
		for(int i=2;i<=n;i++){
			ans=(ans%998244353*i%998244353)%998244353;
		}
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans-1;
	return 0;
}