#include <bits/stdc++.h>
using namespace std;

long long n,m;
string s;
long long a[1010];
long long vis[1001];
long long cnt=0;
long long ans=0;
const long long mod=998244353;

long long dfs(long long dt,long long mc,long long mw){
	if(dt==n-1&&mw>=m) return 1; 
	long long ans=0;
	for(long long i=1;i<=n;i++){
		if(a[i]>mc&&vis[i]==0){
			vis[i]=1;
			ans+=dfs(dt+1,mc,mw+1);
			vis[i]=0;
		}
		else{
			vis[i]=1;
			ans+=dfs(dt+1,mc+1,mw);
			vis[i]=0;
		}
	}
	return ans;
		
//	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>s;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	bool q=1;
	for(long long i=0;i<s.size();i++){
		if(s[i]=='0'){
			q=0;
		}
	}
	cout<<dfs(0,0,0);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}