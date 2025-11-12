#include<bits/stdc++.h>
using namespace std;

long long n,m,ans=0;
string hard;
int cc[510];
int visit[510]={};

void dfs(int k,int sum){
	if(sum>=m){
		ans++;
		return;
	}
	if(k>n) return;
	
	for(int i=1;i<=n;i++){
		if(visit[i]==0){
			visit[i]=1;
			if(k<cc[i])	dfs(k+1,sum+1);
			else dfs(k+1,sum);
			visit[i]=0;
		}
	}
	return;
}

int main(){
	//freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
	
	cin>>n>>m;
	cin>>hard;
	for(int i=1;i<=n;i++){
		cin>>cc[i];
	}
	
	int flag=1;
	for(int i=0;i<hard.length();i++){
		if(hard[i]=='0'){
			flag=0;
		}
	}
	
	if(flag){
		sort(cc+1,cc+n+1);
		dfs(0,0);
		cout<<ans%998244353<<endl;
		return 0;
	}
	
	
	return 0;
}

