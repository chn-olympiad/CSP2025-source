#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m,c[510],ans;
string s;
bool b[510];
void dfs(int j,int x,int num){
	if(num+(n-j)>m)return ;
	if(j==n){
		ans+=(num>=m);
		ans%=MOD;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			if(x>=c[i]||s[j]=='0'){
				dfs(j+1,x+1,num);
			}else{
				dfs(j+1,x,num+1);
			}
			b[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	int a=1,b=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)a=0;
	}
	for(int i=0;i<n;i++){
		if(s[i]=='0')a=0;
		b+=s[i]-'0';
	}
	if(b<m){
		cout<<0;
		return 0;
	}
	if(a){
		int ans=1;
		for(int i=2;i<=n;i++){
			ans*=i;
			ans%=MOD;
		}
		cout<<ans;
		return 0;
	}
	dfs(0,0,0);
	cout<<ans%MOD;;
	return 0;
}

