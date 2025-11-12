#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[510],ans;
string s;
bool v[510];
void dfs(int d,int r,int t){
	if(d==n&&r>=m)ans=(ans+1)%mod;
	for(int i=1;i<=n;i++){
		bool f=0;
		if(v[i]==1)continue;
		v[i]=1;
		d++;
		if(s[d]=='1'&&t<c[i]){r++;f=1;}
		else t++;
		dfs(d,r,t);
		d--;
		if(f==1)r--;
		else t--;
		v[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(0,0,0);
	cout<<ans%mod;
	return 0;
}