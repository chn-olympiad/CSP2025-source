#include<bits/stdc++.h>
using namespace std;
long long n,m,c[505],used[505],me[505][505];
string s;
long long dfs(int d,int g){
	if(d==n&&g>=m)return 1;
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(!used[i]){
			used[i]=1;
			if(s[d]=='1' && d-g<c[i])ans=(ans+dfs(d+1,g+1))%998244353;
			else ans=(ans+dfs(d+1,g))%998244353;
			used[i]=0;
		}
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	cout<<dfs(0,0);
	return 0; 
}