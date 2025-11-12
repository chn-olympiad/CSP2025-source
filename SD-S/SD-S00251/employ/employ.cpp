#include<bits/stdc++.h>
using namespace std;
const int N=510,M=998244353;
int n,m;
int s=0;
string a;
int ma=0;
int pre[N];
bool f[N];
int cover[N];
int t[N];
bool check(){
	int c=0;
	for(int i=1;i<=n;i++){
		if(pre[i]<t[cover[i]]&&a[i]-'0'){
			c++;
		}
	}
	return c>=m;
}
void dfs(int k){
	if(k>n){
		if(check()){
			s++;
			s%=M;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			cover[k]=i;
			dfs(k+1);
			f[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>a;
	a=" "+a;
	for(int i=1;i<=n;i++){
		cin>>t[i];
		ma+=a[i]-'0';
	}
	
	if(!ma){
		cout<<0;
		return 0;
	}
	if(ma==n){
		int s=1;
		for(int i=1;i<=n;i++){
			s*=i;
			s%=M;
		}
		cout<<s%M;
		return 0;
	}
	if(m==1){
		int s=1;
		for(int i=1;i<=n;i++){
			s*=i;
			s%=M;
		}
		cout<<s%M;
		return 0;
	}
	for(int i=0;i<n;i++){
		pre[i+1]=pre[i]+(a[i]=='0');
	}
	dfs(1);
	cout<<s%M;
	return 0;
}
