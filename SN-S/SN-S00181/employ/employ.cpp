#include<bits/stdc++.h>
using namespace std;

long long mod = 998244353;
int n,m;
string s;
int c[505];
long long cnt = 0;
void dfs(int step,int n,long long ans){
	if(step==n){
		if(ans>=m)cnt++;
		cnt%=mod;
		return ;
	}
	for(int i = 1;i<=n;i++){
		if(s[step]=='0'){
			dfs(step+1,n,ans+1);
		}
		else dfs(step+1,n,ans+1);
	}

	

	
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	cin>>n>>m;
	if(m==n){
		long long sdsd = 1;
		int j = n;
		for(int i = 1;i<=n;i++){
			sdsd*=j;
			j--;
		}
		cout<<sdsd;
		return 0;
	}
	cin>>s;

	for(int i =  1;i<=n;i++){
		cin>>c[i];
	}
	dfs(0,n,0);
	cout<<cnt;
	return 0;
}
		
