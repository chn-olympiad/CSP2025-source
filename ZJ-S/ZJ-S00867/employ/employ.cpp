#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],s[510],v[510];
long long x;
string s1;
bool check(){
	int num=0,go=0,wh[510];
	for(int i=1;i<=n;i++){
		wh[v[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(s[i]==0){
			go++;
		}else if(c[wh[i]]<=go){
			go++;
		}else{
			num++;
		}
	}
	if(num>=m){
		return true;
	}else{
		return false;
	}
}
void dfs(int now){
	if(now==n+1){
		if(check()){
			x++;
			x%=998244353;
		}
	}else{
		for(int i=1;i<=n;i++){
			if(v[i]==0){
				v[i]=now;
				dfs(now+1);
				v[i]=0;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s1;
	for(int i=1;i<=n;i++){
		s[i]=s1[i-1]-'0';
		cin>>c[i];
	}
	if(m==1){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i%998244353);
		}
		cout<<ans;
	}else{
		dfs(1);
		cout<<x;
	}
	return 0;
	fclose(stdout);
	fclose(stdin);
}
