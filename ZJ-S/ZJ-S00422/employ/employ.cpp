#include<bits/stdc++.h>
using namespace std;
int n,m,nx[505];
string s;
int lost,p[505];
long long ans;
void dfs(int step){
	if(step==n+1){
		lost=0;
		for(int i=0;i<n;i++){
			if(s[i]=='0'||lost>=nx[p[i]])lost++;
		}
		//cout<<lost;
		if(n-lost>=m)ans++;
		//for(int i=0;i<n;i++)cout<<p[i];
		//cout<<"\n";
		ans%=998244353;
		return ;
	}
	for(int i=0;i<n;i++){
		if(p[i]!=0)continue;
		p[i]=step;
		dfs(step+1);
		p[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>nx[i];
	if(n>18){
		cout<<0;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}