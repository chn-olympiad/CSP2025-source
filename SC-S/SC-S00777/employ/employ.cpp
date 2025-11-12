#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+5;
const int mod=998244353;
int n,m;
string s;
int c[N];
int a[N];
bool v[N];
int tmp=0;
void find(){
	int tot=0,ans=0;
	for(int i=1;i<=n;i++){
		if(c[a[i]]<=tot){
			tot++;
			continue;
		}
		if(s[i-1]=='0'){
			tot++;
			continue;
		}
		else{
			ans++;
		}
	}
	if(ans>=m){
		tmp=(tmp+1)%mod;
	}
}
void dfs(int x){
	if(x==n+1){
		find();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(v[i]) continue;
		v[i]=true;
		a[x]=i;
		dfs(x+1);
		a[x]=0;
		v[i]=false;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	bool k=true;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			k=false;
		}
	}
	if(n<=10){
		dfs(1);
		cout<<tmp; 
		return 0;
	}
	if(n==m){
		bool t=true;
		for(int i=0;i<s.size();i++){
			if(s[i]=='0'){
				t=false;
				break;
			}
		}
		if(k&&t){
			
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}