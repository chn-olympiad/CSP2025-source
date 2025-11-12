#include<bits/stdc++.h>
using namespace std;
int n,m;
char c[1001];
int d[1001];
int f[1001];
int r[1001];
int ans;
int dd;
void dfs(int s,int x){
	if(x>n-m)return ;
	dd=0;
	for(int i=0;i<n;i++){
		if(r[i]<=x&&f[i]==0){
			f[i]=1;
			dd++;
		}
	}
	if(s+dd>=n&&n-x>=m){
		ans=(ans+1)%998244353;
//		cout<<" ha\n";
		return ;
	}
	for(int i=0;i<n;i++){
//		cout<<"aaaa"<<s<<"aaaa"<<" ";
		if(f[i]==0&&d[s]==1){
			f[i]=1;
	//		cout<<i<<"a\n";
			dfs(s+1,x+1);
			f[i]=0;
		}
		else if(f[i]==0&&d[s]==0){
			f[i]=1;
	//		cout<<i<<"b\n";
			dfs(s+1,x);
			f[i]=0;
		}
	//	else cout<<i<<"c\n";
	}
}
int main(){
	cin>>n>>m;
	cin>>c;
	for(int i=0;i<n;i++){
		if(c[i]=='0'){
			d[i]=1;
		}else{
			d[i]=0;
		}
	}
	for(int i=0;i<n;i++){
		cin>>r[i];
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}